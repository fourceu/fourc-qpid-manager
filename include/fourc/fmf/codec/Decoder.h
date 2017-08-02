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

#ifndef FOURC_FMF_DECODER_H
#define FOURC_FMF_DECODER_H

#include "DecodeException.h"
#include "ResponsePropertyNames.h"
#include "ValueReader.h"
#include <fourc/fmf/ObjectId.h>
#include <fourc/fmf/SchemaId.h>

#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

#include <chrono>

namespace fourc {
namespace fmf {
namespace codec {

using RPNs = ResponsePropertyNames;

class Node;

template<typename ObjectT, typename VariantT>
class Decoder {
public:
  typedef typename VariantT::Map MapT;

  virtual ~Decoder() = default;

protected:
  /**
   * \brief Creates a new decoded object with basic properties set
   * @param objectProperties
   * @return A shared_ptr to the new object
   */
  std::shared_ptr<ObjectT> createObject(const MapT& objectProperties) const {
    //std::cout << objectProperties << std::endl;

    auto object = std::make_shared<ObjectT>();

    decodeTimestamps(object, objectProperties);
    decodeObjectId(object, objectProperties);
    decodeSchemaId(object, objectProperties);

    return object;
  }

  /**
   * \brief Converts a variant containing a 64 bit integer of nanoseconds to an std::chrono::time_point structure
   * @param value
   * @return
   */
  std::chrono::system_clock::time_point decodeTimestamp(const VariantT& value) const {
    return std::chrono::system_clock::time_point(std::chrono::nanoseconds(value.asInt64()));
  }

  /**
   * \brief Decodes the object created, deleted and updated timestamps from a query response
   * @param object
   * @param objectProperties
   */
  void decodeTimestamps(std::shared_ptr<ObjectT>& object, const MapT& objectProperties) const {
    auto created = decodeTimestamp(ValueReader::get(objectProperties, RPNs::CREATED));
    auto deleted = decodeTimestamp(ValueReader::get(objectProperties, RPNs::DELETED));
    auto updated = decodeTimestamp(ValueReader::get(objectProperties, RPNs::UPDATED));

    object->setTimeCreated(created)
        .setTimeDeleted(deleted)
        .setTimeUpdated(updated);
  }

  /**
   * \brief Decodes an ObjectId structure from a query response
   * @param object
   * @param objectProperties
   */
  void decodeObjectId(std::shared_ptr<ObjectT>& object, const MapT& objectProperties) const {
    auto object_id_map = ValueReader::get(objectProperties, RPNs::OBJECT_ID).asMap();

    std::string oid = ValueReader::get(object_id_map, RPNs::OBJECT_NAME);
    int agentEpoch = ValueReader::get(object_id_map, RPNs::OBJECT_AGENT_EPOCH).asInt32();

    ObjectId objectId;
    objectId.setName(oid)
        .setAgentEpoch(agentEpoch);

    object->setObjectId(objectId);
  }

  /**
   * \brief Decodes a SchemaId structure from a query response
   * @param object
   * @param objectProperties
   */
  void decodeSchemaId(std::shared_ptr<ObjectT>& object, const MapT& objectProperties) const {
    auto schema_id_map = ValueReader::get(objectProperties, RPNs::SCHEMA_ID).asMap();

    std::string class_name = ValueReader::get(schema_id_map, ResponsePropertyNames::SCHEMA_CLASS_NAME);
    std::string package = ValueReader::get(schema_id_map, ResponsePropertyNames::SCHEMA_PACKAGE_NAME);
    std::string hash = ValueReader::get(schema_id_map, ResponsePropertyNames::SCHEMA_HASH);
    std::string type = ValueReader::get(schema_id_map, ResponsePropertyNames::SCHEMA_TYPE);

    SchemaId schema_id;
    schema_id.setClassName(class_name)
        .setPackageName(package)
        .setHash(hash)
        .setType(type);

    object->setSchemaId(schema_id);
  }

  /**
   * \brief Decodes the vhost ref from a values submap
   * @param values
   * @return
   */
  std::string decodeVhostRef(const MapT& values) const {
    auto vhost_ref_map = ValueReader::get(values, RPNs::VHOST_REF, true).asMap();

    return ValueReader::get(vhost_ref_map, RPNs::OBJECT_NAME);
  }
};

}}} // Namespaces

#endif //FOURC_FMF_DECODER_H
