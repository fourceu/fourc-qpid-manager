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

#include <gmock/gmock.h>
#include <fourc/fmf/codec/AclDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestAclDecoder_VariantReferenceMap : public AclDecoder<subsystem::mocks::ReferenceVariant> {
public:
};

TEST(AclDecoderTests, ctor) {
  auto instance = new AclDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(AclDecoderTests, dynamicCast) {
  auto instance = new AclDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Acl, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(AclDecoderTests, decodeAcl) {
  auto now_ts = std::chrono::system_clock::from_time_t(time(nullptr)); // Base on C time (which is lower resolution than system_clock::now())
  auto zero_ts = std::chrono::system_clock::from_time_t(0);
  std::string oid = "oid";
  int agent_epoch = 10;

  std::string schema_class = "acl";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.acl";
  std::string schema_type = "_data";

  uint32_t acl_deny = 1;
  uint32_t conn_deny = 2;
  uint32_t max_conn = 3;
  uint32_t max_conn_ip = 4;
  uint32_t max_conn_user = 5;
  uint32_t max_queue_user = 6;
  uint32_t queue_quota_deny = 7;
  bool enforcing = false;
  bool transfer = false;
  auto last_load = std::chrono::system_clock::now();
  std::string broker_ref = "org.apache.qpid.broker:broker:amqp-broker";
  std::string policy_file = "/var/lib/qpidd/ some path/acl";

  qpid::types::Variant::Map object_id = {
      { ResponsePropertyNames::OBJECT_NAME, oid },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, agent_epoch }
  };

  qpid::types::Variant::Map schema_id = {
      { ResponsePropertyNames::SCHEMA_CLASS_NAME, schema_class },
      { ResponsePropertyNames::SCHEMA_HASH, schema_hash },
      { ResponsePropertyNames::SCHEMA_PACKAGE_NAME, schema_package_name },
      { ResponsePropertyNames::SCHEMA_TYPE, schema_type },
  };

  qpid::types::Variant::Map broker_ref_map = {
      { ResponsePropertyNames::OBJECT_NAME, broker_ref }
  };

  qpid::types::Variant::Map values = {
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_ACL_DENY_COUNT, acl_deny },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_CONNECTION_DENY_COUNT, conn_deny },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_MAX_CONNECTIONS, max_conn },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_MAX_CONNECTIONS_IP, max_conn_ip },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_MAX_CONNECTIONS_USER, max_conn_user },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_MAX_QUEUES_USER, max_queue_user },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_QUEUE_QUOTA_DENY_COUNT, queue_quota_deny },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_ENFORCING_ACL, enforcing },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_TRANSFER_ACL, transfer },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_LAST_ACL_LOAD, last_load.time_since_epoch().count() },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_BROKER_REF, broker_ref_map },
      { AclDecoder<qpid::types::Variant>::PROPERTY_NAME_POLICY_FILE, policy_file }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, std::chrono::system_clock::to_time_t(now_ts) },
      { ResponsePropertyNames::DELETED, std::chrono::system_clock::to_time_t(zero_ts) },
      { ResponsePropertyNames::UPDATED, std::chrono::system_clock::to_time_t(zero_ts) },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  AclDecoder<qpid::types::Variant> decoder;

  auto acl = decoder.decode(objectProperties);

  EXPECT_TRUE(acl);

  EXPECT_EQ(now_ts, acl->getTimeCreated());
  EXPECT_EQ(zero_ts, acl->getTimeDeleted());
  EXPECT_EQ(zero_ts, acl->getTimeUpdated());

  EXPECT_EQ(oid, acl->getObjectId().getName());
  EXPECT_EQ(agent_epoch, acl->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, acl->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, acl->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, acl->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, acl->getSchemaId().getType());

  EXPECT_EQ(acl_deny, acl->getAclDenyCount());
  EXPECT_EQ(conn_deny, acl->getConnectionDenyCount());
  EXPECT_EQ(max_conn, acl->getMaxConnections());
  EXPECT_EQ(max_conn_ip, acl->getMaxConnectionsPerIp());
  EXPECT_EQ(max_conn_user, acl->getMaxConnectionsPerUser());
  EXPECT_EQ(max_queue_user, acl->getMaxQueuesPerUser());
  EXPECT_EQ(queue_quota_deny, acl->getQueueQuotaDenyCount());
  EXPECT_EQ(enforcing, acl->isEnforcingAcl());
  EXPECT_EQ(transfer, acl->isTransferAcl());
  EXPECT_EQ(last_load, acl->getLastAclLoad());
  EXPECT_EQ(policy_file, acl->getPolicyFile());
  EXPECT_EQ(broker_ref, acl->getBrokerRef());
}
