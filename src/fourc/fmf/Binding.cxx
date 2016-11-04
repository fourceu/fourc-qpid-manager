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

Binding::Binding() : durable(false) {

}

const std::string& Binding::getExchange() const {
  return exchange;
}

const std::string& Binding::getQueue() const {
  return queue;
}

const std::string& Binding::getBindingKey() const {
  return bindingKey;
}

bool Binding::isDurable() const {
  return durable;
}

Binding& Binding::setExchange(const std::string& value) {
  exchange = value;

  return *this;
}

Binding& Binding::setQueue(const std::string& value) {
  queue = value;

  return *this;
}

Binding& Binding::setBindingKey(const std::string& value) {
  bindingKey = value;

  return *this;
}

Binding& Binding::setDurable(bool value) {
  durable = value;

  return *this;
}

}} // Namespaces
