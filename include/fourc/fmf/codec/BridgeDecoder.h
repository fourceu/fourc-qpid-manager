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

#ifndef FOURC_QPID_MANAGER_BRIDGEDECODER_H
#define FOURC_QPID_MANAGER_BRIDGEDECODER_H

#include "../Bridge.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class BridgeDecoder : public Decoder<Bridge, VariantT> {
public:
  static const std::string PROPERTY_NAME_LINK_REF;
  static const std::string PROPERTY_NAME_NAME;
  static const std::string PROPERTY_NAME_CHANNEL_ID;
  static const std::string PROPERTY_NAME_DURABLE;
  static const std::string PROPERTY_NAME_SRC;
  static const std::string PROPERTY_NAME_DEST;
  static const std::string PROPERTY_NAME_KEY;
  static const std::string PROPERTY_NAME_SRC_IS_QUEUE;
  static const std::string PROPERTY_NAME_SRC_IS_LOCAL;
  static const std::string PROPERTY_NAME_TAG;
  static const std::string PROPERTY_NAME_EXCLUDES;
  static const std::string PROPERTY_NAME_DYNAMIC;
  static const std::string PROPERTY_NAME_SYNC;
  static const std::string PROPERTY_NAME_CREDIT;

  typedef typename VariantT::Map MapT;

  virtual ~BridgeDecoder() = default;

  std::shared_ptr<Bridge> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = ValueReader::get(objectProperties, RPNs::VALUES, true).asMap();

    decoded->setLinkRef(ValueReader::get(values, PROPERTY_NAME_LINK_REF))
            .setName(ValueReader::get(values, PROPERTY_NAME_NAME))
            .setChannelId(ValueReader::get(values, PROPERTY_NAME_CHANNEL_ID))
            .setDurable(ValueReader::get(values, PROPERTY_NAME_DURABLE))
            .setSrc(ValueReader::get(values, PROPERTY_NAME_SRC))
            .setDest(ValueReader::get(values, PROPERTY_NAME_DEST))
            .setKey(ValueReader::get(values, PROPERTY_NAME_KEY))
            .setSrcQueue(ValueReader::get(values, PROPERTY_NAME_SRC_IS_QUEUE))
            .setSrcLocal(ValueReader::get(values, PROPERTY_NAME_SRC_IS_LOCAL))
            .setTag(ValueReader::get(values, PROPERTY_NAME_TAG))
            .setExcludes(ValueReader::get(values, PROPERTY_NAME_EXCLUDES))
            .setDynamic(ValueReader::get(values, PROPERTY_NAME_DYNAMIC))
            .setSync(ValueReader::get(values, PROPERTY_NAME_SYNC))
            .setCredit(ValueReader::get(values, PROPERTY_NAME_CREDIT));

    return decoded;
  }
};

template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_LINK_REF = "linkRef";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_NAME = "name";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_CHANNEL_ID = "channelId";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_DURABLE = "durable";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_SRC = "src";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_DEST = "dest";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_KEY = "key";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_SRC_IS_QUEUE = "srcIsQueue";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_SRC_IS_LOCAL = "srcIsLocal";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_TAG = "tag";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_EXCLUDES = "excludes";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_DYNAMIC = "dynamic";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_SYNC = "sync";
template <typename VariantT> const std::string BridgeDecoder<VariantT>::PROPERTY_NAME_CREDIT = "credit";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_BRIDGEDECODER_H
