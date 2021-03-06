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
#include <fourc/fmf/codec/ExchangeDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <MockDefaultValueHandler.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::A;

class TestExchangeDecoder : public ExchangeDecoder<subsystem::mocks::Variant> {
public:
  Exchange::ExchangeType getExchangeType(const subsystem::mocks::Variant::Map& values) const {
    return ExchangeDecoder::getExchangeType(values);
  }
  MOCK_CONST_METHOD1(getExchangeTypeDesc, std::string(const subsystem::mocks::Variant::Map&));
};

class TestExchangeDecoder_NonMocked : public ExchangeDecoder<subsystem::mocks::Variant> {
public:
  Exchange::ExchangeType getExchangeType(const subsystem::mocks::Variant::Map& values) const {
    return ExchangeDecoder::getExchangeType(values);
  }

  virtual std::string getExchangeTypeDesc(const subsystem::mocks::Variant::Map& values) const {
    return ExchangeDecoder::getExchangeTypeDesc(values);
  }
};

TEST(ExchangeDecoderTests, ctor) {
  auto instance = new ExchangeDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(ExchangeDecoderTests, dynamicCast) {
  auto instance = new ExchangeDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Exchange, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(ExchangeDecoderTests, decodeExchangeTypeDesc) {
  const std::string expected_str = "test type";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  MockDefaultValueHandler<std::string> string_default_handler(expected_str);

  TestExchangeDecoder_NonMocked decoder;

  EXPECT_EQ(expected_str, decoder.getExchangeTypeDesc(values));
}

TEST(ExchangeDecoderTests, decodeExchangeType_Direct) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::DIRECT;
  const std::string expected_str = "direct";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}
TEST(ExchangeDecoderTests, decodeExchangeType_Topic) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::TOPIC;
  const std::string expected_str = "topic";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Fanout) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::FANOUT;
  const std::string expected_str = "fanout";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Header) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::HEADERS;
  const std::string expected_str = "headers";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Xml) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::XML;
  const std::string expected_str = "xml";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Other) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::OTHER;
  const std::string expected_str = "spangly exchange type parade";
  subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_NAME_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchange) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  uint64_t agent_epoch = 10;

  std::string schema_class = "exchange";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.exchange";
  std::string schema_type = "_data";

  bool auto_delete = true;
  uint32_t binding_count = 1;
  uint32_t binding_count_high = 2;
  uint32_t binding_count_low = 3;
  uint64_t byte_drops = 4;
  uint64_t byte_receives = 5;
  uint64_t byte_routes = 6;
  bool durable = true;
  uint64_t msg_drops = 7;
  uint64_t msg_receives = 8;
  uint64_t msg_routes = 9;
  std::string name = "exchange name";
  uint32_t producer_count = 10;
  uint32_t producer_count_high = 11;
  uint32_t producer_count_low = 12;
  Exchange::ExchangeType exchange_type = Exchange::ExchangeType::TOPIC;
  std::string vhost_ref = "vhost ref";

  qpid::types::Variant::Map object_id = {
      { RPNs::OBJECT_NAME, oid },
      { RPNs::OBJECT_AGENT_EPOCH, agent_epoch }
  };

  qpid::types::Variant::Map schema_id = {
      { RPNs::SCHEMA_CLASS_NAME, schema_class },
      { RPNs::SCHEMA_HASH, schema_hash },
      { RPNs::SCHEMA_PACKAGE_NAME, schema_package_name },
      { RPNs::SCHEMA_TYPE, schema_type },
  };

  qpid::types::Variant::Map vhost_ref_map = {
      { RPNs::OBJECT_NAME, vhost_ref }
  };

  qpid::types::Variant::Map values = {
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_AUTODELETE, auto_delete },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_COUNT, binding_count },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_COUNT_HIGH, binding_count_high },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_COUNT_LOW, binding_count_low },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_DROPS, byte_drops },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_RECEIVES, byte_receives },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_ROUTES, byte_routes },
      { RPNs::DURABLE, durable },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_DROPS, msg_drops },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_RECEIVES, msg_receives },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_ROUTES, msg_routes },
      { RPNs::NAME, name },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_PRODUCER_COUNT, producer_count },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_PRODUCER_COUNT_HIGH, producer_count_high },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_PRODUCER_COUNT_LOW, producer_count_low },
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_NAME_EXCHANGE_TYPE, ExchangeTypeDesc::getExchangeTypeDesc(exchange_type) },
      { RPNs::VHOST_REF, vhost_ref_map }
  };

  qpid::types::Variant::Map objectProperties = {
      { RPNs::CREATED, now_tp.time_since_epoch().count() },
      { RPNs::DELETED, 0 },
      { RPNs::UPDATED, 0 },
      { RPNs::OBJECT_ID, object_id },
      { RPNs::SCHEMA_ID, schema_id },
      { RPNs::VALUES, values }
  };

  ExchangeDecoder<qpid::types::Variant> decoder;

  auto exchange = decoder.decode(objectProperties);

  EXPECT_TRUE(exchange);

  EXPECT_EQ(now_tp, exchange->getTimeCreated());
  EXPECT_EQ(0, exchange->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, exchange->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, exchange->getObjectId().getName());
  EXPECT_EQ(agent_epoch, exchange->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, exchange->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, exchange->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, exchange->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, exchange->getSchemaId().getType());

  EXPECT_EQ(auto_delete, exchange->isAutoDelete());
  EXPECT_EQ(binding_count, exchange->getBindingCount());
  EXPECT_EQ(binding_count_high, exchange->getBindingCountHigh());
  EXPECT_EQ(binding_count_low, exchange->getBindingCountLow());
  EXPECT_EQ(byte_drops, exchange->getByteDrops());
  EXPECT_EQ(byte_receives, exchange->getByteReceives());
  EXPECT_EQ(byte_routes, exchange->getByteRoutes());
  EXPECT_EQ(durable, exchange->isDurable());
  EXPECT_EQ(msg_drops, exchange->getMsgDrops());
  EXPECT_EQ(msg_receives, exchange->getMsgReceives());
  EXPECT_EQ(msg_routes, exchange->getMsgRoutes());
  EXPECT_EQ(name, exchange->getName());
  EXPECT_EQ(producer_count, exchange->getProducerCount());
  EXPECT_EQ(producer_count_high, exchange->getProducerCountHigh());
  EXPECT_EQ(producer_count_low, exchange->getProducerCountLow());
  EXPECT_EQ(exchange_type, exchange->getExchangeType());
  EXPECT_EQ(vhost_ref, exchange->getVhostRef());
}
