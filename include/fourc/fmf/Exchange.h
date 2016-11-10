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

  bool isAutoDelete() const;
  Exchange& setIsAutoDelete(bool);

  uint32_t getBindingCount() const;
  Exchange& setBindingCount(uint32_t);

  uint32_t getBindingCountHigh() const;
  Exchange& setBindingCountHigh(uint32_t);

  uint32_t getBindingCountLow() const;
  Exchange& setBindingCountLow(uint32_t);

  uint64_t getByteDrops() const;
  Exchange& setByteDrops(uint64_t);

  uint64_t getByteReceives() const;
  Exchange& setByteReceives(uint64_t);

  uint64_t getByteRoutes() const;
  Exchange& setByteRoutes(uint64_t);

  bool isDurable() const;
  Exchange& setDurable(bool value);

  uint64_t getMsgDrops() const;
  Exchange& setMsgDrops(uint64_t);

  uint64_t getMsgReceives() const;
  Exchange& setMsgReceives(uint64_t);

  uint64_t getMsgRoutes() const;
  Exchange& setMsgRoutes(uint64_t);

  const std::string& getName() const;
  Exchange& setName(const std::string&);

  uint32_t getProducerCount() const;
  Exchange& setProducerCount(uint32_t);

  uint32_t getProducerCountHigh() const;
  Exchange& setProducerCountHigh(uint32_t);

  uint32_t getProducerCountLow() const;
  Exchange& setProducerCountLow(uint32_t);

  ExchangeType getExchangeType() const;
  Exchange& setExchangeType(const ExchangeType);

  const std::string& getVhostRef() const;
  Exchange& setVhostRef(const std::string&);

  bool operator==(const Exchange& other) const;

protected:
  bool autoDelete;
  uint32_t bindingCount;
  uint32_t bindingCountHigh;
  uint32_t bindingCountLow;
  uint64_t byteDrops;
  uint64_t byteReceives;
  uint64_t byteRoutes;
  bool durable;
  uint64_t msgDrops;
  uint64_t msgReceives;
  uint64_t msgRoutes;
  std::string name;
  uint32_t producerCount;
  uint32_t producerCountHigh;
  uint32_t producerCountLow;
  ExchangeType exchangeType;
  std::string vhostRef;
};

}} // Namespaces

#endif //FOURC_FMF_EXCHANGE_H
