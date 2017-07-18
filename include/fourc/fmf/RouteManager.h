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
 * \brief Offers essentially the same interface to route management as is provided by the CLI tool "qpid-route"
 */
class RouteManager {
public:
  RouteManager() = default;
  virtual ~RouteManager() = default;

  /**
   * \brief Gets this instance's link to the broker
   * @return
   */
  const std::shared_ptr<Link> getLink() const;

  /**
   * \brief Verifies that a link is connected (3 retries, tested with 1 second intervals)
   */
  void checkLink(const std::shared_ptr<Link>&) const;

  /**
   * \brief Adds a link to a remote broker
   * @param remote
   * @param interbroker_mechanism
   * @return the new link
   */
  std::shared_ptr<Link> addLink(const Broker& remote, std::string& interbroker_mechanism) const;

  /**
   * \brief Deletes a link to a remote broker
   * @param remote
   */
  void delLink(const Broker& remote) const;


};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_ROUTEMANAGER_H
