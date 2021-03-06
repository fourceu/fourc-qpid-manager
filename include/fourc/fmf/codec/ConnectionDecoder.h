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

  typedef typename VariantT::Map MapT;

  virtual ~ConnectionDecoder() = default;

  std::shared_ptr<Connection> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = ValueReader::get(objectProperties, RPNs::VALUES, true).asMap();

    decoded->setSystemConnection(ValueReader::get(values, PROPERTY_NAME_SYSTEM_CONNECTION))
      .setAddress(ValueReader::get(values, PROPERTY_NAME_ADDRESS))
      .setAuthIdentity(ValueReader::get(values, PROPERTY_NAME_AUTH_IDENTITY))
      .setBytesFromClient(ValueReader::get(values, PROPERTY_NAME_BYTES_FROM_CLIENT))
      .setBytesToClient(ValueReader::get(values, PROPERTY_NAME_BYTES_TO_CLIENT))
      .setIsClosing(ValueReader::get(values, PROPERTY_NAME_CLOSING))
      .setIsFederationLink(ValueReader::get(values, PROPERTY_NAME_FEDERATION_LINK))
      .setFramesFromClient(ValueReader::get(values, PROPERTY_NAME_FRAMES_FROM_CLIENT))
      .setFramesToClient(ValueReader::get(values, PROPERTY_NAME_FRAMES_TO_CLIENT))
      .setIsIncoming(ValueReader::get(values, PROPERTY_NAME_INCOMING))
      .setMsgsFromClient(ValueReader::get(values, PROPERTY_NAME_MSGS_FROM_CLIENT))
      .setMsgsToClient(ValueReader::get(values, PROPERTY_NAME_MSGS_TO_CLIENT))
      .setProtocol(ValueReader::get(values, PROPERTY_NAME_PROTOCOL))
      .setRemoteParentPid(ValueReader::get(values, PROPERTY_NAME_REMOTE_PARENT_PID))
      .setRemotePid(ValueReader::get(values, PROPERTY_NAME_REMOTE_PID))
      .setRemoteProcessName(ValueReader::get(values, PROPERTY_NAME_REMOTE_PROCESS_NAME))
      .setSaslMechanism(ValueReader::get(values, PROPERTY_NAME_SASL_MECHANISM))
      .setSaslSsf(ValueReader::get(values, PROPERTY_NAME_SASL_SSF))
      .setIsShadow(ValueReader::get(values, PROPERTY_NAME_SHADOW))
      .setIsUserProxyAuth(ValueReader::get(values, PROPERTY_NAME_USER_PROXY_AUTH))
      .setVhostRef(this->decodeVhostRef(values));

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

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_ConnectionDECODER_H
