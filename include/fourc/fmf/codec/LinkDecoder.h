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

#ifndef FOURC_QPID_MANAGER_LINKDECODER_H
#define FOURC_QPID_MANAGER_LINKDECODER_H

#include "../Link.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class LinkDecoder : public Decoder<Link, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_CONNECTION_REF;
  static const std::string PROPERTY_NAME_HOST;
  static const std::string PROPERTY_NAME_PORT;
  static const std::string PROPERTY_NAME_LAST_ERROR;
  static const std::string PROPERTY_NAME_STATE;
  static const std::string PROPERTY_NAME_TRANSPORT;

  virtual ~LinkDecoder() = default;

  std::shared_ptr<Link> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = ValueReader::get(objectProperties, RPNs::VALUES, true).asMap();

    auto connection_ref_map = ValueReader::get(values, PROPERTY_NAME_CONNECTION_REF, true).asMap();

    decoded->setConnectionEpoch(ValueReader::get(connection_ref_map, RPNs::OBJECT_AGENT_EPOCH))
          .setConnectionName(ValueReader::get(connection_ref_map, RPNs::OBJECT_NAME))
          .setDurable(ValueReader::get(values, RPNs::DURABLE))
          .setHost(ValueReader::get(values, PROPERTY_NAME_HOST))
          .setPort(ValueReader::get(values, PROPERTY_NAME_PORT))
          .setLastError(ValueReader::get(values, PROPERTY_NAME_LAST_ERROR))
          .setName(ValueReader::get(values, RPNs::NAME))
          .setState(ValueReader::get(values, PROPERTY_NAME_STATE))
          .setTransport(ValueReader::get(values, PROPERTY_NAME_TRANSPORT))
          .setVhostRef(this->decodeVhostRef(values));

    return decoded;
  }
};

template <typename VariantT> const std::string LinkDecoder<VariantT>::PROPERTY_NAME_CONNECTION_REF = "connectionRef";
template <typename VariantT> const std::string LinkDecoder<VariantT>::PROPERTY_NAME_HOST = "host";
template <typename VariantT> const std::string LinkDecoder<VariantT>::PROPERTY_NAME_PORT = "port";
template <typename VariantT> const std::string LinkDecoder<VariantT>::PROPERTY_NAME_LAST_ERROR = "lastError";
template <typename VariantT> const std::string LinkDecoder<VariantT>::PROPERTY_NAME_STATE = "state";
template <typename VariantT> const std::string LinkDecoder<VariantT>::PROPERTY_NAME_TRANSPORT = "transport";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_LINKDECODER_H
