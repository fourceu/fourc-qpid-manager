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

#include "Decoder.h"


#ifndef FOURC_QPID_MANAGER_METHODRESULTDECODER_H
#define FOURC_QPID_MANAGER_METHODRESULTDECODER_H

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class MethodResultDecoder : public Decoder<Link, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_ARGUMENTS;

  virtual ~MethodResultDecoder() = default;

  std::shared_ptr<MethodResult> decode(const MapT &objectProperties) const {
    auto args = ValueReader::get(objectProperties, PROPERTY_NAME_ARGUMENTS, true).asMap();

//    if (args.empty()) {
//      std::cout << "Empty" << std::endl;
//    }
//    std::for_each (args.begin(), args.end(), [](const typename MapT::value_type& pair) { std::cout << pair.first << std::endl;});

    return std::make_shared<MethodResult>();
  }
};

template <typename VariantT> const std::string MethodResultDecoder<VariantT>::PROPERTY_NAME_ARGUMENTS = "_arguments";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_METHODRESULTDECODER_H
