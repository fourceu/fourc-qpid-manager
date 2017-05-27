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

class MemoryTestsIT : public ::testing::Test {
public:
  MemoryTestsIT() : brokerAgent(session) {
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

TEST_F(MemoryTestsIT, testGetMemory) {
  auto memory = brokerAgent.getMemory();

  EXPECT_NE(0u, memory->getMallocArena());
  EXPECT_NE(0u, memory->getMallocFordblks());
//  EXPECT_NE(0u, memory->getMallocHblkhd()); // Seems this value is often zero
//  EXPECT_NE(0u, memory->getMallocHblks()); // Seems this value is often zero
  EXPECT_NE(0u, memory->getMallocKeepcost());
  EXPECT_NE(0u, memory->getMallocOrdblks());
  EXPECT_NE(0u, memory->getMallocUordblks());
  EXPECT_FALSE(memory->getName().empty());
}
