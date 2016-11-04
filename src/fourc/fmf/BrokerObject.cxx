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

#include <fourc/fmf/BrokerObject.h>

namespace fourc {
namespace fmf {

const std::chrono::system_clock::time_point& BrokerObject::getTimeCreated() const {
  return created;
}

BrokerObject& BrokerObject::setTimeCreated(const std::chrono::system_clock::time_point& value) {
  created = value;

  return *this;
}

const std::chrono::system_clock::time_point& BrokerObject::getTimeDeleted() const {
  return deleted;
}

BrokerObject& BrokerObject::setTimeDeleted(const std::chrono::system_clock::time_point& value) {
  deleted = value;

  return *this;
}

const std::chrono::system_clock::time_point& BrokerObject::getTimeUpdated() const {
  return updated;
}

BrokerObject& BrokerObject::setTimeUpdated(const std::chrono::system_clock::time_point& value) {
  updated = value;

  return *this;
}

const ObjectId& BrokerObject::getObjectId() const {
  return objectId;
}

BrokerObject& BrokerObject::setObjectId(const ObjectId& value) {
  objectId = value;

  return *this;
}

const SchemaId& BrokerObject::getSchemaId() const {
  return schemaId;
}

BrokerObject& BrokerObject::setSchemaId(const SchemaId& value) {
  schemaId = value;

  return *this;
}

bool BrokerObject::operator==(const BrokerObject& other) const {
  return created == other.created
      && deleted == other.deleted
      && updated == other.updated
      && objectId == other.objectId
      && schemaId == other.schemaId;
}

}} // Namespaces