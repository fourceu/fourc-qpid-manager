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

#include <fourc/fmf/codec/DecodeException.h>
#include <fourc/fmf/codec/ResponsePropertyNames.h>
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
   * \brief Finds the requested value in the map
   * @param map
   * @param key
   * @param mandatory If true, will throw an exception if the key is not found in the map
   * @return
   */
  const VariantT getMapProperty(const MapT &map, const std::string& key, bool mandatory = false) const
                                                                         throw(codec::DecodeException) {

    auto itr = map.find(key);
    if (itr != map.end()) {
      return itr->second;
    } else {
      if (mandatory) {
        throw codec::DecodeException(boost::str(boost::format("Key '%s' not found in map") % key));
      }
      return VariantT();
    }
  }

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

  std::chrono::system_clock::time_point decodeTimestamp(const VariantT& value) const {
    return std::chrono::system_clock::time_point(std::chrono::nanoseconds(value.asInt64()));
  }

  void decodeTimestamps(std::shared_ptr<ObjectT>& object, const MapT& objectProperties) const {
    auto created = decodeTimestamp(getMapProperty(objectProperties, RPNs::CREATED));
    auto deleted = decodeTimestamp(getMapProperty(objectProperties, RPNs::DELETED));
    auto updated = decodeTimestamp(getMapProperty(objectProperties, RPNs::UPDATED));

    object->setTimeCreated(created)
        .setTimeDeleted(deleted)
        .setTimeUpdated(updated);
  }

  void decodeObjectId(std::shared_ptr<ObjectT>& object, const MapT& objectProperties) const {
    auto object_id_map = getMapProperty(objectProperties, RPNs::OBJECT_ID).asMap();
    
    std::string oid = getMapProperty(object_id_map, RPNs::OBJECT_NAME);
    int agentEpoch = getMapProperty(object_id_map, RPNs::OBJECT_AGENT_EPOCH).asInt32();

    ObjectId objectId;
    objectId.setName(oid)
        .setAgentEpoch(agentEpoch);

    object->setObjectId(objectId);
  }

  void decodeSchemaId(std::shared_ptr<ObjectT>& object, const MapT& objectProperties) const {
    auto schema_id_map = getMapProperty(objectProperties, RPNs::SCHEMA_ID).asMap();

    std::string class_name = getMapProperty(schema_id_map, ResponsePropertyNames::SCHEMA_CLASS_NAME);
    std::string package = getMapProperty(schema_id_map, ResponsePropertyNames::SCHEMA_PACKAGE_NAME);
    std::string hash = getMapProperty(schema_id_map, ResponsePropertyNames::SCHEMA_HASH);
    std::string type = getMapProperty(schema_id_map, ResponsePropertyNames::SCHEMA_TYPE);

    SchemaId schema_id;
    schema_id.setClassName(class_name)
        .setPackageName(package)
        .setHash(hash)
        .setType(type);

    object->setSchemaId(schema_id);
  }
};

}}} // Namespaces

#endif //FOURC_FMF_DECODER_H
