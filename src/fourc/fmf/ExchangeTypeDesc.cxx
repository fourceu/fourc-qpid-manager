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

#include <fourc/fmf/ExchangeTypeDesc.h>

namespace fourc {
namespace fmf {

const std::string ExchangeTypeDesc::DIRECT = "direct";
const std::string ExchangeTypeDesc::TOPIC = "topic";
const std::string ExchangeTypeDesc::FANOUT = "fanout";
const std::string ExchangeTypeDesc::HEADER = "headers";
const std::string ExchangeTypeDesc::XML = "xml";

const std::map<std::string, Exchange::ExchangeType> ExchangeTypeDesc::exchange_type_map = {
    { ExchangeTypeDesc::DIRECT, Exchange::ExchangeType::DIRECT },
    { ExchangeTypeDesc::TOPIC, Exchange::ExchangeType::TOPIC },
    { ExchangeTypeDesc::FANOUT, Exchange::ExchangeType::FANOUT },
    { ExchangeTypeDesc::HEADER, Exchange::ExchangeType::HEADERS },
    { ExchangeTypeDesc::XML, Exchange::ExchangeType::XML }
};

std::string ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType exchangeType) {
  for (auto itr = exchange_type_map.begin(); itr != exchange_type_map.end(); ++itr) {
    if (itr->second == exchangeType) {
      return itr->first;
    }
  }

  throw std::range_error("An exchange type ID was provided for which there is no description.");
}

Exchange::ExchangeType ExchangeTypeDesc::getExchangeType(std::string exchangeTypeDesc) {
  auto itr = exchange_type_map.find(exchangeTypeDesc);
  return itr == exchange_type_map.end() ? Exchange::ExchangeType::OTHER : itr->second;
}

}} // Namespaces
