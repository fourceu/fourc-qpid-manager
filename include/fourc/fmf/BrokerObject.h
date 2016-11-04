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

#ifndef FOURC_QPID_MANAGER_BROKEROBJECT_H
#define FOURC_QPID_MANAGER_BROKEROBJECT_H

#include "ObjectId.h"
#include "SchemaId.h"

#include <string>
#include <chrono>

namespace fourc {
namespace fmf {

/**
 * \brief Base class for all objects decoded on the qmf interface
 */
class BrokerObject {
public:
  const std::chrono::system_clock::time_point& getTimeCreated() const;
  BrokerObject& setTimeCreated(const std::chrono::system_clock::time_point& value);

  const std::chrono::system_clock::time_point& getTimeDeleted() const;
  BrokerObject& setTimeDeleted(const std::chrono::system_clock::time_point& value);

  const std::chrono::system_clock::time_point& getTimeUpdated() const;
  BrokerObject& setTimeUpdated(const std::chrono::system_clock::time_point& value);

  const ObjectId& getObjectId() const;
  BrokerObject& setObjectId(const ObjectId& value);

  const SchemaId& getSchemaId() const;
  BrokerObject& setSchemaId(const SchemaId& value);

  bool operator==(const BrokerObject& other) const;

protected:
  std::chrono::system_clock::time_point created;
  std::chrono::system_clock::time_point deleted;
  std::chrono::system_clock::time_point updated;
  ObjectId objectId;
  SchemaId schemaId;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_BROKEROBJECT_H
