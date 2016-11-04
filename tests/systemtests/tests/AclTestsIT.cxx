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

class AclTestsIT : public ::testing::Test {
public:
  AclTestsIT() : brokerAgent(std::shared_ptr<qpid::messaging::Session>()) {
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
};

TEST_F(AclTestsIT, testGetAcl) {
  auto acl = brokerAgent.getAcl();

  EXPECT_TRUE(acl);
}

TEST_F(AclTestsIT, testAclLookup) {
  std::string user = "Arthur";
  std::string action = "access";
  std::string acl_obj = "exchange";
  std::string acl_obj_name = "amq.direct";
  qpid::types::Variant::Map props;

  auto result = brokerAgent.aclLookup(user, action, acl_obj, acl_obj_name, props);

  EXPECT_FALSE(result.empty());
}

TEST_F(AclTestsIT, testAclLookupPublish) {
  std::string user;
  std::string exchange;
  std::string key;

  auto result = brokerAgent.aclLookupPublish(user, exchange, key);

  EXPECT_FALSE(result.empty());
}

TEST_F(AclTestsIT, testReloadACL) {
  brokerAgent.reloadACLFile();
}