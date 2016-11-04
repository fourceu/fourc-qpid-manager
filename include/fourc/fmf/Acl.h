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

#ifndef FOURC_FMF_ACL_H
#define FOURC_FMF_ACL_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Acl : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Acl();

  uint32_t getAclDenyCount() const;
  Acl& setAclDenyCount(const uint32_t);

  uint32_t getConnectionDenyCount() const;
  Acl& setConnectionDenyCount(const uint32_t);

  uint32_t getMaxConnections() const;
  Acl& setMaxConnections(const uint32_t);

  uint32_t getMaxConnectionsPerIp() const;
  Acl& setMaxConnectionsPerIp(const uint32_t);

  uint32_t getMaxConnectionsPerUser() const;
  Acl& setMaxConnectionsPerUser(const uint32_t);

  uint32_t getMaxQueuesPerUser() const;
  Acl& setMaxQueuesPerUser(const uint32_t);

  uint32_t getQueueQuotaDenyCount() const;
  Acl& setQueueQuotaDenyCount(const uint32_t);

  bool isEnforcingAcl() const;
  Acl& setIsEnforcingAcl(const bool);

  bool isTransferAcl() const;
  Acl& setIsTransferAcl(const bool);

  const std::chrono::system_clock::time_point& getLastAclLoad() const;
  Acl& setLastAclLoad(const std::chrono::system_clock::time_point&);

  const std::string& getBrokerRef() const;
  Acl& setBrokerRef(const std::string&);

  const std::string& getPolicyFile() const;
  Acl& setPolicyFile(const std::string&);

private:
  uint32_t aclDenyCount;
  uint32_t connectionDenyCount;
  uint32_t maxConnections;
  uint32_t maxConnectionsPerIp;
  uint32_t maxConnectionsPerUser;
  uint32_t maxQueuesPerUser;
  uint32_t queueQuotaDenyCount;
  bool enforcingAcl;
  bool transferAcl;
  std::chrono::system_clock::time_point lastAclLoad;
  std::string brokerRef;
  std::string policyFile;
};

}} // Namespaces

#endif //FOURC_FMF_ACL_H
