/*
 * This file is part of fourc-qpid-manager.
 *
 * fourc-qpid-manager is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * fourc-qpid-manager is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with fourc-qpid-manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FOURC_QPID_MANAGER_ROUTEMANAGER_H
#define FOURC_QPID_MANAGER_ROUTEMANAGER_H

namespace fourc {
namespace fmf {

/**
 * \brief Offers essentially the same interface to route management as is provided by the "qpid-route" CLI tool
 */
template <typename BrokerAgentT>
class RouteManager {
public:
  RouteManager(BrokerAgentT& brokerAgent) : brokerAgent(brokerAgent) {
  };

  virtual ~RouteManager() = default;

  /**
   * \brief Gets the link from the local broker to a remote broker
   * \note Could return a link on any transport but this should be OK in practice
   * @return
   */
  const std::shared_ptr<Link> getLink(const std::string& host, const int port, const std::string& transport) const {
    for (auto link : brokerAgent.getLinks()) {
      if (link->getHost() == host && link->getPort() == port && link->getTransport() == transport) {
        return link;
      }
    }

    return std::shared_ptr<Link>();
  };

  const std::shared_ptr<Link> ensureLinked(const std::shared_ptr<Broker>& broker,
                         const std::string& host, const int port, const bool durable, const std::string& interbroker_mechanism,
                         const std::string& transport, const std::string& user, const std::string& pwd) const {
    auto link = getLink(host, port, transport);
    if (!link) {
      broker->connect(brokerAgent, host, port, durable, interbroker_mechanism, transport, user, pwd);
      link = getLink(host, port, transport);
    }
    if (!link) {
      throw BrokerAgentException("Unable to establish link to host " + host + ":" + std::to_string(port));
    }

    return link;
  }

  void addBridge(const std::shared_ptr<Broker>& broker, const std::shared_ptr<Link>& link,
                 const std::string& src, const std::string& dest, const std::string& key, const std::string& tag,
                 const std::string excludes, const bool src_local, const bool src_queue, const bool durable,
                 const bool dynamic, const uint16_t sync, const uint32_t credit) const {

    // Check the bridge doesn't already exist
    auto bridges = brokerAgent.getBridges();
    for (auto bridge : bridges) {
      if (bridge->getLinkRef() == link->getObjectId().getName()
          && bridge->getSrc() == src
          && bridge->getDest() == dest
          && bridge->getKey() == key
          && bridge->isSrcLocal() == src_local) {
        throw BrokerAgentException("Duplicate route");
      }
    }

    std::string name = boost::str(boost::format("%s:%s:%s:%s:%s") % dest % (key.empty() ? src : key) % link->getObjectId()
                                                               % src_queue % src_local);

    typename BrokerAgentT::VariantType::Map properties;
    properties.emplace("link", link->getName()); // NB: Not the same as link->getObjectId().getName() used above
    properties.emplace("src", src);
    properties.emplace("dest", dest);
    properties.emplace("key", key);
    properties.emplace("tag", tag);
    properties.emplace("excludes", excludes);
    properties.emplace("srcIsLocal", src_local);
    properties.emplace("srcIsQueue", src_queue);
    properties.emplace("durable", durable);
    properties.emplace("dynamic", dynamic);
    properties.emplace("sync", sync);
    properties.emplace("credit", credit);

    broker->create(brokerAgent, Bridge::OBJECT_TYPE_NAME, name, properties, false);
  }

  /**
   * \brief Adds a route to/from an exchange on a remote broker
   * @param remote
   * @param interbroker_mechanism
   * @return the new link
   */
  void addRoute(const std::string& host, const int port, const std::string& interbroker_mechanism,
                const std::string& transport, const std::string& user, const std::string& pwd,
                const std::string& src, const std::string& dest, const std::string& routingKey, const std::string& tag,
                const std::string excludes, const bool dynamic, const bool src_local, const bool durable,
                const uint16_t sync, const uint32_t credit = 0xFFFFFFFF) const {
    auto broker = brokerAgent.getBroker();
    auto link = ensureLinked(broker, host, port, durable, interbroker_mechanism, transport, user, pwd);

    addBridge(broker, link, src, dest, routingKey, tag, excludes, src_local, false, durable, dynamic, sync, credit);
  };

  /**
   * \brief Adds a route to/from a queue on a remote broker
   * @param remote
   * @param interbroker_mechanism
   * @return the new link
   */
  void addQueueRoute(const std::string& host, const int port, const std::string& interbroker_mechanism,
                     const std::string& transport, const std::string& user, const std::string& pwd,
                     const std::string& queue, const std::string& exchange,
                     const bool src_local, const bool durable,
                     const uint16_t sync, const uint32_t credit = 0xFFFFFFFF) const {
    auto broker = brokerAgent.getBroker();
    auto link = ensureLinked(broker, host, port, durable, interbroker_mechanism, transport, user, pwd);

    addBridge(broker, link, queue, exchange, "", "", "", src_local, true, durable, false, sync, credit);
  };

  /**
   * \brief Deletes an exchange route to a remote broker
   * @param remote
   */
  void delRoute(const std::string& host, const int port, const std::string& transport,
                const std::string& src, const std::string& dest, const std::string& key, bool srcLocal,
                bool dynamic, bool delLink) const {
    auto link = getLink(host, port, transport);
    if (!link) {
      throw BrokerAgentException("Unable to find link to host " + host + ":" + std::to_string(port));
    }

    auto bridges = brokerAgent.getBridges();
    for (auto bridge : bridges) {
      if (bridge->getLinkRef() == static_cast<std::string>(link->getObjectId())
          && bridge->getSrc() == src
          && bridge->getDest() == dest
          && bridge->getKey() == key
          && bridge->isDynamic() == dynamic
          && !bridge->isSrcQueue()
          && bridge->isSrcLocal() == srcLocal) {
        bridge->closeOn(brokerAgent);
        if (bridges.size() == 1 && delLink) {
          link->closeOn(brokerAgent);
        }
        return;
      }
    }

    std::string arrow = srcLocal ? "=>" : "<=";
    throw BrokerAgentException(boost::str(boost::format("Route not found: %s %s %s:%d (%s(%s))")
                                          % src % arrow % host % port % dest % key));
  };

  /**
   * \brief Deletes a queue route to a remote broker
   * @param remote
   */
  void delQueueRoute(const std::string& host, const int port, const std::string& transport,
                     const std::string& queue, const std::string& exchange,
                     bool srcLocal, bool delLink) const {
    auto link = getLink(host, port, transport);
    if (!link) {
      throw BrokerAgentException("Unable to find link to host " + host + ":" + std::to_string(port));
    }

    auto bridges = brokerAgent.getBridges();
    for (auto bridge : bridges) {
      if (bridge->getLinkRef() == static_cast<std::string>(link->getObjectId())
          && bridge->getDest() == exchange
          && bridge->getSrc() == queue
          && bridge->isSrcQueue()
          && bridge->isSrcLocal() == srcLocal) {
        bridge->closeOn(brokerAgent);
        if (bridges.size() == 1 && delLink) {
          link->closeOn(brokerAgent);
        }
        return;
      }
    }

    std::string arrow = srcLocal ? "=>" : "<=";
    throw BrokerAgentException(boost::str(boost::format("Route not found: %s %s %s:%d (%s)")
                                          % queue % arrow % host % port % exchange));
  };

protected:
  BrokerAgentT& brokerAgent;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_ROUTEMANAGER_H
