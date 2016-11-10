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

#ifndef FOURC_QPID_MANAGER_SUBSCRIPTIONDECODER_H
#define FOURC_QPID_MANAGER_SUBSCRIPTIONDECODER_H

#include "../Subscription.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class SubscriptionDecoder : public Decoder<Subscription, VariantT> {
public:
  typedef typename VariantT::Map MapT;
  
  static const std::string PROPERTY_NAME_ACKNOWLEDGED;
  static const std::string PROPERTY_NAME_BROWSING;
  static const std::string PROPERTY_NAME_CREDIT_MODE;
  static const std::string PROPERTY_NAME_DELIVERED;
  static const std::string PROPERTY_NAME_EXCLUSIVE;
  static const std::string PROPERTY_NAME_QUEUE_REF;
  static const std::string PROPERTY_NAME_SESSION_REF;
  
  virtual ~SubscriptionDecoder() = default;

  std::shared_ptr<Subscription> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();

    auto queue_ref_map = this->getMapProperty(values, PROPERTY_NAME_QUEUE_REF, true).asMap();
    auto session_ref_map = this->getMapProperty(values, PROPERTY_NAME_SESSION_REF, true).asMap();

    decoded->setAcknowledged(this->getMapProperty(values, PROPERTY_NAME_ACKNOWLEDGED))
        .setBrowsing(this->getMapProperty(values, PROPERTY_NAME_BROWSING))
        .setCreditMode(this->getMapProperty(values, PROPERTY_NAME_CREDIT_MODE))
        .setDelivered(this->getMapProperty(values, PROPERTY_NAME_DELIVERED))
        .setExclusive(this->getMapProperty(values, PROPERTY_NAME_EXCLUSIVE))
        .setName(this->getMapProperty(values, RPNs::NAME))
        .setQueueEpoch(this->getMapProperty(queue_ref_map, RPNs::OBJECT_AGENT_EPOCH))
        .setQueueName(this->getMapProperty(queue_ref_map, RPNs::OBJECT_NAME))
        .setSessionEpoch(this->getMapProperty(session_ref_map, RPNs::OBJECT_AGENT_EPOCH))
        .setSessionName(this->getMapProperty(session_ref_map, RPNs::OBJECT_NAME));

    return decoded;
  }
};

template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_ACKNOWLEDGED = "acknowledged";
template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_BROWSING = "browsing";
template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_CREDIT_MODE = "creditMode";
template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_DELIVERED = "delivered";
template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_EXCLUSIVE = "exclusive";
template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_QUEUE_REF = "queueRef";
template <typename VariantT> const std::string SubscriptionDecoder<VariantT>::PROPERTY_NAME_SESSION_REF = "sessionRef";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_SUBSCRIPTIONDECODER_H
