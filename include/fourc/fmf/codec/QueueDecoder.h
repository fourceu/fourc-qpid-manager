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

#ifndef FOURC_FMF_QUEUEDECODER_H
#define FOURC_FMF_QUEUEDECODER_H

#include "../Queue.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class QueueDecoder : public Decoder<Queue, VariantT> {
public:
  typedef typename VariantT::Map MapT;
  virtual ~QueueDecoder() = default;

  std::shared_ptr<Queue> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();

    decoded->setName(this->getMapProperty(values, RPNs::NAME))
        .setDurable(this->getMapProperty(values, RPNs::DURABLE));

    return decoded;
  }
};

}}} // Namespaces

#endif //FOURC_FMF_QUEUEDECODER_H
