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

#include <fourc/fmf/Binding.h>

namespace fourc {
namespace fmf {

const std::string Binding::OBJECT_TYPE_NAME = "binding";

Binding::Binding() : exchangeEpoch(0), queueEpoch(0), msgMatched(0) {

}

const std::string& Binding::getExchangeName() const {
  return exchangeName;
}

Binding& Binding::setExchangeName(const std::string& value) {
  exchangeName = value;

  return *this;
}

const std::string& Binding::getQueueName() const {
  return queueName;
}

Binding& Binding::setQueueName(const std::string& value) {
  queueName = value;

  return *this;
}

const std::string& Binding::getBindingKey() const {
  return bindingKey;
}

Binding& Binding::setBindingKey(const std::string& value) {
  bindingKey = value;

  return *this;
}

uint64_t Binding::getExchangeEpoch() const {
  return exchangeEpoch;
}

Binding& Binding::setExchangeEpoch(uint64_t value) {
  exchangeEpoch = value;

  return *this;
}

uint64_t Binding::getQueueEpoch() const {
  return queueEpoch;
}

Binding& Binding::setQueueEpoch(uint64_t value) {
  queueEpoch = value;

  return *this;
}

uint64_t Binding::getMsgMatched() const {
  return msgMatched;
}

Binding& Binding::setMsgMatched(uint64_t value) {
  msgMatched = value;

  return *this;
}

}} // Namespaces
