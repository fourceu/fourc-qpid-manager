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

class QueueTestsIT : public ::testing::Test {
public:
  QueueTestsIT() : brokerAgent(std::shared_ptr<qpid::messaging::Session>()) {
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

TEST_F(QueueTestsIT, testGetQueues) {
  auto queues = brokerAgent.getQueues();

  EXPECT_FALSE(queues.empty());
}

TEST_F(QueueTestsIT, testCreateQueue) {
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);
  auto type = Exchange::ExchangeType::DIRECT;

  brokerAgent.createExchange(type, uuid_str);

  auto exchange = brokerAgent.getExchange(uuid_str);

  ASSERT_TRUE(exchange);
  EXPECT_EQ(type, exchange->getExchangeType());
}

TEST_F(QueueTestsIT, testGetQueue) {
// No meaningful test here that isn't performed by testCreateQueue, since there are no default queues on the broker.
}

TEST_F(QueueTestsIT, testDeleteQueue) {
  // Create an queue then delete it, verifying existence at all stages
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);

  // Check no queue
  ASSERT_FALSE(brokerAgent.getQueue(uuid_str));

  brokerAgent.createQueue(uuid_str);

  // Check queue
  ASSERT_TRUE(brokerAgent.getQueue(uuid_str));

  brokerAgent.deleteQueue(uuid_str, true, true);

  // Check no queue
  ASSERT_FALSE(brokerAgent.getQueue(uuid_str));
}

TEST_F(QueueTestsIT, testDeleteNonexistentQueue) {
  // Verify a queue does not exist, then try to delete it
  boost::uuids::uuid uuid = uuid_generator();
  std::string uuid_str = boost::uuids::to_string(uuid);

  // Check no queue
  ASSERT_FALSE(brokerAgent.getQueue(uuid_str));

  EXPECT_THROW(brokerAgent.deleteQueue(uuid_str, true, true), BrokerAgentException);

  // Check no queue
  ASSERT_FALSE(brokerAgent.getQueue(uuid_str));
}