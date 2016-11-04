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

class BindingTestsIT : public ::testing::Test {
public:
  BindingTestsIT() : brokerAgent(std::shared_ptr<qpid::messaging::Session>()) {
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

TEST_F(BindingTestsIT, testGetBindings) {
  auto bindings = brokerAgent.getBindings();

  EXPECT_FALSE(bindings.empty()); // Hopefully there are some default bindings?
}

TEST_F(BindingTestsIT, testBind) {
  // Create an exchange and a queue, and in the darkness bind them
  boost::uuids::uuid uuid = uuid_generator();
  std::string exchange_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string queue_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string binding_key = boost::uuids::to_string(uuid);


  brokerAgent.createExchange(Exchange::ExchangeType::TOPIC, exchange_name);
  ASSERT_TRUE(brokerAgent.getExchange(exchange_name));
  brokerAgent.createQueue(queue_name);
  ASSERT_TRUE(brokerAgent.getQueue(queue_name));

  brokerAgent.bind(exchange_name, queue_name, binding_key);
}

TEST_F(BindingTestsIT, testBindNonexistentQueue) {
  // Same thing, no queue
  boost::uuids::uuid uuid = uuid_generator();
  std::string exchange_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string queue_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string binding_key = boost::uuids::to_string(uuid);

  brokerAgent.createExchange(Exchange::ExchangeType::TOPIC, exchange_name);
  ASSERT_TRUE(brokerAgent.getExchange(exchange_name));
  ASSERT_FALSE(brokerAgent.getQueue(queue_name));

  EXPECT_THROW(brokerAgent.bind(exchange_name, queue_name, binding_key), RPCException);
}

TEST_F(BindingTestsIT, testBindNonexistentExchange) {
  // Same thing, no exchange
  boost::uuids::uuid uuid = uuid_generator();
  std::string exchange_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string queue_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string binding_key = boost::uuids::to_string(uuid);

  ASSERT_FALSE(brokerAgent.getExchange(exchange_name));
  brokerAgent.createQueue(queue_name);
  ASSERT_TRUE(brokerAgent.getQueue(queue_name));

  EXPECT_THROW(brokerAgent.bind(exchange_name, queue_name, binding_key), RPCException);
}

TEST_F(BindingTestsIT, testUnbind) {
  // Create an exchange and a queue, bind and then unbind them
  boost::uuids::uuid uuid = uuid_generator();
  std::string exchange_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string queue_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string binding_key = boost::uuids::to_string(uuid);


  brokerAgent.createExchange(Exchange::ExchangeType::TOPIC, exchange_name);
  ASSERT_TRUE(brokerAgent.getExchange(exchange_name));
  brokerAgent.createQueue(queue_name);
  ASSERT_TRUE(brokerAgent.getQueue(queue_name));

  brokerAgent.bind(exchange_name, queue_name, binding_key);

  // Verify result here

  brokerAgent.unbind(exchange_name, queue_name, binding_key);
  // Verify result here
}

TEST_F(BindingTestsIT, testUnbindNonexistentBinding) {
  // Same thing, no exchange
  boost::uuids::uuid uuid = uuid_generator();
  std::string exchange_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string queue_name = boost::uuids::to_string(uuid);
  uuid = uuid_generator();
  std::string binding_key = boost::uuids::to_string(uuid);

  ASSERT_FALSE(brokerAgent.getExchange(exchange_name));

  EXPECT_THROW(brokerAgent.unbind(exchange_name, queue_name, binding_key), BrokerAgentException);
}
