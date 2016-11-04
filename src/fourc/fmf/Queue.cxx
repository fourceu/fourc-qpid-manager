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

#include <fourc/fmf/Queue.h>

namespace fourc {
namespace fmf {

const std::string Queue::OBJECT_TYPE_NAME = "queue";

Queue::Queue() : BrokerObject(), durable(false) {

}

const std::string& Queue::getName() const {
  return name;
}

Queue& Queue::setName(const std::string& value) {
  name = value;

  return *this;
}

bool Queue::isDurable() const {
  return durable;
}

Queue& Queue::setDurable(bool value) {
  durable = value;

  return *this;
}

bool Queue::operator==(const Queue& other) const {
  return BrokerObject::operator==(other)
      && durable == other.durable
      && name == other.name;
}

}} // Namespaces