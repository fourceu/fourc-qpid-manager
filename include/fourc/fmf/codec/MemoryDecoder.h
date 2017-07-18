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

#ifndef FOURC_QPID_MANAGER_MEMORYDECODER_H
#define FOURC_QPID_MANAGER_MEMORYDECODER_H

#include "../Memory.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class MemoryDecoder : public Decoder<Memory, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_MALLOC_ARENA;
  static const std::string PROPERTY_NAME_MALLOC_FORDBLKS;
  static const std::string PROPERTY_NAME_MALLOC_HBLKHD;
  static const std::string PROPERTY_NAME_MALLOC_HBLKS;
  static const std::string PROPERTY_NAME_MALLOC_KEEPCOST;
  static const std::string PROPERTY_NAME_MALLOC_ORDBLKS;
  static const std::string PROPERTY_NAME_MALLOC_UORDBLKS;

  virtual ~MemoryDecoder() = default;

  std::shared_ptr<Memory> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = ValueReader::get(objectProperties, RPNs::VALUES, true).asMap();

    decoded->setMallocArena(ValueReader::get(values, PROPERTY_NAME_MALLOC_ARENA))
        .setMallocFordblks(ValueReader::get(values, PROPERTY_NAME_MALLOC_FORDBLKS))
        .setMallocHblkhd(ValueReader::get(values, PROPERTY_NAME_MALLOC_HBLKHD))
        .setMallocHblks(ValueReader::get(values, PROPERTY_NAME_MALLOC_HBLKS))
        .setMallocKeepcost(ValueReader::get(values, PROPERTY_NAME_MALLOC_KEEPCOST))
        .setMallocOrdblks(ValueReader::get(values, PROPERTY_NAME_MALLOC_ORDBLKS))
        .setMallocUordblks(ValueReader::get(values, PROPERTY_NAME_MALLOC_UORDBLKS))
        .setName(ValueReader::get(values, RPNs::NAME));

    return decoded;
  }
};

template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_ARENA = "malloc_arena";
template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_FORDBLKS = "malloc_fordblks";
template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_HBLKHD = "malloc_hblkhd";
template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_HBLKS = "malloc_hblks";
template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_KEEPCOST = "malloc_keepcost";
template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_ORDBLKS = "malloc_ordblks";
template<typename VariantT> const std::string MemoryDecoder<VariantT>::PROPERTY_NAME_MALLOC_UORDBLKS = "malloc_uordblks";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_MEMORYDECODER_H
