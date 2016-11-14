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

#include <fourc/fmf/Acl.h>

namespace fourc {
namespace fmf {

const std::string Acl::OBJECT_TYPE_NAME = "acl";

Acl::Acl() : aclDenyCount(0), connectionDenyCount(0), queueQuotaDenyCount(0), maxConnections(0), maxConnectionsPerIp(0), maxConnectionsPerUser(0),
             maxQueuesPerUser(0), enforcingAcl(true), transferAcl(true),
             lastAclLoad(std::chrono::system_clock::time_point::min()) {
}

uint64_t Acl::getAclDenyCount() const {
  return aclDenyCount;
}

Acl& Acl::setAclDenyCount(const uint64_t value) {
  aclDenyCount = value;

  return *this;
}

uint64_t Acl::getConnectionDenyCount() const {
  return connectionDenyCount;
}

Acl& Acl::setConnectionDenyCount(const uint64_t value) {
  connectionDenyCount = value;

  return *this;
}

uint64_t Acl::getQueueQuotaDenyCount() const {
  return queueQuotaDenyCount;
}

Acl& Acl::setQueueQuotaDenyCount(const uint64_t value) {
  queueQuotaDenyCount = value;

  return *this;
}

uint16_t Acl::getMaxConnections() const {
  return maxConnections;
}

Acl& Acl::setMaxConnections(const uint16_t value) {
  maxConnections = value;

  return *this;
}

uint16_t Acl::getMaxConnectionsPerIp() const {
  return maxConnectionsPerIp;
}

Acl& Acl::setMaxConnectionsPerIp(const uint16_t value) {
  maxConnectionsPerIp = value;

  return *this;
}

uint16_t Acl::getMaxConnectionsPerUser() const {
  return maxConnectionsPerUser;
}

Acl& Acl::setMaxConnectionsPerUser(const uint16_t value) {
  maxConnectionsPerUser = value;

  return *this;
}

uint16_t Acl::getMaxQueuesPerUser() const {
  return maxQueuesPerUser;
}

Acl& Acl::setMaxQueuesPerUser(const uint16_t value) {
  maxQueuesPerUser = value;

  return *this;
}

bool Acl::isEnforcingAcl() const {
  return enforcingAcl;
}

Acl& Acl::setIsEnforcingAcl(const bool value) {
  enforcingAcl = value;

  return *this;
}

bool Acl::isTransferAcl() const {
  return transferAcl;
}

Acl& Acl::setIsTransferAcl(const bool value) {
  transferAcl = value;

  return *this;
}

const std::chrono::system_clock::time_point& Acl::getLastAclLoad() const {
  return lastAclLoad;
}

Acl& Acl::setLastAclLoad(const std::chrono::system_clock::time_point& value) {
  lastAclLoad = value;

  return *this;
}

const std::string& Acl::getBrokerRef() const {
  return brokerRef;
}

Acl& Acl::setBrokerRef(const std::string& value) {
  brokerRef = value;

  return *this;
}

const std::string& Acl::getPolicyFile() const {
  return policyFile;
}

Acl& Acl::setPolicyFile(const std::string& value) {
  policyFile = value;

  return *this;
}

}} // Namespaces