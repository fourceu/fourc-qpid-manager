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
#include <boost/uuid/uuid_generators.hpp>

using namespace fourc::fmf;
using namespace fourc::testing;

class BrokerAgentTests : public ::testing::Test {
public:
  BrokerAgentTests() : brokerAgent(std::shared_ptr<qpid::messaging::Session>()) {
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


TEST_F(BrokerAgentTests, testEcho) {
  int sequence = 42;
  std::string body = "lies";

  auto response = brokerAgent.echo(sequence, body);
  int seq_resp;
  std::string body_resp;

  std::tie(seq_resp, body_resp) = *response.get();

  EXPECT_EQ(sequence, seq_resp);
  EXPECT_EQ(body, body_resp);
}

TEST_F(BrokerAgentTests, testPartialResponses) {
  // Qmf breaks long responses into messages of max 100 records, which need to be concatenated
  // in the client to form the full list. Test this here by creating a few hundred exchanges
  // and verifying the list length and contents after querying for the exchange list.

  size_t NUM_EXCHANGES = 201; // should get us 3 messages in the response
  auto exchangeType = Exchange::ExchangeType::DIRECT;

  std::forward_list<std::string> createdExchanges;
  for (size_t i = 0; i < NUM_EXCHANGES; i++) {
    boost::uuids::uuid uuid = uuid_generator();
    std::string exchange_name = boost::uuids::to_string(uuid);
    createdExchanges.push_front(exchange_name);

    brokerAgent.createExchange(exchangeType, exchange_name);
  }

  auto exchanges = brokerAgent.getExchanges();
  EXPECT_TRUE(exchanges.size() > NUM_EXCHANGES); // There will always be more exchanges than we created (defaults etc)

  // Check that all the exchanges we created are in the list
  std::string errors;
  for (auto exchangeName : createdExchanges) {
    bool found = false;
    for (auto& exchange : exchanges) {
      if (exchange->getName() == exchangeName) {
        found = true;
        break;
      }
    }

    if (!found) {
      errors += boost::str(boost::format("Exchange not found: %s\n") % exchangeName);
    }

    // Might as well try to clean up a bit
    brokerAgent.deleteExchange(exchangeName);
  }
  if (!errors.empty()) {
    FAIL() << errors;
  }
}
