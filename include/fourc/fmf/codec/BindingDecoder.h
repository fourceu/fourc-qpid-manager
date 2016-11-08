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

#ifndef FOURC_FMF_BINDINGDECODER_H
#define FOURC_FMF_BINDINGDECODER_H

#include "../Binding.h"
#include "Decoder.h"

#include <qpid/types/Variant.h> // InvalidConversion exception

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class BindingDecoder : public Decoder<Binding, VariantT> {
public:
  static const std::string PROPERTY_NAME_EXCHANGE_REF;
  static const std::string PROPERTY_NAME_QUEUE_REF;
  static const std::string PROPERTY_NAME_BINDING_KEY;
  static const std::string PROPERTY_NAME_MSG_MATCHED;

  typedef typename VariantT::Map MapT;

  virtual ~BindingDecoder() = default;

  std::shared_ptr<Binding> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();

    auto exchange_ref = this->getMapProperty(values, PROPERTY_NAME_EXCHANGE_REF);
    auto queue_ref = this->getMapProperty(values, PROPERTY_NAME_QUEUE_REF);

    decoded->setExchangeName(getObjectRefName(values, PROPERTY_NAME_EXCHANGE_REF))
        .setQueueName(getObjectRefName(values, PROPERTY_NAME_QUEUE_REF))
        .setBindingKey(this->getMapProperty(values, PROPERTY_NAME_BINDING_KEY))
        .setExchangeEpoch(getObjectRefEpoc(values, PROPERTY_NAME_EXCHANGE_REF))
        .setQueueEpoch(getObjectRefEpoc(values, PROPERTY_NAME_QUEUE_REF))
        .setMsgMatched(this->getMapProperty(values, PROPERTY_NAME_MSG_MATCHED));

    return decoded;
  }
protected:
  /**
   * \brief Reads the object name property from a sub-map of the given map. If the object name contains a colon,
   * all characters up to and including the last colon are erased.
   * Note: In the case of the default exchange, this will return an empty string.
   *
   * @param values
   * @param ref_key
   * @return
   */
  std::string getObjectRefName(const MapT& values, const std::string& ref_key) const {
    auto ref_map = this->getMapProperty(values, ref_key);

    std::string ref;
    try {
       ref = this->getMapProperty(ref_map.asMap(), RPNs::OBJECT_NAME).asString();

      auto itr = ref.rfind(':');
      if (itr != std::string::npos) {
        ref.erase(0, itr + 1);
      }

    } catch (qpid::types::InvalidConversion&) {
    }

    return ref;
  }

  /**
   * \brief Reads an agent epoch property from a sub-map of the given map.
   * @param values
   * @param ref_key
   * @return
   */
  int getObjectRefEpoc(const MapT& values, const std::string& ref_key) const {
    auto ref_map = this->getMapProperty(values, ref_key);

    return this->getMapProperty(ref_map.asMap(), RPNs::OBJECT_AGENT_EPOCH);
  }
};

template <typename VariantT> const std::string BindingDecoder<VariantT>::PROPERTY_NAME_EXCHANGE_REF = "exchangeRef";
template <typename VariantT> const std::string BindingDecoder<VariantT>::PROPERTY_NAME_QUEUE_REF = "queueRef";
template <typename VariantT> const std::string BindingDecoder<VariantT>::PROPERTY_NAME_BINDING_KEY = "bindingKey";
template <typename VariantT> const std::string BindingDecoder<VariantT>::PROPERTY_NAME_MSG_MATCHED = "msgMatched";

}}} // Namespaces

#endif //FOURC_FMF_BINDINGDECODER_H
