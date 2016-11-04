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

#ifndef FOURC_QPID_MANAGER_LINKDECODER_H
#define FOURC_QPID_MANAGER_LINKDECODER_H

#include "../Link.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class LinkDecoder : public Decoder<Link, VariantT> {
public:
  typedef typename VariantT::Map MapT;
  virtual ~LinkDecoder() = default;

  std::shared_ptr<Link> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto &values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();
    // Lots more properties we could apply here

    int i = values.size();
    i = i;

    return decoded;
  }
};

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_LINKDECODER_H
