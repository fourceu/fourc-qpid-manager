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

#ifndef FOURC_QPID_MANAGER_SESSIONDECODER_H
#define FOURC_QPID_MANAGER_SESSIONDECODER_H

#include "../Session.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class SessionDecoder : public Decoder<Session, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_TXN_COMMITS;
  static const std::string PROPERTY_NAME_TXN_COUNT;
  static const std::string PROPERTY_NAME_TXN_REJECTS;
  static const std::string PROPERTY_NAME_TXN_STARTS;
  static const std::string PROPERTY_NAME_ATTACHED;
  static const std::string PROPERTY_NAME_CHANNEL_ID;
  static const std::string PROPERTY_NAME_CLIENT_CREDIT;
  static const std::string PROPERTY_NAME_CONNECTION_REF;
  static const std::string PROPERTY_NAME_DETACHED_LIFESPAN;
  static const std::string PROPERTY_NAME_FRAMES_OUTSTANDING;
  static const std::string PROPERTY_NAME_FULL_NAME;
  static const std::string PROPERTY_NAME_UNACKED_MESSAGES;

  virtual ~SessionDecoder() = default;

  std::shared_ptr<Session> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = ValueReader::get(objectProperties, RPNs::VALUES, true).asMap();

    // connection_ref_map used for setting connectionRefEpoch and connectionRefName on the decoded session
    auto connection_ref_map = ValueReader::get(values, PROPERTY_NAME_CONNECTION_REF, true).asMap();

    decoded->setTxnCommmits(ValueReader::get(values, PROPERTY_NAME_TXN_COMMITS))
        .setTxnCount(ValueReader::get(values, PROPERTY_NAME_TXN_COUNT))
        .setTxnRejects(ValueReader::get(values, PROPERTY_NAME_TXN_REJECTS))
        .setTxnStarts(ValueReader::get(values, PROPERTY_NAME_TXN_STARTS))
        .setAttached(ValueReader::get(values, PROPERTY_NAME_ATTACHED))
        .setChannelId(ValueReader::get(values, PROPERTY_NAME_CHANNEL_ID))
        .setClientCredit(ValueReader::get(values, PROPERTY_NAME_CLIENT_CREDIT))
        .setConnectionEpoch(ValueReader::get(connection_ref_map, RPNs::OBJECT_AGENT_EPOCH))
        .setConnectionName(ValueReader::get(connection_ref_map, RPNs::OBJECT_NAME))
        .setDetachedLifespan(ValueReader::get(values, PROPERTY_NAME_DETACHED_LIFESPAN))
        .setFramesOutstanding(ValueReader::get(values, PROPERTY_NAME_FRAMES_OUTSTANDING))
        .setFullName(ValueReader::get(values, PROPERTY_NAME_FULL_NAME))
        .setName(ValueReader::get(values, RPNs::NAME))
        .setUnackedMessages(ValueReader::get(values, PROPERTY_NAME_UNACKED_MESSAGES))
        .setVhostRef(this->decodeVhostRef(values));

    return decoded;
  }
};

template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_TXN_COMMITS = "TxnCommits";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_TXN_COUNT = "TxnCount";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_TXN_REJECTS = "TxnRejects";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_TXN_STARTS = "TxnStarts";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_ATTACHED = "attached";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_CHANNEL_ID = "channelId";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_CLIENT_CREDIT = "clientCredit";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_CONNECTION_REF = "connectionRef";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_DETACHED_LIFESPAN = "detachedLifespan";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_FRAMES_OUTSTANDING = "framesOutstanding";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_FULL_NAME = "fullName";
template <typename VariantT> const std::string SessionDecoder<VariantT>::PROPERTY_NAME_UNACKED_MESSAGES = "unackedMessages";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_SESSIONDECODER_H
