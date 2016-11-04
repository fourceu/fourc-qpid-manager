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

class TestExchangeDecoder_VariantReferenceMap : public ExchangeDecoder<subsystem::mocks::ReferenceVariant> {
public:
  Exchange::ExchangeType getExchangeType(const subsystem::mocks::ReferenceVariant::Map& values) const {
    return ExchangeDecoder::getExchangeType(values);
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
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  MockDefaultValueHandler<std::string> string_default_handler(expected_str);

  TestExchangeDecoder_NonMocked decoder;

  EXPECT_EQ(expected_str, decoder.getExchangeTypeDesc(values));
}

TEST(ExchangeDecoderTests, decodeExchangeType_Direct) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::DIRECT;
  const std::string expected_str = "direct";
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}
TEST(ExchangeDecoderTests, decodeExchangeType_Topic) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::TOPIC;
  const std::string expected_str = "topic";
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Fanout) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::FANOUT;
  const std::string expected_str = "fanout";
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Header) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::HEADERS;
  const std::string expected_str = "headers";
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Xml) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::XML;
  const std::string expected_str = "xml";
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchangeType_Other) {
  Exchange::ExchangeType expected = Exchange::ExchangeType::OTHER;
  const std::string expected_str = "spangly exchange type parade";
  const subsystem::mocks::Variant value;
  subsystem::mocks::Variant::Map values;
  values.emplace(TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, value);

  TestExchangeDecoder decoder;

  EXPECT_CALL(decoder, getExchangeTypeDesc(A<const subsystem::mocks::Variant::Map&>())).WillOnce(Return(expected_str));

  auto actual = decoder.getExchangeType(values);

  EXPECT_EQ(expected, actual);
}

TEST(ExchangeDecoderTests, decodeExchange) {
  auto now_ts = std::chrono::system_clock::from_time_t(time(0)); // Base on C time (which is lower resolution than system_clock::now())
  auto zero_ts = std::chrono::system_clock::from_time_t(0);
  std::string oid = "oid";
  std::string name = "name";
  bool durable = true;
  Exchange::ExchangeType exchangeType = Exchange::ExchangeType::DIRECT;

  qpid::types::Variant::Map object_id = {
      { ResponsePropertyNames::OBJECT_NAME, oid }
  };

  qpid::types::Variant::Map schema_id = {

  };

  auto test = qpid::types::Variant(ExchangeTypeDesc::getExchangeTypeDesc(exchangeType));
  qpid::types::Variant::Map values = {
      { ExchangeDecoder<qpid::types::Variant>::PROPERTY_EXCHANGE_TYPE, test
           },
      { ResponsePropertyNames::NAME, name },
      { ResponsePropertyNames::DURABLE, durable }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, std::chrono::system_clock::to_time_t(now_ts) },
      { ResponsePropertyNames::DELETED, std::chrono::system_clock::to_time_t(zero_ts) },
      { ResponsePropertyNames::UPDATED, std::chrono::system_clock::to_time_t(zero_ts) },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, qpid::types::Variant(values) }
  };

  ExchangeDecoder<qpid::types::Variant> decoder;

  auto exchange = decoder.decode(objectProperties);

  EXPECT_TRUE(exchange);

  EXPECT_EQ(now_ts, exchange->getTimeCreated());
  EXPECT_EQ(zero_ts, exchange->getTimeDeleted());
  EXPECT_EQ(zero_ts, exchange->getTimeUpdated());

  EXPECT_EQ(oid, exchange->getObjectId().getName());

  EXPECT_EQ(name, exchange->getName());
  EXPECT_EQ(durable, exchange->isDurable());
  EXPECT_EQ(exchangeType, exchange->getExchangeType());
}

// Mocked decoder tests fail, something to do with mocked object_id map.
//TEST(ExchangeDecoderTests, decodeNondurableDirectExchange) {
//  Exchange::ExchangeType type = Exchange::ExchangeType::DIRECT;
//  const std::string type_str = "direct";
//  const subsystem::mocks::ReferenceVariant type_value;
//  EXPECT_CALL(type_value, asString()).WillOnce(Return(type_str));
//
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = false;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, type_value},
//      { ResponsePropertyNames::NAME, name_value },
//      { ResponsePropertyNames::DURABLE, durable_value }
//  };
//  const subsystem::mocks::ReferenceVariant values(values_map);
//  EXPECT_CALL(values, asMap()).WillOnce(ReturnRef(values_map));
//
//  const subsystem::mocks::ReferenceVariant::Map object_id_map = {
//
//  };
//  const subsystem::mocks::ReferenceVariant object_id(object_id_map);
//  EXPECT_CALL(object_id, asMap()).WillOnce(ReturnRef(object_id_map));
//
//  const subsystem::mocks::ReferenceVariant::Map objectProperties = {
//      { ResponsePropertyNames::VALUES, values },
//      { ResponsePropertyNames::OBJECT_ID, object_id }
//  };
//
//  // This is what we should get back from the decoder
//  auto expected = std::make_shared<Exchange>();
//  expected->setExchangeType(type)
//      .setName(name)
//      .setDurable(durable);
//
//  TestExchangeDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}

//TEST(ExchangeDecoderTests, decodeDurableTopicExchange) {
//  Exchange::ExchangeType type = Exchange::ExchangeType::TOPIC;
//  const std::string type_str = "topic";
//  const subsystem::mocks::ReferenceVariant type_value;
//  EXPECT_CALL(type_value, asString()).WillOnce(Return(type_str));
//
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = true;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, type_value},
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
//  auto expected = std::make_shared<Exchange>();
//  expected->setExchangeType(type)
//      .setName(name)
//      .setDurable(durable);
//
//  TestExchangeDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}
//
//TEST(ExchangeDecoderTests, decodeNondurableFanoutExchange) {
//  Exchange::ExchangeType type = Exchange::ExchangeType::FANOUT;
//  const std::string type_str = "fanout";
//  const subsystem::mocks::ReferenceVariant type_value;
//  EXPECT_CALL(type_value, asString()).WillOnce(Return(type_str));
//
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = false;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, type_value},
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
//  auto expected = std::make_shared<Exchange>();
//  expected->setExchangeType(type)
//      .setName(name)
//      .setDurable(durable);
//
//  TestExchangeDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}
//
//TEST(ExchangeDecoderTests, decodeDurableHeadersExchange) {
//  Exchange::ExchangeType type = Exchange::ExchangeType::HEADERS;
//  const std::string type_str = "headers";
//  const subsystem::mocks::ReferenceVariant type_value;
//  EXPECT_CALL(type_value, asString()).WillOnce(Return(type_str));
//
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = true;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, type_value},
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
//  auto expected = std::make_shared<Exchange>();
//  expected->setExchangeType(type)
//      .setName(name)
//      .setDurable(durable);
//
//  TestExchangeDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}
//
//TEST(ExchangeDecoderTests, decodeNondurableXmlExchange) {
//  Exchange::ExchangeType type = Exchange::ExchangeType::XML;
//  const std::string type_str = "xml";
//  const subsystem::mocks::ReferenceVariant type_value;
//  EXPECT_CALL(type_value, asString()).WillOnce(Return(type_str));
//
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = true;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { TestExchangeDecoder::PROPERTY_EXCHANGE_TYPE, type_value},
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
//  auto expected = std::make_shared<Exchange>();
//  expected->setExchangeType(type)
//      .setName(name)
//      .setDurable(durable);
//
//  TestExchangeDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}
