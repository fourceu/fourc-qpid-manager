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

#ifndef FOURC_FMF_ACLLOOKUPDECODER_H
#define FOURC_FMF_ACLLOOKUPDECODER_H

#include "Decoder.h"
#include "DecodeException.h"

#include <map>

namespace fourc {
namespace fmf {

typedef const std::string AclLookupType;

namespace codec {

template<typename VariantT>
class AclLookupDecoder : public Decoder<AclLookupType, VariantT> {
public:
  typedef typename VariantT::Map MapT;
  virtual ~AclLookupDecoder() = default;

  std::shared_ptr<AclLookupType> decode(const MapT &objectProperties) const {
    auto args = this->getMapProperty(objectProperties, "_arguments").asMap();
    return std::make_shared<AclLookupType>(this->getMapProperty(args, "result").asString());
  }
};

}}} // Namespaces

#endif //FOURC_FMF_ECHODECODER_H
