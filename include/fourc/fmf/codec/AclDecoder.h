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

#ifndef FOURC_FMF_ACLDECODER_H
#define FOURC_FMF_ACLDECODER_H

#include "Decoder.h"
#include "DecodeException.h"

#include "fourc/fmf/Acl.h"

#include <boost/assign/list_of.hpp>

#include <map>

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class AclDecoder : public Decoder<Acl, VariantT> {
public:
  static const std::string PROPERTY_NAME_ACL_DENY_COUNT;
  static const std::string PROPERTY_NAME_CONNECTION_DENY_COUNT;
  static const std::string PROPERTY_NAME_QUEUE_QUOTA_DENY_COUNT;
  static const std::string PROPERTY_NAME_MAX_CONNECTIONS;
  static const std::string PROPERTY_NAME_MAX_CONNECTIONS_IP;
  static const std::string PROPERTY_NAME_MAX_CONNECTIONS_USER;
  static const std::string PROPERTY_NAME_MAX_QUEUES_USER;
  static const std::string PROPERTY_NAME_ENFORCING_ACL;
  static const std::string PROPERTY_NAME_TRANSFER_ACL;
  static const std::string PROPERTY_NAME_BROKER_REF;
  static const std::string PROPERTY_NAME_POLICY_FILE;
  static const std::string PROPERTY_NAME_LAST_ACL_LOAD;
  
  typedef typename VariantT::Map MapT;
  
  virtual ~AclDecoder() = default;

  std::shared_ptr<Acl> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();

    auto broker_ref_map = this->getMapProperty(values, PROPERTY_NAME_BROKER_REF).asMap();
    std::string broker_ref = this->getMapProperty(broker_ref_map, ResponsePropertyNames::OBJECT_NAME);

    decoded->setAclDenyCount(this->getMapProperty(values, PROPERTY_NAME_ACL_DENY_COUNT))
        .setConnectionDenyCount(this->getMapProperty(values, PROPERTY_NAME_CONNECTION_DENY_COUNT))
        .setQueueQuotaDenyCount(this->getMapProperty(values, PROPERTY_NAME_QUEUE_QUOTA_DENY_COUNT))
        .setMaxConnections(this->getMapProperty(values, PROPERTY_NAME_MAX_CONNECTIONS))
        .setMaxConnectionsPerIp(this->getMapProperty(values, PROPERTY_NAME_MAX_CONNECTIONS_IP))
        .setMaxConnectionsPerUser(this->getMapProperty(values, PROPERTY_NAME_MAX_CONNECTIONS_USER))
        .setMaxQueuesPerUser(this->getMapProperty(values, PROPERTY_NAME_MAX_QUEUES_USER))
        .setIsEnforcingAcl(this->getMapProperty(values, PROPERTY_NAME_ENFORCING_ACL))
        .setIsTransferAcl(this->getMapProperty(values, PROPERTY_NAME_TRANSFER_ACL))
        .setLastAclLoad(std::chrono::system_clock::time_point(std::chrono::nanoseconds(this->getMapProperty(values, PROPERTY_NAME_LAST_ACL_LOAD))))
        .setPolicyFile(this->getMapProperty(values, PROPERTY_NAME_POLICY_FILE))
        .setBrokerRef(broker_ref);

    return decoded;
  }
};

template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_ACL_DENY_COUNT = "aclDenyCount";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_CONNECTION_DENY_COUNT = "connectionDenyCount";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_QUEUE_QUOTA_DENY_COUNT = "queueQuotaDenyCount";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_MAX_CONNECTIONS = "maxConnections";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_MAX_CONNECTIONS_IP = "maxConnectionsPerIp";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_MAX_CONNECTIONS_USER = "maxConnectionsPerUser";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_MAX_QUEUES_USER = "maxQueuesPerUser";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_ENFORCING_ACL = "enforcingAcl";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_TRANSFER_ACL = "transferAcl";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_BROKER_REF = "brokerRef";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_POLICY_FILE = "policyFile";
template <typename VariantT> const std::string AclDecoder<VariantT>::PROPERTY_NAME_LAST_ACL_LOAD = "lastAclLoad";

}}} // Namespaces

#endif //FOURC_FMF_ACLDECODER_H
