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

#include <gtest/gtest.h>
#include <fourc/fmf/BrokerAgent.h>

#include <SystemTestConfiguration.h>

#include <qpid/messaging/Connection.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace fourc::fmf;
using namespace fourc::testing;

class ExchangeTestsIT : public ::testing::Test {
public:
  ExchangeTestsIT() : brokerAgent(std::shared_ptr<qpid::messaging::Session>()) {
    connection = qpid::messaging::Connection(SystemTestConfiguration::buildUrl(), SystemTestConfiguration::getConnectionOptions());
    connection.open();
    session = connection.createSession();
    session_ptr = std::shared_ptr<qpid::messaging::Session>(&session, [](qpid::messaging::Session*&){});
  }
protected:
  virtual void SetUp() {
    brokerAgent = BrokerAgent(session_ptr);
  }
  // Tears down the test fixture.
  virtual void TearDown() {
  }

  qpid::messaging::Connection connection;
  qpid::messaging::Session session;
  std::shared_ptr<qpid::messaging::Session> session_ptr;
  BrokerAgent brokerAgent;
  boost::uuids::random_generator uuid_generator;
};

TEST_F(ExchangeTestsIT, testGetExchange) {
  ASSERT_TRUE(brokerAgent.getExchange("amq.direct")); // Default exchange should always exist
}

TEST_F(ExchangeTestsIT, testGetExchanges) {
  auto exchanges = brokerAgent.getExchanges();

  EXPECT_FALSE(exchanges.empty());
}

TEST_F(ExchangeTestsIT, testCreateDirectExchange) {
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);
  auto type = Exchange::ExchangeType::DIRECT;

  brokerAgent.createExchange(type, uuid_str);

  auto exchange = brokerAgent.getExchange(uuid_str);

  ASSERT_TRUE(exchange);
  EXPECT_EQ(type, exchange->getExchangeType());
}

TEST_F(ExchangeTestsIT, testCreateTopicExchange) {
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);
  auto type = Exchange::ExchangeType::TOPIC;

  brokerAgent.createExchange(type, uuid_str);

  auto exchange = brokerAgent.getExchange(uuid_str);

  ASSERT_TRUE(exchange);
  EXPECT_EQ(type, exchange->getExchangeType());
}

TEST_F(ExchangeTestsIT, testCreateFanoutExchange) {
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);
  auto type = Exchange::ExchangeType::FANOUT;

  brokerAgent.createExchange(type, uuid_str);

  auto exchange = brokerAgent.getExchange(uuid_str);

  ASSERT_TRUE(exchange);
  EXPECT_EQ(type, exchange->getExchangeType());
}

TEST_F(ExchangeTestsIT, testCreateHeadersExchange) {
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);
  auto type = Exchange::ExchangeType::HEADERS;

  brokerAgent.createExchange(type, uuid_str);

  auto exchange = brokerAgent.getExchange(uuid_str);

  ASSERT_TRUE(exchange);
  EXPECT_EQ(type, exchange->getExchangeType());
}

// Broker must be compiled with XML support, which makes this test unreliable
//TEST_F(ExchangeTestsIT, testCreateXmlExchange) {
//  boost::uuids::uuid uuid = uuid_generator();
//  std::string uuid_str = boost::uuids::to_string(uuid);
//  auto type = Exchange::ExchangeType::XML;
//
//  brokerAgent.createExchange(type, uuid_str);
//
//  auto exchange = brokerAgent.getExchange(uuid_str);
//
//  ASSERT_TRUE(exchange);
//  EXPECT_EQ(type, exchange->getExchangeType());
//}

TEST_F(ExchangeTestsIT, testDeleteExchange) {
  // Create an exchange then delete it, verifying existence at all stages
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);
  auto type = Exchange::ExchangeType::DIRECT;

  // Check no exchange
  ASSERT_FALSE(brokerAgent.getExchange(uuid_str));

  brokerAgent.createExchange(type, uuid_str);

  // Check exchange
  ASSERT_TRUE(brokerAgent.getExchange(uuid_str));

  brokerAgent.deleteExchange(uuid_str);

  // Check no exchange
  ASSERT_FALSE(brokerAgent.getExchange(uuid_str));
}

TEST_F(ExchangeTestsIT, testDeleteNonexistentExchange) {
  // Verify an exchange does not exist, then try to delete it
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);

  // Check no exchange
  ASSERT_FALSE(brokerAgent.getExchange(uuid_str));

  EXPECT_THROW(brokerAgent.deleteExchange(uuid_str), BrokerAgentException);

  // Check no exchange
  ASSERT_FALSE(brokerAgent.getExchange(uuid_str));
}