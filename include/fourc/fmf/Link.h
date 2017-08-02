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

#ifndef FOURC_FMF_LINK_H
#define FOURC_FMF_LINK_H

#include "BrokerObject.h"
#include "MethodResult.h"

#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

#include <map>

namespace fourc {
namespace fmf {

template<typename AddressT, typename SessionT, typename ReceiverT, typename MessageT, typename DurationT, typename VariantT>
class BrokerAgentTemplate;

class Link : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Link();

  uint64_t getConnectionEpoch() const;
  Link& setConnectionEpoch(uint64_t);

  const std::string& getConnectionName() const;
  Link& setConnectionName(const std::string&);

  bool isDurable() const;
  Link& setDurable(bool);

  const std::string& getHost() const;
  Link& setHost(const std::string&);

  uint16_t getPort() const;
  Link& setPort(uint16_t);

  const std::string& getLastError() const;
  Link& setLastError(const std::string&);

  const std::string& getName() const;
  Link& setName(const std::string&);

  const std::string& getState() const;
  Link& setState(const std::string&);

  const std::string& getTransport() const;
  Link& setTransport(const std::string&);

  const std::string& getVhostRef() const;
  Link& setVhostRef(const std::string&);

  /**
   * \brief Bridges messages over the link
   * @tparam BrokerAgentT
   * @param brokerAgent
   * @param src
   * @param dest
   * @param key
   * @param tag
   * @param excludes
   * @param src_queue
   * @param src_local
   * @param durable
   * @param dynamic
   * @param sync
   * @param credit default="0xFFFFFFFF", granted to peer, 0 = infinite
   */
  template <typename BrokerAgentT>
  std::shared_ptr<MethodResult> bridge(BrokerAgentT& brokerAgent,
              const std::string& src, const std::string& dest, const std::string& key,  const std::string& tag,
              const std::string& excludes, const bool src_queue, const bool src_local, const bool durable,
              const bool dynamic, const uint16_t sync, const uint32_t credit = 0xFFFFFFFF) {
    std::string method_name = "bridge";
    typename BrokerAgentT::VariantType::Map args;
    args.emplace("src", src);
    args.emplace("dest", dest);
    args.emplace("key", key);
    args.emplace("tag", tag);
    args.emplace("excludes", excludes);
    args.emplace("srcIsQueue", boost::lexical_cast<std::string>(src_queue));
    args.emplace("srcIsLocal", boost::lexical_cast<std::string>(src_local));
    args.emplace("dynamic", boost::lexical_cast<std::string>(dynamic));
    args.emplace("durable", boost::lexical_cast<std::string>(durable));
    args.emplace("sync", boost::lexical_cast<std::string>(sync));
    args.emplace("credit", boost::lexical_cast<std::string>(credit));

    const auto& address = getObjectId().getName();

    return brokerAgent.template method<MethodResult, typename BrokerAgentT::VariantType::Map>(method_name, args, address);
  }

  template <typename BrokerAgentT>
  std::shared_ptr<MethodResult> closeOn(BrokerAgentT& brokerAgent) const {
    std::string method_name = "close";
    typename BrokerAgentT::VariantType::Map args;

    const auto& address = getObjectId().getName();

    return brokerAgent.template method<MethodResult, typename BrokerAgentT::VariantType::Map>(method_name, args, address);
  }

private:
  uint64_t connectionEpoch;
  std::string connectionName;
  bool durable;
  std::string host;
  uint16_t port;
  std::string lastError;
  std::string name;
  std::string state;
  std::string transport;
  std::string vhostRef;
};

}} // Namespaces

#endif //FOURC_FMF_LINK_H
