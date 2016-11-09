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
#include <fourc/fmf/codec/QueueDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestQueueDecoder_VariantReferenceMap : public QueueDecoder<subsystem::mocks::ReferenceVariant> {
public:
};

TEST(QueueDecoderTests, ctor) {
  auto instance = new QueueDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(QueueDecoderTests, dynamicCast) {
  auto instance = new QueueDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Queue, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(QueueDecoderTests, decodeQueue) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  std::string name = "name";
  bool durable = true;

  qpid::types::Variant::Map object_id = {
      { ResponsePropertyNames::OBJECT_NAME, oid }
  };

  qpid::types::Variant::Map schema_id = {

  };

  qpid::types::Variant::Map values = {
      { ResponsePropertyNames::NAME, name },
      { ResponsePropertyNames::DURABLE, durable }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, now_tp.time_since_epoch().count() },
      { ResponsePropertyNames::DELETED, 0 },
      { ResponsePropertyNames::UPDATED, 0 },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  QueueDecoder<qpid::types::Variant> decoder;

  auto queue = decoder.decode(objectProperties);

  EXPECT_TRUE(queue);

  EXPECT_EQ(now_tp, queue->getTimeCreated());
  EXPECT_EQ(0, queue->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, queue->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, queue->getObjectId().getName());

  EXPECT_EQ(name, queue->getName());
  EXPECT_EQ(durable, queue->isDurable());
}


// Problems with mocking maps
//TEST(QueueDecoderTests, decodeDurableQueue) {
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = true;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { ResponsePropertyNames::NAME, name_value },
//      { ResponsePropertyNames::DURABLE, durable_value }
//  };
//  const subsystem::mocks::ReferenceVariant values(values_map);
//  EXPECT_CALL(values, asMap()).WillOnce(ReturnRef(values_map));
//
//  const subsystem::mocks::ReferenceVariant::Map objectProperties = {
//      { ResponsePropertyNames::VALUES, values }
//  };
//
//  // This is what we should get back from the codec
//  auto expected = std::make_shared<Queue>();
//
//  TestQueueDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}
//
//TEST(QueueDecoderTests, decodeNondurableQueue) {
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = false;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { ResponsePropertyNames::NAME, name_value },
//      { ResponsePropertyNames::DURABLE, durable_value }
//  };
//  const subsystem::mocks::ReferenceVariant values(values_map);
//  EXPECT_CALL(values, asMap()).WillOnce(ReturnRef(values_map));
//
//  const subsystem::mocks::ReferenceVariant::Map objectProperties = {
//      { ResponsePropertyNames::VALUES, values }
//  };
//
//  // This is what we should get back from the codec
//  auto expected = std::make_shared<Queue>();
//
//  TestQueueDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}