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

#ifndef FOURC_FMF_EXCHANGEDECODER_H
#define FOURC_FMF_EXCHANGEDECODER_H

#include "Decoder.h"
#include "DecodeException.h"
#include "ValueReader.h"
#include "../ExchangeTypeDesc.h"
#include "../Exchange.h"

#include <boost/assign/list_of.hpp>

#include <map>

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class ExchangeDecoder : public Decoder<Exchange, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_AUTODELETE;
  static const std::string PROPERTY_NAME_BINDING_COUNT;
  static const std::string PROPERTY_NAME_BINDING_COUNT_HIGH;
  static const std::string PROPERTY_NAME_BINDING_COUNT_LOW;
  static const std::string PROPERTY_NAME_BYTE_DROPS;
  static const std::string PROPERTY_NAME_BYTE_RECEIVES;
  static const std::string PROPERTY_NAME_BYTE_ROUTES;
  static const std::string PROPERTY_NAME_MSG_DROPS;
  static const std::string PROPERTY_NAME_MSG_RECEIVES;
  static const std::string PROPERTY_NAME_MSG_ROUTES;
  static const std::string PROPERTY_NAME_PRODUCER_COUNT;
  static const std::string PROPERTY_NAME_PRODUCER_COUNT_HIGH;
  static const std::string PROPERTY_NAME_PRODUCER_COUNT_LOW;
  static const std::string PROPERTY_NAME_EXCHANGE_TYPE;
  static const std::string PROPERTY_NAME_VHOSTREF;

  virtual ~ExchangeDecoder() = default;

  std::shared_ptr<Exchange> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = ValueReader::get(objectProperties, RPNs::VALUES, true).asMap();

    decoded->setIsAutoDelete(ValueReader::get(values, PROPERTY_NAME_AUTODELETE))
      .setBindingCount(ValueReader::get(values, PROPERTY_NAME_BINDING_COUNT))
      .setBindingCountHigh(ValueReader::get(values, PROPERTY_NAME_BINDING_COUNT_HIGH))
      .setBindingCountLow(ValueReader::get(values, PROPERTY_NAME_BINDING_COUNT_LOW))
      .setByteDrops(ValueReader::get(values, PROPERTY_NAME_BYTE_DROPS))
      .setByteReceives(ValueReader::get(values, PROPERTY_NAME_BYTE_RECEIVES))
      .setByteRoutes(ValueReader::get(values, PROPERTY_NAME_BYTE_ROUTES))
      .setDurable(ValueReader::get(values, RPNs::DURABLE))
      .setMsgDrops(ValueReader::get(values, PROPERTY_NAME_MSG_DROPS))
      .setMsgReceives(ValueReader::get(values, PROPERTY_NAME_MSG_RECEIVES))
      .setMsgRoutes(ValueReader::get(values, PROPERTY_NAME_MSG_ROUTES))
      .setName(ValueReader::get(values, RPNs::NAME))
      .setProducerCount(ValueReader::get(values, PROPERTY_NAME_PRODUCER_COUNT))
      .setProducerCountHigh(ValueReader::get(values, PROPERTY_NAME_PRODUCER_COUNT_HIGH))
      .setProducerCountLow(ValueReader::get(values, PROPERTY_NAME_PRODUCER_COUNT_LOW))
      .setExchangeType(getExchangeType(values))
      .setVhostRef(this->decodeVhostRef(values));

    return decoded;
  }

protected:
  /**
   * \brief Reads the exchange type property from the map.
   * Facilitates testing.
   * @param values
   * @return
   */
  virtual std::string getExchangeTypeDesc(const MapT& values) const {
    return ValueReader::get(values, PROPERTY_NAME_EXCHANGE_TYPE);
  }

  Exchange::ExchangeType getExchangeType(const MapT& values) const {
    // Get the string representation of the exchange type
    auto exchange_type_desc = getExchangeTypeDesc(values);

    return ExchangeTypeDesc::getExchangeType(exchange_type_desc);
  }
};

template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_AUTODELETE = "autoDelete";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_BINDING_COUNT = "bindingCount";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_BINDING_COUNT_HIGH = "bindingCountHigh";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_BINDING_COUNT_LOW = "bindingCountLow";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_BYTE_DROPS = "byteDrops";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_BYTE_RECEIVES = "byteReceives";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_BYTE_ROUTES = "byteRoutes";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_MSG_DROPS = "msgDrops";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_MSG_RECEIVES = "msgReceives";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_MSG_ROUTES = "msgRoutes";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_PRODUCER_COUNT = "producerCount";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_PRODUCER_COUNT_HIGH = "producerCountHigh";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_PRODUCER_COUNT_LOW = "producerCountLow";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_EXCHANGE_TYPE = "type";
template <typename VariantT> const std::string ExchangeDecoder<VariantT>::PROPERTY_NAME_VHOSTREF = "vhostRef";

}}} // Namespaces

#endif //FOURC_FMF_EXCHANGEDECODER_H
