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
#include <fourc/fmf/RouteManager.h>

#include <SystemTestConfiguration.h>

#include <qpid/messaging/Connection.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace fourc::fmf;
using namespace fourc::testing;

class RouteManagerTestsIT : public ::testing::Test {
public:
  RouteManagerTestsIT() : brokerAgent(session) {
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

  std::shared_ptr<Bridge> findBridge(const std::string& src, const std::string& dest, const std::string key, const bool src_local) {
    return brokerAgent.getSingleObject<Bridge>([&src, &dest, &key, src_local](const std::shared_ptr<Bridge>& bridge) {
        return bridge->getSrc() == src
                && bridge->getDest() == dest
                && bridge->getKey() == key
                && bridge->isSrcLocal() == src_local;
    });
  }

  qpid::messaging::Connection connection;
  qpid::messaging::Session session;
  BrokerAgent brokerAgent;
};

TEST_F(RouteManagerTestsIT, addAndRemoveRoute) {
  std::string host = SystemTestConfiguration::getHost();
  int port = 5673;
  bool durable = false;
  std::string mech("EXTERNAL");
  std::string transport("ssl");
  std::string user("");
  std::string pass("");
  std::string exchange("amq.direct-addAndRemoveRoute");
  std::string key("key");
  std::string tag("tag");
  std::string excludes;
  bool src_local = false;
  bool dynamic = false;
  uint16_t sync = 4;

  RouteManager<BrokerAgent> routeManager(brokerAgent);

  routeManager.addRoute(host, port, mech, transport, user, pass, exchange, exchange, key, tag, excludes, dynamic, src_local, durable, sync);

  EXPECT_TRUE(findBridge(exchange, exchange, key, src_local));

  routeManager.delRoute(host, port, transport, exchange, exchange, key, src_local, dynamic, true);

  EXPECT_FALSE(findBridge(exchange, exchange, key, src_local));
}

TEST_F(RouteManagerTestsIT, addAndRemoveQueueRoute) {
  std::string host = SystemTestConfiguration::getHost();
  int port = 5673;
  bool durable = false;
  std::string mech("EXTERNAL");
  std::string transport("ssl");
  std::string user("");
  std::string pass("");
  std::string queue("test-queue-addAndRemoveQueueRoute");
  std::string exchange("amq.direct-addAndRemoveQueueRoute");
  std::string tag("tag");
  std::string excludes;
  bool src_local = false;
  uint16_t sync = 4;

  RouteManager<BrokerAgent> routeManager(brokerAgent);

  routeManager.addQueueRoute(host, port, mech, transport, user, pass, queue, exchange, src_local, durable, sync);

  EXPECT_TRUE(findBridge(queue, exchange, "", src_local));

  routeManager.delQueueRoute(host, port, transport, queue, exchange, src_local, true);

  EXPECT_FALSE(findBridge(queue, exchange, "", src_local));
}
