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
#include <fourc/fmf/codec/SubscriptionDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestSubscriptionDecoder_VariantReferenceMap : public SubscriptionDecoder<subsystem::mocks::ReferenceVariant> {
public:
};

TEST(SubscriptionDecoderTests, ctor) {
  auto instance = new SubscriptionDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(SubscriptionDecoderTests, dynamicCast) {
  auto instance = new SubscriptionDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Subscription, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(SubscriptionDecoderTests, decodeSubscription) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  int agent_epoch = 10;

  std::string schema_class = "subscription";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.subscription";
  std::string schema_type = "_data";

  
  bool acknowledged = true;
  bool browsing = true;
  std::string credit_mode = "test credit mode";
  uint64_t delivered = 1;
  bool exclusive = true;
  std::string name = "test name";
  uint32_t queue_epoch = 2;
  std::string queue_name = "test queue name";
  uint32_t session_epoch = 3;
  std::string session_name = "test session name";


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

  qpid::types::Variant::Map queue_ref_map = {
      { ResponsePropertyNames::OBJECT_NAME, queue_name },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, queue_epoch }
  };
  
  qpid::types::Variant::Map session_ref_map = {
      { ResponsePropertyNames::OBJECT_NAME, session_name },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, session_epoch }
  };

  qpid::types::Variant::Map values = {
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_ACKNOWLEDGED, acknowledged },
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_BROWSING, browsing },
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_CREDIT_MODE, credit_mode },
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_DELIVERED, delivered },
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_EXCLUSIVE, exclusive },
      { RPNs::NAME, name },
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_QUEUE_REF, queue_ref_map },
      { SubscriptionDecoder<qpid::types::Variant>::PROPERTY_NAME_SESSION_REF, session_ref_map }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, now_tp.time_since_epoch().count() },
      { ResponsePropertyNames::DELETED, 0 },
      { ResponsePropertyNames::UPDATED, 0 },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  SubscriptionDecoder<qpid::types::Variant> decoder;

  auto subscription = decoder.decode(objectProperties);

  EXPECT_TRUE(subscription);

  EXPECT_EQ(now_tp, subscription->getTimeCreated());
  EXPECT_EQ(0, subscription->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, subscription->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, subscription->getObjectId().getName());
  EXPECT_EQ(agent_epoch, subscription->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, subscription->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, subscription->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, subscription->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, subscription->getSchemaId().getType());

  EXPECT_EQ(acknowledged, subscription->isAcknowledged());
  EXPECT_EQ(browsing, subscription->isBrowsing());
  EXPECT_EQ(credit_mode, subscription->getCreditMode());
  EXPECT_EQ(delivered, subscription->getDelivered());
  EXPECT_EQ(exclusive, subscription->isExclusive());
  EXPECT_EQ(name, subscription->getName());
  EXPECT_EQ(queue_epoch, subscription->getQueueEpoch());
  EXPECT_EQ(queue_name, subscription->getQueueName());
  EXPECT_EQ(session_epoch, subscription->getSessionEpoch());
  EXPECT_EQ(session_name, subscription->getSessionName());
}
