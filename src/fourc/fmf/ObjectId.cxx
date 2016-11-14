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

#include <fourc/fmf/ObjectId.h>

namespace fourc {
namespace fmf {

ObjectId::ObjectId() : agentEpoch(0) {

}

const std::string& ObjectId::getName() const {
  return name;
}

ObjectId& ObjectId::setName(const std::string& value) {
  name = value;

  return *this;
}

uint64_t ObjectId::getAgentEpoch() const {
  return agentEpoch;
}

ObjectId& ObjectId::setAgentEpoch(uint64_t value) {
  agentEpoch = value;

  return *this;
}

bool ObjectId::operator==(const ObjectId& other) const {
  return agentEpoch == other.agentEpoch && name == other.name;
}

}} // Namespaces