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

#ifndef FOURC_FMF_EXCHANGETYPEDESC_H
#define FOURC_FMF_EXCHANGETYPEDESC_H

#include <fourc/fmf/Exchange.h>
#include <map>

namespace fourc {
namespace fmf {

class ExchangeTypeDesc {
public:
  ExchangeTypeDesc() = delete;

  static const std::string DIRECT;
  static const std::string TOPIC;
  static const std::string FANOUT;
  static const std::string HEADER;
  static const std::string XML;

  static std::string getExchangeTypeDesc(Exchange::ExchangeType exchangeType);
  static Exchange::ExchangeType getExchangeType(std::string exchangeTypeDesc);

protected:
  static const std::map<std::string, Exchange::ExchangeType> exchange_type_map;
};

}} // Namespaces

#endif //FOURC_FMF_EXCHANGETYPEDESC_H
