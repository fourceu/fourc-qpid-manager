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

#ifndef FOURC_FMF_RESPONSEDECODER_H
#define FOURC_FMF_RESPONSEDECODER_H

#include "ExceptionDecoder.h"

#include "DecoderTraits.h"

#include <iostream>

#include <string>
#include <forward_list>

namespace fourc {
namespace fmf {
namespace codec {

template<typename MessageT, typename ObjectType, typename VariantT>
class ResponseDecoder {
public:
  typedef decoder_traits<ObjectType, VariantT> DecoderTraits;

  ResponseDecoder() = default;

  /**
   * \brief Decodes all messages in a response and returns a collated list of all the responses.
   * @param response
   * @return
   */
  std::vector<std::shared_ptr<ObjectType>> decodeResponse(const std::vector<MessageT> &response) const {
    std::vector<std::shared_ptr<ObjectType>> nodes;
    for (MessageT message : response) {
      auto new_nodes = decodeResponseMessage(message);
      nodes.insert(
          nodes.end(),
          std::make_move_iterator(new_nodes.begin()),
          std::make_move_iterator(new_nodes.end())
      );
    }
    return nodes;
  }

protected:
  /**
   * \brief Verifies that the template object type matches the type specified
   * @param type
   */
  void verifyDecoderType(const std::string &type) const {
    // Verify codec node type matches the expected one
    if (ObjectType::OBJECT_TYPE_NAME != type) {
      throw std::logic_error(boost::str(
          boost::format("Declared object type '%s' does not match expected '%s'") % ObjectType::OBJECT_TYPE_NAME % type));
    }
  }

  std::shared_ptr<ObjectType> decodeObject(const VariantT &object) const {
    const auto &object_map = object.asMap();
    const auto &schema = object_map.at("_schema_id");
    const auto &type = schema.asMap().at("_class_name");

    // Verify that the data being decoded declares its type to be the same as our decoder
    verifyDecoderType(type.asString());

    return typename DecoderTraits::DecoderType().decode(object_map);
  }

  const std::vector<std::shared_ptr<ObjectType>> decodeQueryResponse(const MessageT &message) const {
    // Decode the message content to a list of variants
    typename VariantT::List response_list = message.getContentObject().asList();

    std::vector<std::shared_ptr<ObjectType>> objects;
    for (auto &response : response_list) {
      objects.push_back(decodeObject(response));
    }
    return objects;
  }

  const std::vector<std::shared_ptr<ObjectType>> decodeResponseMessage(const MessageT &message) const {
    std::vector<std::shared_ptr<ObjectType>> objects;

    std::string opcode = message.getProperties().at("qmf.opcode");
    if (opcode == "_exception") {
      throw ExceptionDecoder<MessageT>().decodeException(message);
    } else if (opcode == "_query_response") {
      objects = decodeQueryResponse(message);
    } else if (opcode == "_method_response") {
      throw DecodeException("Don't use ResponseDecoder to decode method responses - use decoder_traits directly instead");
    } else {
      throw DecodeException(boost::str(boost::format("Failed to decode response: %s") % message.getContent()));
    }

    return objects;
  }
};

}}} // Namespaces

#endif //FOURC_FMF_RESPONSEDECODER_H
