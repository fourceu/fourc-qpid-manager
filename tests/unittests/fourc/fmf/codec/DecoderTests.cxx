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
#include <fourc/fmf/codec/Decoder.h>

#include <subsystem/mocks/Variant.h>

using namespace fourc::fmf::codec;

using ::testing::A;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;

class TestObjectType {};

class TestDecoder : public Decoder<TestObjectType, subsystem::mocks::Variant> {
public:
  /**
   * \brief Implements this abstract method to allow instantiation of the class
   * @return
   */
  virtual std::shared_ptr<TestObjectType> decode(const subsystem::mocks::Variant::Map& ) const {
    throw std::runtime_error("This method doesn't need testing (it's a test method)");
  }

  subsystem::mocks::Variant getMapProperty(subsystem::mocks::Variant::Map& v, const std::string& key, bool mandatory = false) const
  throw(DecodeException) {
    return Decoder<TestObjectType, subsystem::mocks::Variant>::getMapProperty(v, key, mandatory);
  }
};

TEST(DecoderTests, ctor) {
  auto instance = new TestDecoder();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(DecoderTests, getMapProperty) {
  subsystem::mocks::Variant expected;
  subsystem::mocks::Variant::Map objectProperties;
  objectProperties[ResponsePropertyNames::VALUES] = expected;

  EXPECT_CALL(expected, equals(A<const subsystem::mocks::Variant&>())).Times(1).WillOnce(Return(true));

  TestDecoder decoder;

  EXPECT_EQ(expected, decoder.getMapProperty(objectProperties, ResponsePropertyNames::VALUES));
}

TEST(DecoderTests, getMapProperty_MissingOptionalValueThrowsDecodeException) {
  subsystem::mocks::Variant::Map objectProperties;

  TestDecoder decoder;

  decoder.getMapProperty(objectProperties, "test key");
}

TEST(DecoderTests, getMapProperty_MissingMandatoryValueThrowsDecodeException) {
  subsystem::mocks::Variant::Map objectProperties;

  TestDecoder decoder;

  EXPECT_THROW(decoder.getMapProperty(objectProperties, "test key", true), DecodeException);
}
