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
#include <fourc/fmf/codec/BindingDecoder.h>

#include <qpid/types/Variant.h>
#include <subsystem/mocks/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestBindingDecoder : public BindingDecoder<qpid::types::Variant> {
public:
  std::string getObjectRefName_test(const MapT& values, const std::string& ref_key) const {
    return BindingDecoder<qpid::types::Variant>::getObjectRefName(values, ref_key);
  }

  int getObjectRefEpoc(const MapT& values, const std::string& ref_key) const {
    return BindingDecoder<qpid::types::Variant>::getObjectRefEpoc(values, ref_key);
  }
};

TEST(BindingDecoderTests, ctor) {
  auto instance = new BindingDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BindingDecoderTests, dynamicCast) {
  auto instance = new BindingDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Binding, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(BindingDecoderTests, getObjectRefName_empty_map) {
  qpid::types::Variant::Map values;

  TestBindingDecoder decoder;
  decoder.getObjectRefName_test(values, TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF);
}

TEST(BindingDecoderTests, getObjectRefName_empty_nested_map) {
  qpid::types::Variant::Map properties = {
  };
  qpid::types::Variant::Map values = {
      { TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF, properties }
  };

  TestBindingDecoder decoder;
  decoder.getObjectRefName_test(values, TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF);
}

TEST(BindingDecoderTests, getObjectRefName_empty_name) {
  qpid::types::Variant::Map properties = {
      { ResponsePropertyNames::OBJECT_NAME, qpid::types::Variant("") }
  };
  qpid::types::Variant::Map values = {
      { TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF, properties }
  };

  TestBindingDecoder decoder;
  decoder.getObjectRefName_test(values, TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF);
}

TEST(BindingDecoderTests, getObjectRefName_no_colons) {
  std::string expected = "simple_name";
  qpid::types::Variant::Map properties = {
      { ResponsePropertyNames::OBJECT_NAME, expected }
  };
  qpid::types::Variant::Map values = {
      { TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF, properties }
  };

  TestBindingDecoder decoder;
  std::string actual = decoder.getObjectRefName_test(values, TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF);

  EXPECT_EQ(expected, actual);
}

TEST(BindingDecoderTests, getObjectRefName_parses_colons) {
  std::string expected = "simple_name";
  std::string full_name =  "this bit: should be: deleted:" + expected;
  qpid::types::Variant::Map properties = {
      { ResponsePropertyNames::OBJECT_NAME, full_name }
  };
  qpid::types::Variant::Map values = {
      { TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF, properties }
  };

  TestBindingDecoder decoder;
  std::string actual = decoder.getObjectRefName_test(values, TestBindingDecoder::PROPERTY_NAME_EXCHANGE_REF);

  EXPECT_EQ(expected, actual);
}

TEST(BindingDecoderTests, decodeBinding) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  int agent_epoch = 10;

  std::string schema_class = "binding";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.binding";
  std::string schema_type = "_data";

  std::string exchange_name = "exc name";
  std::string queue_name = "queue name";
  std::string binding_key = "binding key";
  int exchange_epoch = 3;
  int queue_epoch = 4;
  int msg_matched = 9;

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

  qpid::types::Variant::Map exchange_ref_map = {
      { ResponsePropertyNames::OBJECT_NAME, exchange_name },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, exchange_epoch }
  };

  qpid::types::Variant::Map queue_ref_map = {
      { ResponsePropertyNames::OBJECT_NAME, queue_name },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, queue_epoch }
  };

  qpid::types::Variant::Map values = {
      { BindingDecoder<qpid::types::Variant>::PROPERTY_NAME_EXCHANGE_REF, exchange_ref_map },
      { BindingDecoder<qpid::types::Variant>::PROPERTY_NAME_QUEUE_REF, queue_ref_map },
      { BindingDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_KEY, binding_key },
      { BindingDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_MATCHED, msg_matched }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, now_tp.time_since_epoch().count() },
      { ResponsePropertyNames::DELETED, 0 },
      { ResponsePropertyNames::UPDATED, 0 },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  BindingDecoder<qpid::types::Variant> decoder;

  auto binding = decoder.decode(objectProperties);

  EXPECT_TRUE(binding);

  EXPECT_EQ(now_tp, binding->getTimeCreated());
  EXPECT_EQ(0, binding->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, binding->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, binding->getObjectId().getName());
  EXPECT_EQ(agent_epoch, binding->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, binding->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, binding->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, binding->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, binding->getSchemaId().getType());

  EXPECT_EQ(exchange_name, binding->getExchangeName());
  EXPECT_EQ(queue_name, binding->getQueueName());
  EXPECT_EQ(binding_key, binding->getBindingKey());
  EXPECT_EQ(exchange_epoch, binding->getExchangeEpoch());
  EXPECT_EQ(queue_epoch, binding->getQueueEpoch());
  EXPECT_EQ(msg_matched, binding->getMsgMatched());
}
