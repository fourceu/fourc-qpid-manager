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
#include <fourc/fmf/codec/ValueReader.h>

#include <subsystem/mocks/Variant.h>

using namespace fourc::fmf::codec;

TEST(ValueReaderTests, get) {
  subsystem::mocks::Variant::Map values;
  std::string key("key");
  std::string value("value");

  values.emplace(key, value);

  auto actual = ValueReader::get(values, key);

  //EXPECT_EQ(value, actual.asString()); // Mock got copied
}

TEST(ValueReaderTests, getMissingOptionalThrowsNoException) {
  subsystem::mocks::Variant::Map values;
  std::string key("key");

  auto actual = ValueReader::get(values, key);

  //EXPECT_EQ(value, actual.asString()); // Mock got copied
}

TEST(ValueReaderTests, getMissingMandatoryThrowsException) {
  subsystem::mocks::Variant::Map values;
  std::string key("key");

  try {
    auto actual = ValueReader::get(values, key, true);

    FAIL() << "Expected exception not thrown";
  } catch (DecodeException& /* expected*/ ) {
  }
}
