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

#ifndef FOURC_FMF_TRIVIALDECODER_H
#define FOURC_FMF_TRIVIALDECODER_H

#include "Decoder.h"
#include "DecodeException.h"

#include "fourc/fmf/Acl.h"

#include <boost/assign/list_of.hpp>

#include <map>

namespace fourc {
namespace fmf {

typedef void TrivialResponseType;

namespace codec {

/**
 * \brief A decoder that doesn't try to decode anything (useful for methods that don't return data)
 */
template<typename VariantT>
class TrivialDecoder : public Decoder<void, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  std::shared_ptr<void> decode(const MapT &) const {
    return std::shared_ptr<void>();
  }
};

}}} // Namespaces

#endif //FOURC_FMF_TRIVIALDECODER_H
