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

#include <fourc/fmf/ExchangeTypeDesc.h>

using namespace fourc::fmf;

TEST(ExchangeTypeDescTests, mapExchangeTypeDirect) {
  EXPECT_EQ("direct", ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType::DIRECT));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeTopic) {
  EXPECT_EQ("topic", ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType::TOPIC));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeFanout) {
  EXPECT_EQ("fanout", ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType::FANOUT));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeHeaders) {
  EXPECT_EQ("headers", ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType::HEADERS));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeXml) {
  EXPECT_EQ("xml", ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType::XML));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeOtherThrowsException) {
  EXPECT_THROW(ExchangeTypeDesc::getExchangeTypeDesc(Exchange::ExchangeType::OTHER), std::range_error);
}

TEST(ExchangeTypeDescTests, mapExchangeTypeDesc_Direct) {
  EXPECT_EQ(Exchange::ExchangeType::DIRECT, ExchangeTypeDesc::getExchangeType("direct"));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeDesc_Topic) {
  EXPECT_EQ(Exchange::ExchangeType::TOPIC, ExchangeTypeDesc::getExchangeType("topic"));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeDesc_Fanout) {
  EXPECT_EQ(Exchange::ExchangeType::FANOUT, ExchangeTypeDesc::getExchangeType("fanout"));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeDesc_Headers) {
  EXPECT_EQ(Exchange::ExchangeType::HEADERS, ExchangeTypeDesc::getExchangeType("headers"));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeDesc_Xml) {
  EXPECT_EQ(Exchange::ExchangeType::XML, ExchangeTypeDesc::getExchangeType("xml"));
}

TEST(ExchangeTypeDescTests, mapExchangeTypeDesc_Other) {
  EXPECT_EQ(Exchange::ExchangeType::OTHER, ExchangeTypeDesc::getExchangeType("other"));
}
