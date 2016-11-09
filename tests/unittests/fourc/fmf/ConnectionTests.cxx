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
#include <fourc/fmf/Connection.h>

using namespace fourc::fmf;

TEST(ConnectionTests, ctor) {
  auto instance = new Connection();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(ConnectionTests, ctorSetsSystemConnection) {
  Connection connection;

  EXPECT_FALSE(connection.isSystemConnection());
}

TEST(ConnectionTests, ctorSetsAddress) {
  Connection connection;

  EXPECT_TRUE(connection.getAddress().empty());
}

TEST(ConnectionTests, ctorSetsAuthIdentity) {
  Connection connection;

  EXPECT_TRUE(connection.getAuthIdentity().empty());
}

TEST(ConnectionTests, ctorSetsBytesFromClient) {
  Connection connection;

  EXPECT_EQ(0u, connection.getBytesFromClient());
}

TEST(ConnectionTests, ctorSetsBytesToClient) {
  Connection connection;

  EXPECT_EQ(0u, connection.getBytesToClient());
}

TEST(ConnectionTests, ctorSetsClosing) {
  Connection connection;

  EXPECT_FALSE(connection.isClosing());
}

TEST(ConnectionTests, ctorSetsFederationLink) {
  Connection connection;

  EXPECT_FALSE(connection.isFederationLink());
}

TEST(ConnectionTests, ctorSetsFramesFromClient) {
  Connection connection;

  EXPECT_EQ(0u, connection.getFramesFromClient());
}

TEST(ConnectionTests, ctorSetsFramesToClient) {
  Connection connection;

  EXPECT_EQ(0u, connection.getFramesToClient());
}

TEST(ConnectionTests, ctorSetsIncoming) {
  Connection connection;

  EXPECT_FALSE(connection.isIncoming());
}

TEST(ConnectionTests, ctorSetsMessagesFromClient) {
  Connection connection;

  EXPECT_EQ(0u, connection.getMsgsFromClient());
}

TEST(ConnectionTests, ctorSetsMessagesToClient) {
  Connection connection;

  EXPECT_EQ(0u, connection.getMsgsToClient());
}

TEST(ConnectionTests, ctorSetsProtocol) {
  Connection connection;

  EXPECT_TRUE(connection.getProtocol().empty());
}

TEST(ConnectionTests, ctorSetsRemotePid) {
  Connection connection;

  EXPECT_EQ(0u, connection.getRemotePid());
}

TEST(ConnectionTests, ctorSetsRemoteParentPid) {
  Connection connection;

  EXPECT_EQ(0u, connection.getRemoteParentPid());
}

TEST(ConnectionTests, ctorSetsRemoteProcessName) {
  Connection connection;

  EXPECT_TRUE(connection.getRemoteProcessName().empty());
}

TEST(ConnectionTests, ctorSetsSaslMechanism) {
  Connection connection;

  EXPECT_TRUE(connection.getSaslMechanism().empty());
}

TEST(ConnectionTests, ctorSetsVhostRef) {
  Connection connection;

  EXPECT_TRUE(connection.getVhostRef().empty());
}

TEST(ConnectionTests, ctorSetsSaslSsf) {
  Connection connection;

  EXPECT_EQ(0u, connection.getSaslSsf());
}

TEST(ConnectionTests, ctorSetsShadow) {
  Connection connection;

  EXPECT_FALSE(connection.isShadow());
}

TEST(ConnectionTests, ctorSetsUserProxyAuth) {
  Connection connection;

  EXPECT_FALSE(connection.isUserProxyAuth());
}

// ***********************

TEST(ConnectionTests, setSystemConnection) {
  bool expected = true;
  Connection connection;

  EXPECT_NE(expected, connection.isSystemConnection());
  connection.setSystemConnection(expected);

  EXPECT_EQ(expected, connection.isSystemConnection());
}

TEST(ConnectionTests, setAddress) {
  std::string expected = "address";
  Connection connection;
  connection.setAddress(expected);

  EXPECT_EQ(expected, connection.getAddress());
}

TEST(ConnectionTests, setAuthIdentity) {
  std::string expected = "authid";
  Connection connection;
  connection.setAuthIdentity(expected);

  EXPECT_EQ(expected, connection.getAuthIdentity());
}

TEST(ConnectionTests, setBytesFromClient) {
  uint64_t expected = 3;
  Connection connection;
  connection.setBytesFromClient(expected);

  EXPECT_EQ(expected, connection.getBytesFromClient());
}

TEST(ConnectionTests, setBytesToClient) {
  uint64_t expected = 3;
  Connection connection;
  connection.setBytesToClient(expected);

  EXPECT_EQ(expected, connection.getBytesToClient());
}

TEST(ConnectionTests, setClosing) {
  bool expected = true;
  Connection connection;

  EXPECT_NE(expected, connection.isClosing());
  connection.setIsClosing(expected);

  EXPECT_EQ(expected, connection.isClosing());
}

TEST(ConnectionTests, setFederationLink) {
  bool expected = true;
  Connection connection;

  EXPECT_NE(expected, connection.isFederationLink());
  connection.setIsFederationLink(expected);

  EXPECT_EQ(expected, connection.isFederationLink());
}

TEST(ConnectionTests, setFramesFromClient) {
  uint64_t expected = 3;
  Connection connection;
  connection.setFramesFromClient(expected);

  EXPECT_EQ(expected, connection.getFramesFromClient());
}

TEST(ConnectionTests, setFramesToClient) {
  uint64_t expected = 3;
  Connection connection;
  connection.setFramesToClient(expected);

  EXPECT_EQ(expected, connection.getFramesToClient());
}

TEST(ConnectionTests, setIncoming) {
  bool expected = true;
  Connection connection;

  EXPECT_NE(expected, connection.isIncoming());
  connection.setIsIncoming(expected);

  EXPECT_EQ(expected, connection.isIncoming());
}

TEST(ConnectionTests, setMsgsFromClient) {
  uint64_t expected = 3;
  Connection connection;
  connection.setMsgsFromClient(expected);

  EXPECT_EQ(expected, connection.getMsgsFromClient());
}

TEST(ConnectionTests, setMsgsToClient) {
  uint64_t expected = 3;
  Connection connection;
  connection.setMsgsToClient(expected);

  EXPECT_EQ(expected, connection.getMsgsToClient());
}

TEST(ConnectionTests, setProtocol) {
  std::string expected = "amqp";
  Connection connection;
  connection.setProtocol(expected);

  EXPECT_EQ(expected, connection.getProtocol());
}

TEST(ConnectionTests, setRemotePid) {
  uint32_t expected = 3;
  Connection connection;
  connection.setRemotePid(expected);

  EXPECT_EQ(expected, connection.getRemotePid());
}

TEST(ConnectionTests, setRemoteParentPid) {
  uint32_t expected = 3;
  Connection connection;
  connection.setRemoteParentPid(expected);

  EXPECT_EQ(expected, connection.getRemoteParentPid());
}

TEST(ConnectionTests, setRemoteProcessName) {
  std::string expected = "test value";
  Connection connection;
  connection.setRemoteProcessName(expected);

  EXPECT_EQ(expected, connection.getRemoteProcessName());
}

TEST(ConnectionTests, setSaslMechanism) {
  std::string expected = "test value";
  Connection connection;
  connection.setSaslMechanism(expected);

  EXPECT_EQ(expected, connection.getSaslMechanism());
}

TEST(ConnectionTests, setVhostRef) {
  std::string expected = "test value";
  Connection connection;
  connection.setVhostRef(expected);

  EXPECT_EQ(expected, connection.getVhostRef());
}

TEST(ConnectionTests, setSaslSsf) {
  uint64_t expected = 3;
  Connection connection;
  connection.setSaslSsf(expected);

  EXPECT_EQ(expected, connection.getSaslSsf());
}

TEST(ConnectionTests, setShadow) {
  bool expected = true;
  Connection connection;

  EXPECT_NE(expected, connection.isShadow());
  connection.setIsShadow(expected);

  EXPECT_EQ(expected, connection.isShadow());
}

TEST(ConnectionTests, setUserProxyAuth) {
  bool expected = true;
  Connection connection;

  EXPECT_NE(expected, connection.isUserProxyAuth());
  connection.setIsUserProxyAuth(expected);

  EXPECT_EQ(expected, connection.isUserProxyAuth());
}
