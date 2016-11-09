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

#ifndef FOURC_QPID_MANAGER_CONNECTIONDECODER_H
#define FOURC_QPID_MANAGER_CONNECTIONDECODER_H

#include "../Connection.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class ConnectionDecoder : public Decoder<Connection, VariantT> {
public:
  static const std::string PROPERTY_NAME_SYSTEM_CONNECTION;
  static const std::string PROPERTY_NAME_ADDRESS;
  static const std::string PROPERTY_NAME_AUTH_IDENTITY;
  static const std::string PROPERTY_NAME_BYTES_FROM_CLIENT;
  static const std::string PROPERTY_NAME_BYTES_TO_CLIENT;
  static const std::string PROPERTY_NAME_CLOSING;
  static const std::string PROPERTY_NAME_FEDERATION_LINK;
  static const std::string PROPERTY_NAME_FRAMES_FROM_CLIENT;
  static const std::string PROPERTY_NAME_FRAMES_TO_CLIENT;
  static const std::string PROPERTY_NAME_INCOMING;
  static const std::string PROPERTY_NAME_MSGS_FROM_CLIENT;
  static const std::string PROPERTY_NAME_MSGS_TO_CLIENT;
  static const std::string PROPERTY_NAME_PROTOCOL;
  static const std::string PROPERTY_NAME_REMOTE_PARENT_PID;
  static const std::string PROPERTY_NAME_REMOTE_PID;
  static const std::string PROPERTY_NAME_REMOTE_PROCESS_NAME;
  static const std::string PROPERTY_NAME_SASL_MECHANISM;
  static const std::string PROPERTY_NAME_SASL_SSF;
  static const std::string PROPERTY_NAME_SHADOW;
  static const std::string PROPERTY_NAME_USER_PROXY_AUTH;
  static const std::string PROPERTY_NAME_VHOST_REF;
  
  typedef typename VariantT::Map MapT;

  virtual ~ConnectionDecoder() = default;

  std::shared_ptr<Connection> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();

    auto vhost_ref_map = this->getMapProperty(values, PROPERTY_NAME_VHOST_REF, true).asMap();

    decoded->setSystemConnection(this->getMapProperty(values, PROPERTY_NAME_SYSTEM_CONNECTION))
      .setAddress(this->getMapProperty(values, PROPERTY_NAME_ADDRESS))
      .setAuthIdentity(this->getMapProperty(values, PROPERTY_NAME_AUTH_IDENTITY))
      .setBytesFromClient(this->getMapProperty(values, PROPERTY_NAME_BYTES_FROM_CLIENT))
      .setBytesToClient(this->getMapProperty(values, PROPERTY_NAME_BYTES_TO_CLIENT))
      .setIsClosing(this->getMapProperty(values, PROPERTY_NAME_CLOSING))
      .setIsFederationLink(this->getMapProperty(values, PROPERTY_NAME_FEDERATION_LINK))
      .setFramesFromClient(this->getMapProperty(values, PROPERTY_NAME_FRAMES_FROM_CLIENT))
      .setFramesToClient(this->getMapProperty(values, PROPERTY_NAME_FRAMES_TO_CLIENT))
      .setIsIncoming(this->getMapProperty(values, PROPERTY_NAME_INCOMING))
      .setMsgsFromClient(this->getMapProperty(values, PROPERTY_NAME_MSGS_FROM_CLIENT))
      .setMsgsToClient(this->getMapProperty(values, PROPERTY_NAME_MSGS_TO_CLIENT))
      .setProtocol(this->getMapProperty(values, PROPERTY_NAME_PROTOCOL))
      .setRemoteParentPid(this->getMapProperty(values, PROPERTY_NAME_REMOTE_PARENT_PID))
      .setRemotePid(this->getMapProperty(values, PROPERTY_NAME_REMOTE_PID))
      .setRemoteProcessName(this->getMapProperty(values, PROPERTY_NAME_REMOTE_PROCESS_NAME))
      .setSaslMechanism(this->getMapProperty(values, PROPERTY_NAME_SASL_MECHANISM))
      .setSaslSsf(this->getMapProperty(values, PROPERTY_NAME_SASL_SSF))
      .setIsShadow(this->getMapProperty(values, PROPERTY_NAME_SHADOW))
      .setIsUserProxyAuth(this->getMapProperty(values, PROPERTY_NAME_USER_PROXY_AUTH))
      .setVhostRef(this->getMapProperty(vhost_ref_map, RPNs::OBJECT_NAME));

    return decoded;
  }
};

template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_SYSTEM_CONNECTION = "SystemConnection";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_ADDRESS = "address";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_AUTH_IDENTITY = "authIdentity";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_BYTES_FROM_CLIENT = "bytesFromClient";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_BYTES_TO_CLIENT = "bytesToClient";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_CLOSING = "closing";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_FEDERATION_LINK = "federationLink";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_FRAMES_FROM_CLIENT = "framesFromClient";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_FRAMES_TO_CLIENT = "framesToClient";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_INCOMING = "incoming";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_MSGS_FROM_CLIENT = "msgsFromClient";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_MSGS_TO_CLIENT = "msgsToClient";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_PROTOCOL = "protocol";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_REMOTE_PARENT_PID = "remoteParentPid";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_REMOTE_PID = "remotePid";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_REMOTE_PROCESS_NAME = "remoteProcessName";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_SASL_MECHANISM = "saslMechanism";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_SASL_SSF = "saslSsf";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_SHADOW = "shadow";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_USER_PROXY_AUTH = "userProxyAuth";
template <typename VariantT> const std::string ConnectionDecoder<VariantT>::PROPERTY_NAME_VHOST_REF = "vhostRef";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_ConnectionDECODER_H
