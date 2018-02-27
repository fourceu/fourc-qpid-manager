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

#ifndef FOURC_QPID_MANAGER_LOGLEVELDECODER_H
#define FOURC_QPID_MANAGER_LOGLEVELDECODER_H

#include "../LogLevel.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class LogLevelDecoder : public Decoder<LogLevel, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_LEVEL;

  virtual ~LogLevelDecoder() = default;

  std::shared_ptr<LogLevel> decode(const MapT &objectProperties) const {
    auto decoded = std::make_shared<LogLevel>();
    auto arguments = ValueReader::get(objectProperties, RPNs::ARGUMENTS).asMap();
    decoded->setLevel(ValueReader::get(arguments, PROPERTY_NAME_LEVEL));

    return decoded;
  }
};
template<typename VariantT> const std::string LogLevelDecoder<VariantT>::PROPERTY_NAME_LEVEL = "level";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_LOGLEVELDECODER_H
