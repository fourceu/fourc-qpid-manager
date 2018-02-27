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

#ifndef FOURC_QPID_MANAGER_VALUEREADER_H
#define FOURC_QPID_MANAGER_VALUEREADER_H

#include "DecodeException.h"

#include <boost/format.hpp>

namespace fourc {
namespace fmf {

namespace codec {

/**
 * \brief Reads variants from an associative list
 */
class ValueReader {
public:
  /**
   * \brief Finds the requested value in the map
   * @param map
   * @param key
   * @param mandatory If true, will throw an exception if the key is not found in the map
   * @return
   */

  template<typename MapT>
  static const typename MapT::mapped_type get(const MapT &map, const typename MapT::key_type& key, bool mandatory = false) {
    auto itr = map.find(key);
    if (itr != map.end()) {
      return itr->second;
    } else {
      if (mandatory) {
        throw DecodeException(boost::str(boost::format("Key '%s' not found in map") % key));
      }
      return typename MapT::mapped_type();
    }
  }
};

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_VALUEREADER_H
