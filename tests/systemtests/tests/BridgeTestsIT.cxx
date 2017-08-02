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

class BridgeTestsIT : public ::testing::Test {
public:
  BridgeTestsIT() : brokerAgent(session) {
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

TEST_F(BridgeTestsIT, testClose) {
  // Before we can close a connection, we need to open one!
  std::string host = SystemTestConfiguration::getHost();
  int port = 5673;
  bool durable = false;
  std::string mech("EXTERNAL");
  std::string transport("ssl");
  std::string source("amq.direct");
  std::string dest("amq.direct");
  std::string key("key");
  std::string tag("tag");
  std::string excludes;
  bool src_queue = false;
  bool src_local = false;
  bool dynamic = false;
  uint16_t sync = 4;

  auto broker = brokerAgent.getBroker();

  broker->connect(brokerAgent, host, port, durable, mech, transport);

  auto links = brokerAgent.getLinks();
  ASSERT_FALSE(links.empty()) << "No links found on broker.";

  auto link = links.front();
  link->bridge(brokerAgent, source, dest, key, tag, excludes, src_queue, src_local, durable, dynamic, sync);

  // Now we should have a bridge to close
  auto bridge = brokerAgent.getSingleObject<Bridge>([&source, &dest, &key, src_local](const std::shared_ptr<Bridge>& bridge) {
      return bridge->getSrc() == source
             && bridge->getDest() == dest
             && bridge->getKey() == key
             && bridge->isSrcLocal() == src_local; });
  ASSERT_TRUE(bridge) << "Bridge creation failed.";
  bridge->closeOn(brokerAgent);

  // If we get the bridges again, the one we closed should not be present
  if (brokerAgent.getSingleObject<Bridge>([&source, &dest, &key, src_local](const std::shared_ptr<Bridge>& bridge) {
      return bridge->getSrc() == source
             && bridge->getDest() == dest
             && bridge->getKey() == key
             && bridge->isSrcLocal() == src_local; })) {
      FAIL() << "Bridge was not closed.";
  }
}
