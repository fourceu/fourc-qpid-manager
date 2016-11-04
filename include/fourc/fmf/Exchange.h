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

#ifndef FOURC_FMF_EXCHANGE_H
#define FOURC_FMF_EXCHANGE_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Exchange : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  enum class ExchangeType {
    DIRECT, TOPIC, FANOUT, HEADERS, XML, OTHER
  };

  Exchange();
  virtual ~Exchange() = default;

  const std::string& getName() const;
  Exchange& setName(const std::string&);

  bool isDurable() const;
  Exchange& setDurable(bool value);

  ExchangeType getExchangeType() const;
  Exchange& setExchangeType(const ExchangeType);

  bool operator==(const Exchange& other) const;

protected:
  std::string name;
  bool durable;
  ExchangeType exchangeType;
};

}} // Namespaces

#endif //FOURC_FMF_EXCHANGE_H
