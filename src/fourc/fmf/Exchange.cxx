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

#include <fourc/fmf/Exchange.h>

namespace fourc {
namespace fmf {

const std::string Exchange::OBJECT_TYPE_NAME = "exchange";

Exchange::Exchange() :
    autoDelete(false),
    bindingCount(0),
    bindingCountHigh(0),
    bindingCountLow(0),
    byteDrops(0),
    byteReceives(0),
    byteRoutes(0),
    durable(false),
    msgDrops(0),
    msgReceives(0),
    msgRoutes(0),
    producerCount(0),
    producerCountHigh(0),
    producerCountLow(0),
    exchangeType(ExchangeType::DIRECT) {
}

bool Exchange::operator==(const Exchange& other) const {
  return BrokerObject::operator==(other)
         && durable == other.durable
         && exchangeType == other.exchangeType
         && name == other.name;
}

bool Exchange::isAutoDelete() const {
  return autoDelete;
}

Exchange& Exchange::setIsAutoDelete(bool value) {
  autoDelete = value;

  return *this;
}

uint32_t Exchange::getBindingCount() const {
  return bindingCount;
}

Exchange& Exchange::setBindingCount(uint32_t value) {
  bindingCount = value;

  return *this;
}

uint32_t Exchange::getBindingCountHigh() const {
  return bindingCountHigh;
}

Exchange& Exchange::setBindingCountHigh(uint32_t value) {
  bindingCountHigh = value;

  return *this;
}

uint32_t Exchange::getBindingCountLow() const {
  return bindingCountLow;
}

Exchange& Exchange::setBindingCountLow(uint32_t value) {
  bindingCountLow = value;

  return *this;
}

uint64_t Exchange::getByteDrops() const {
  return byteDrops;
}

Exchange& Exchange::setByteDrops(uint64_t value) {
  byteDrops = value;

  return *this;
}

uint64_t Exchange::getByteReceives() const {
  return byteReceives;
}

Exchange& Exchange::setByteReceives(uint64_t value) {
  byteReceives = value;

  return *this;
}

uint64_t Exchange::getByteRoutes() const {
  return byteRoutes;
}

Exchange& Exchange::setByteRoutes(uint64_t value) {
  byteRoutes = value;

  return *this;
}

bool Exchange::isDurable() const {
  return durable;
}

Exchange& Exchange::setDurable(bool value) {
  durable = value;

  return *this;
}

uint64_t Exchange::getMsgDrops() const {
  return msgDrops;
}

Exchange& Exchange::setMsgDrops(uint64_t value) {
  msgDrops = value;

  return *this;
}

uint64_t Exchange::getMsgReceives() const {
  return msgReceives;
}

Exchange& Exchange::setMsgReceives(uint64_t value) {
  msgReceives = value;

  return *this;
}

uint64_t Exchange::getMsgRoutes() const {
  return msgRoutes;
}

Exchange& Exchange::setMsgRoutes(uint64_t value) {
  msgRoutes = value;

  return *this;
}

const std::string& Exchange::getName() const {
  return name;
}

Exchange& Exchange::setName(const std::string& value) {
  name = value;

  return *this;
}

uint32_t Exchange::getProducerCount() const {
  return producerCount;
}

Exchange& Exchange::setProducerCount(uint32_t value) {
  producerCount = value;

  return *this;
}

uint32_t Exchange::getProducerCountHigh() const {
  return producerCountHigh;
}

Exchange& Exchange::setProducerCountHigh(uint32_t value) {
  producerCountHigh = value;

  return *this;
}

uint32_t Exchange::getProducerCountLow() const {
  return producerCountLow;
}

Exchange& Exchange::setProducerCountLow(uint32_t value) {
  producerCountLow = value;

  return *this;
}

Exchange::ExchangeType Exchange::getExchangeType() const {
  return exchangeType;
}

Exchange& Exchange::setExchangeType(const Exchange::ExchangeType value) {
  exchangeType = value;

  return *this;
}

const std::string& Exchange::getVhostRef() const {
  return vhostRef;
}

Exchange& Exchange::setVhostRef(const std::string& value) {
  vhostRef = value;

  return *this;
}

}} // Namespaces
