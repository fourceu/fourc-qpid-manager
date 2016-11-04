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
#include <fourc/fmf/Acl.h>

using namespace fourc::fmf;

TEST(AclTests, ctor) {
  auto instance = new Acl();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(AclTests, ctorSetsAclDenyCount) {
  Acl acl;

  EXPECT_EQ(0u, acl.getAclDenyCount());
}

TEST(AclTests, ctorSetsConnectionDenyCount) {
  Acl acl;

  EXPECT_EQ(0u, acl.getConnectionDenyCount());
}

TEST(AclTests, ctorSetsMaxConnections) {
  Acl acl;

  EXPECT_EQ(0u, acl.getMaxConnections());
}

TEST(AclTests, ctorSetsMaxConnectionsPerIp) {
  Acl acl;

  EXPECT_EQ(0u, acl.getMaxConnectionsPerIp());
}

TEST(AclTests, ctorSetsMaxConnectionsPerUser) {
  Acl acl;

  EXPECT_EQ(0u, acl.getMaxConnectionsPerUser());
}

TEST(AclTests, ctorSetsMaxQueuesPerUser) {
  Acl acl;

  EXPECT_EQ(0u, acl.getMaxQueuesPerUser());
}

TEST(AclTests, ctorSetsQueueQuotaDenyCount) {
  Acl acl;

  EXPECT_EQ(0u, acl.getQueueQuotaDenyCount());
}

TEST(AclTests, ctorSetsEnforcingAcl) {
  Acl acl;

  EXPECT_TRUE(acl.isEnforcingAcl());
}

TEST(AclTests, ctorSetsTransferAcl) {
  Acl acl;

  EXPECT_TRUE(acl.isTransferAcl());
}

TEST(AclTests, ctorSetsLastAclLoad) {
  Acl acl;

  auto expected = std::chrono::system_clock::time_point::min();

  EXPECT_EQ(expected, acl.getLastAclLoad());
}

TEST(AclTests, ctorSetsBrokerRef) {
  Acl acl;

  EXPECT_TRUE(acl.getBrokerRef().empty());
}

TEST(AclTests, ctorSetsPolicyFile) {
  Acl acl;

  EXPECT_TRUE(acl.getPolicyFile().empty());
}

TEST(AclTests, setAclDenyCount) {
  uint32_t expected = 3;
  Acl acl;
  acl.setAclDenyCount(expected);

  EXPECT_EQ(expected, acl.getAclDenyCount());
}

TEST(AclTests, setConnectionDenyCount) {
  uint32_t expected = 3;
  Acl acl;
  acl.setConnectionDenyCount(expected);

  EXPECT_EQ(expected, acl.getConnectionDenyCount());
}

TEST(AclTests, setMaxConnections) {
  uint32_t expected = 3;
  Acl acl;
  acl.setMaxConnections(expected);

  EXPECT_EQ(expected, acl.getMaxConnections());
}

TEST(AclTests, setMaxConnectionsPerIp) {
  uint32_t expected = 3;
  Acl acl;
  acl.setMaxConnectionsPerIp(expected);

  EXPECT_EQ(expected, acl.getMaxConnectionsPerIp());
}

TEST(AclTests, setMaxConnectionsPerUser) {
  uint32_t expected = 3;
  Acl acl;
  acl.setMaxConnectionsPerUser(expected);

  EXPECT_EQ(expected, acl.getMaxConnectionsPerUser());
}

TEST(AclTests, setMaxQueuesPerUser) {
  uint32_t expected = 3;
  Acl acl;
  acl.setMaxQueuesPerUser(expected);

  EXPECT_EQ(expected, acl.getMaxQueuesPerUser());
}

TEST(AclTests, setQueueQuotaDenyCount) {
  uint32_t expected = 3;
  Acl acl;
  acl.setQueueQuotaDenyCount(expected);

  EXPECT_EQ(expected, acl.getQueueQuotaDenyCount());
}

TEST(AclTests, setEnforcingAcl) {
  bool expected = false;
  Acl acl;
  acl.setIsEnforcingAcl(expected);

  EXPECT_EQ(expected, acl.isEnforcingAcl());
}

TEST(AclTests, setTransferAcl) {
  bool expected = false;
  Acl acl;
  acl.setIsTransferAcl(expected);

  EXPECT_EQ(expected, acl.isTransferAcl());
}

TEST(AclTests, setLastAclLoad) {
  auto expected = std::chrono::system_clock::now();
  Acl acl;
  acl.setLastAclLoad(expected);

  EXPECT_EQ(expected, acl.getLastAclLoad());
}

TEST(AclTests, setBrokerRef) {
  std::string expected = "test broker ref";
  Acl acl;
  acl.setBrokerRef(expected);

  EXPECT_EQ(expected, acl.getBrokerRef());
}

TEST(AclTests, setPolicyFile) {
  std::string expected = "test broker ref";
  Acl acl;
  acl.setPolicyFile(expected);

  EXPECT_EQ(expected, acl.getPolicyFile());
}
