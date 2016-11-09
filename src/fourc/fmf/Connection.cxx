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

#include <fourc/fmf/Connection.h>

namespace fourc {
namespace fmf {

const std::string Connection::OBJECT_TYPE_NAME = "connection";

Connection::Connection() :
  systemConnection(false),
  bytesFromClient(0),
  bytesToClient(0),
  closing(false),
  federationLink(false),
  framesFromClient(0),
  framesToClient(0),
  incoming(false),
  msgsFromClient(0),
  msgsToClient(0),
  remoteParentPid(0),
  remotePid(0),
  saslSsf(0),
  shadow(false),
  userProxyAuth(false) {}

bool Connection::isSystemConnection() const {
  return systemConnection;
}

Connection& Connection::setSystemConnection(bool value) {
  systemConnection = value;

  return *this;
}

const std::string& Connection::getAddress() const {
  return address;
}

Connection& Connection::setAddress(const std::string& value) {
  address = value;

  return *this;
}

const std::string& Connection::getAuthIdentity() const {
  return authIdentity;
}

Connection& Connection::setAuthIdentity(const std::string& value) {
  authIdentity = value;

  return *this;
}

uint64_t Connection::getBytesFromClient() const {
  return bytesFromClient;
}

Connection& Connection::setBytesFromClient(uint64_t value) {
  bytesFromClient = value;

  return *this;
}

uint64_t Connection::getBytesToClient() const {
  return bytesToClient;
}
 
Connection& Connection::setBytesToClient(uint64_t value) {
  bytesToClient = value;

  return *this;
}

bool Connection::isClosing() const {
  return closing;
}

Connection& Connection::setIsClosing(bool value) {
  closing = value;

  return *this;
}

bool Connection::isFederationLink() const {
  return federationLink;
}

Connection& Connection::setIsFederationLink(bool value) {
  federationLink = value;

  return *this;
}

uint64_t Connection::getFramesFromClient() const {
  return framesFromClient;
}

Connection& Connection::setFramesFromClient(uint64_t value) {
  framesFromClient = value;

  return *this;
}

uint64_t Connection::getFramesToClient() const {
  return framesToClient;
}

Connection& Connection::setFramesToClient(uint64_t value) {
  framesToClient = value;

  return *this;
}

bool Connection::isIncoming() const {
  return incoming;
}
 
Connection& Connection::setIsIncoming(bool value) {
  incoming = value;

  return *this;
}

uint64_t Connection::getMsgsFromClient() const {
  return msgsFromClient;
}

Connection& Connection::setMsgsFromClient(uint64_t value) {
  msgsFromClient = value;

  return *this;
}

uint64_t Connection::getMsgsToClient() const {
  return msgsToClient;
}

Connection& Connection::setMsgsToClient(uint64_t value) {
  msgsToClient = value;

  return *this;
}

const std::string& Connection::getProtocol() const {
  return protocol;
}
 
Connection& Connection::setProtocol(const std::string& value) {
  protocol = value;

  return *this;
}

uint32_t Connection::getRemotePid() const {
  return remotePid;
}

Connection& Connection::setRemotePid(uint32_t value) {
  remotePid = value;

  return *this;
}

uint32_t Connection::getRemoteParentPid() const {
  return remoteParentPid;
}

Connection& Connection::setRemoteParentPid(uint32_t value) {
  remoteParentPid = value;

  return *this;
}

const std::string& Connection::getRemoteProcessName() const {
  return remoteProcessName;
}
 
Connection& Connection::setRemoteProcessName(const std::string& value) {
  remoteProcessName = value;

  return *this;
}

const std::string& Connection::getSaslMechanism() const {
  return saslMechanism;
}

Connection& Connection::setSaslMechanism(const std::string& value) {
  saslMechanism = value;

  return *this;
}

uint64_t Connection::getSaslSsf() const {
  return saslSsf;
}

Connection& Connection::setSaslSsf(uint64_t value) {
  saslSsf = value;

  return *this;
}

bool Connection::isUserProxyAuth() const {
  return userProxyAuth;
}

Connection& Connection::setIsUserProxyAuth(bool value) {
  userProxyAuth = value;

  return *this;
}

bool Connection::isShadow() const {
  return shadow;
}

Connection& Connection::setIsShadow(bool value) {
  shadow = value;

  return *this;
}

const std::string& Connection::getVhostRef() const {
  return vhostRef;
}

Connection& Connection::setVhostRef(const std::string& value) {
  vhostRef = value;

  return *this;
}

}} // Namespaces
