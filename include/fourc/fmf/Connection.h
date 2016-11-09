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

#ifndef FOURC_FMF_CONNECTION_H
#define FOURC_FMF_CONNECTION_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

/**
 * \brief Holds data about a broker connection.
 * Caveat:
 * Current implementation excludes information available in the remoteProperties map (not deemed useful enough for the
 * dev effort of implementation at this time)
 */
class Connection : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Connection();

  bool isSystemConnection() const;
  Connection& setSystemConnection(bool);

  const std::string& getAddress() const;
  Connection& setAddress(const std::string&);

  const std::string& getAuthIdentity() const;
  Connection& setAuthIdentity(const std::string&);

  uint64_t getBytesFromClient() const;
  Connection& setBytesFromClient(uint64_t);

  uint64_t getBytesToClient() const;
  Connection& setBytesToClient(uint64_t);

  bool isClosing() const;
  Connection& setIsClosing(bool);

  bool isFederationLink() const;
  Connection& setIsFederationLink(bool);

  uint64_t getFramesFromClient() const;
  Connection& setFramesFromClient(uint64_t);

  uint64_t getFramesToClient() const;
  Connection& setFramesToClient(uint64_t);

  bool isIncoming() const;
  Connection& setIsIncoming(bool);

  uint64_t getMsgsFromClient() const;
  Connection& setMsgsFromClient(uint64_t);

  uint64_t getMsgsToClient() const;
  Connection& setMsgsToClient(uint64_t);

  const std::string& getProtocol() const;
  Connection& setProtocol(const std::string&);

  uint32_t getRemotePid() const;
  Connection& setRemotePid(uint32_t);

  uint32_t getRemoteParentPid() const;
  Connection& setRemoteParentPid(uint32_t);

  const std::string& getRemoteProcessName() const;
  Connection& setRemoteProcessName(const std::string&);

  const std::string& getSaslMechanism() const;
  Connection& setSaslMechanism(const std::string&);

  uint64_t getSaslSsf() const;
  Connection& setSaslSsf(uint64_t);

  bool isShadow() const;
  Connection& setIsShadow(bool);

  bool isUserProxyAuth() const;
  Connection& setIsUserProxyAuth(bool);

  const std::string& getVhostRef() const;
  Connection& setVhostRef(const std::string&);

private:
  bool systemConnection;
  std::string address;
  std::string authIdentity;
  uint64_t bytesFromClient;
  uint64_t bytesToClient;
  bool closing;
  bool federationLink;
  uint64_t framesFromClient;
  uint64_t framesToClient;
  bool incoming;
  uint64_t msgsFromClient;
  uint64_t msgsToClient;
  std::string protocol;
  uint32_t remoteParentPid;
  uint32_t remotePid;
  std::string remoteProcessName;
  std::string saslMechanism;
  uint64_t saslSsf;
  bool shadow;
  bool userProxyAuth;
  std::string vhostRef;
};

}} // Namespaces

#endif //FOURC_FMF_CONNECTION_H
