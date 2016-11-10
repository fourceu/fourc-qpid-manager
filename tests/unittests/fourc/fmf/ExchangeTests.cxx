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

TEST(ExchangeTests, ctorSetsAutoDelete) {
  Exchange exchange;

  EXPECT_FALSE(exchange.isAutoDelete());
}

TEST(ExchangeTests, ctorSetsBindingCount) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getBindingCount());
}

TEST(ExchangeTests, ctorSetsBindingCountHigh) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getBindingCountHigh());
}

TEST(ExchangeTests, ctorSetsBindingCountLow) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getBindingCountLow());
}

TEST(ExchangeTests, ctorSetsByteDrops) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getByteDrops());
}

TEST(ExchangeTests, ctorSetsByteReceives) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getByteReceives());
}

TEST(ExchangeTests, ctorSetsByteRoutes) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getByteRoutes());
}

TEST(ExchangeTests, ctorSetsDurable) {
  Exchange exchange;

  EXPECT_FALSE(exchange.isDurable());
}

TEST(ExchangeTests, ctorSetsMsgDrops) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getMsgDrops());
}

TEST(ExchangeTests, ctorSetsMsgReceives) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getMsgReceives());
}

TEST(ExchangeTests, ctorSetsMsgRoutes) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getMsgRoutes());
}

TEST(ExchangeTests, ctorSetsName) {
  Exchange exchange;
  
  EXPECT_TRUE(exchange.getName().empty());
}

TEST(ExchangeTests, ctorSetsProducerCount) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getProducerCount());
}

TEST(ExchangeTests, ctorSetsProducerCountHigh) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getProducerCountHigh());
}

TEST(ExchangeTests, ctorSetsProducerCountLow) {
  Exchange exchange;

  EXPECT_EQ(0u, exchange.getProducerCountLow());
}

TEST(ExchangeTests, ctorSetsExchangeType) {
  Exchange exchange;

  EXPECT_EQ(Exchange::ExchangeType::DIRECT, exchange.getExchangeType());
}

TEST(ExchangeTests, ctorSetsVhostRef) {
  Exchange exchange;
  
  EXPECT_TRUE(exchange.getVhostRef().empty());
}

// ***********************

TEST(ExchangeTests, setAutoDelete) {
  bool expected = true;
  Exchange exchange;

  EXPECT_NE(expected, exchange.isAutoDelete());
  exchange.setIsAutoDelete(expected);

  EXPECT_EQ(expected, exchange.isAutoDelete());
}

TEST(ExchangeTests, setBindingCount) {
  uint32_t expected = 5;
  Exchange exchange;
  exchange.setBindingCount(expected);

  EXPECT_EQ(expected, exchange.getBindingCount());
}

TEST(ExchangeTests, setBindingCountHigh) {
  uint32_t expected = 6;
  Exchange exchange;
  exchange.setBindingCountHigh(expected);

  EXPECT_EQ(expected, exchange.getBindingCountHigh());
}

TEST(ExchangeTests, setBindingCountLow) {
  uint32_t expected = 4;
  Exchange exchange;
  exchange.setBindingCountLow(expected);

  EXPECT_EQ(expected, exchange.getBindingCountLow());
}

TEST(ExchangeTests, setByteDrops) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setByteDrops(expected);

  EXPECT_EQ(expected, exchange.getByteDrops());
}

TEST(ExchangeTests, setByteReceives) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setByteReceives(expected);

  EXPECT_EQ(expected, exchange.getByteReceives());
}

TEST(ExchangeTests, setByteRoutes) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setByteRoutes(expected);

  EXPECT_EQ(expected, exchange.getByteRoutes());
}

TEST(ExchangeTests, setDurable) {
  bool expected = true;
  Exchange exchange;

  EXPECT_NE(expected, exchange.isDurable());
  exchange.setDurable(expected);

  EXPECT_EQ(expected, exchange.isDurable());
}

TEST(ExchangeTests, setMsgDrops) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setMsgDrops(expected);

  EXPECT_EQ(expected, exchange.getMsgDrops());
}

TEST(ExchangeTests, setMsgReceives) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setMsgReceives(expected);

  EXPECT_EQ(expected, exchange.getMsgReceives());
}

TEST(ExchangeTests, setMsgRoutes) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setMsgRoutes(expected);

  EXPECT_EQ(expected, exchange.getMsgRoutes());
}

TEST(ExchangeTests, setName) {
  std::string expected = "expected name";
  Exchange exchange;
  exchange.setName(expected);

  EXPECT_EQ(expected, exchange.getName());
}

TEST(ExchangeTests, setProducerCount) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setProducerCount(expected);

  EXPECT_EQ(expected, exchange.getProducerCount());
}

TEST(ExchangeTests, setProducerCountHigh) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setProducerCountHigh(expected);

  EXPECT_EQ(expected, exchange.getProducerCountHigh());
}

TEST(ExchangeTests, setProducerCountLow) {
  uint64_t expected = 17;
  Exchange exchange;
  exchange.setProducerCountLow(expected);

  EXPECT_EQ(expected, exchange.getProducerCountLow());
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

TEST(ExchangeTests, setVhostRef) {
  std::string expected = "test vhost";
  Exchange exchange;
  exchange.setVhostRef(expected);

  EXPECT_EQ(expected, exchange.getVhostRef());
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
