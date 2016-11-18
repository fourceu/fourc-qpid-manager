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

#ifndef FOURC_QPID_MANAGER_EXCEPTIONDECODER_H
#define FOURC_QPID_MANAGER_EXCEPTIONDECODER_H

#include "../RPCException.h"

#include <sstream>

namespace fourc {
namespace fmf {
namespace codec {

template <typename MessageT>
class ExceptionDecoder {
public:
  RPCException decodeException(const MessageT &message) const {
    int code = -1;
    std::string text;

    auto& response = message.getContentObject().asMap();
    auto itr = response.find("_values");
    if (itr == response.end()) {
      std::stringstream ss;
      ss << response;
      text = "An exception was returned from the RPC interface but no further information could be decoded from the response:"
          + ss.str();
    } else {
      auto values = itr->second.asMap();

      try {
        code = values.at("error_code").asInt32();
      } catch (std::out_of_range&) {}
      try  {
        text = values.at("error_text").asString();
      } catch (std::out_of_range&) {
        std::stringstream ss;
        ss << response;
        text = "An exception was returned from the RPC interface but no description could be decoded from the response:"
          + ss.str();
      }
    }

    return RPCException(code, text);
  }
};

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_EXCEPTIONDECODER_H
