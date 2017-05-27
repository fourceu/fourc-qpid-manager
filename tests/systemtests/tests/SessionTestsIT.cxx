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

class SessionTestsIT : public ::testing::Test {
public:
  SessionTestsIT() : brokerAgent(session) {
    connection = qpid::messaging::Connection(SystemTestConfiguration::buildUrl(), SystemTestConfiguration::getConnectionOptions());
    connection.open();
    session = connection.createSession();
  }
protected:
  virtual void SetUp() {
    brokerAgent = BrokerAgent(session);
  }
  // Tears down the test fixture.
  virtual void TearDown() {
  }

  qpid::messaging::Connection connection;
  qpid::messaging::Session session;
  BrokerAgent brokerAgent;
};

TEST_F(SessionTestsIT, testGetSession) {
  // Since we don't know the name of an existing session, get a list of all sessions and then retrieve
  // the first session again, this by name
  auto sessions = brokerAgent.getSessions();
  ASSERT_FALSE(sessions.empty()) << "No sessions found.";

  auto session_name = sessions.front()->getName();

  // Now we have a session name, start the actual test!
  auto session = brokerAgent.getSession(session_name);

  ASSERT_TRUE(session);

  EXPECT_EQ(session_name, session->getName());
}

TEST_F(SessionTestsIT, testGetSessions) {
  auto sessions = brokerAgent.getSessions();

  EXPECT_FALSE(sessions.empty());
}
