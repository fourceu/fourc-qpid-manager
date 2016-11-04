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
#include <fourc/fmf/Exchange.h>

using namespace fourc::fmf;

TEST(ExchangeTests, ctor) {
  auto instance = new Exchange();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(ExchangeTests, ctorSetsDefaultDurableFalse) {
  Exchange exchange;

  EXPECT_FALSE(exchange.isDurable());
}

TEST(ExchangeTests, ctorSetsDefaultExchangeTypeDirect) {
  Exchange exchange;

  EXPECT_EQ(Exchange::ExchangeType::DIRECT, exchange.getExchangeType());
}

TEST(ExchangeTests, setName) {
  std::string expected = "expected name";

  Exchange exchange;
  exchange.setName(expected);

  EXPECT_EQ(expected, exchange.getName());
}

TEST(ExchangeTests, setDurableFalse) {
  Exchange exchange;
  exchange.setDurable(true);
  exchange.setDurable(false);

  EXPECT_FALSE(exchange.isDurable());
}

TEST(ExchangeTests, setDurableTrue) {
  Exchange exchange;
  exchange.setDurable(true);

  EXPECT_TRUE(exchange.isDurable());
}

TEST(ExchangeTests, setExchangeType_Direct) {
  Exchange::ExchangeType expected(Exchange::ExchangeType::DIRECT);

  Exchange exchange;
  exchange.setExchangeType(expected);

  EXPECT_EQ(expected, exchange.getExchangeType());
}

TEST(ExchangeTests, setExchangeType_Topic) {
  Exchange::ExchangeType expected(Exchange::ExchangeType::TOPIC);

  Exchange exchange;
  exchange.setExchangeType(expected);

  EXPECT_EQ(expected, exchange.getExchangeType());
}

TEST(ExchangeTests, setExchangeType_Fanout) {
  Exchange::ExchangeType expected(Exchange::ExchangeType::FANOUT);

  Exchange exchange;
  exchange.setExchangeType(expected);

  EXPECT_EQ(expected, exchange.getExchangeType());
}

TEST(ExchangeTests, setExchangeType_Header) {
  Exchange::ExchangeType expected(Exchange::ExchangeType::HEADERS);

  Exchange exchange;
  exchange.setExchangeType(expected);

  EXPECT_EQ(expected, exchange.getExchangeType());
}

TEST(ExchangeTests, setExchangeType_Xml) {
  Exchange::ExchangeType expected(Exchange::ExchangeType::XML);

  Exchange exchange;
  exchange.setExchangeType(expected);

  EXPECT_EQ(expected, exchange.getExchangeType());
}

TEST(ExchangeTests, setExchangeType_Other) {
  Exchange::ExchangeType expected(Exchange::ExchangeType::OTHER);

  Exchange exchange;
  exchange.setExchangeType(expected);

  EXPECT_EQ(expected, exchange.getExchangeType());
}

TEST(ExchangeTests, operatorEquals_SameInstance) {
  Exchange node1;
  auto& node2(node1);

  EXPECT_EQ(node1, node2);
}

TEST(ExchangeTests, operatorEquals_CopiedInstance) {
  Exchange node1;
  Exchange node2 = node1;

  EXPECT_EQ(node1, node2);
}

TEST(ExchangeTests, operatorEquals_CopyConstructedInstance) {
  Exchange node1;
  Exchange node2(node1);

  EXPECT_EQ(node1, node2);
}

TEST(ExchangeTests, operatorEqualsFalse_DifferentName) {
  Exchange node1;
  Exchange node2;
  node2.setName("something else");

  EXPECT_FALSE(node1 == node2);
}

TEST(ExchangeTests, operatorEqualsFalse_DifferentExchangeType) {
  Exchange node1;
  Exchange node2;
  node2.setExchangeType(Exchange::ExchangeType::FANOUT);

  EXPECT_FALSE(node1 == node2);
}

TEST(ExchangeTests, operatorEqualsFalse_DifferentDurability) {
  Exchange node1;
  Exchange node2;
  node2.setDurable(true);

  EXPECT_FALSE(node1 == node2);
}
