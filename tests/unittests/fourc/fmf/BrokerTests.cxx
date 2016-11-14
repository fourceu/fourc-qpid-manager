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
#include <fourc/fmf/Broker.h>

using namespace fourc::fmf;

TEST(BrokerTests, ctor) {
  auto instance = new Broker();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BrokerTests, ctorSetsAbandoned) {
  Broker broker;

  EXPECT_EQ(0u, broker.getAbandoned());
}

TEST(BrokerTests, ctorSetsAbandonedViaAlt) {
  Broker broker;

  EXPECT_EQ(0u, broker.getAbandonedViaAlt());
}

TEST(BrokerTests, ctorSetsAcquires) {
  Broker broker;

  EXPECT_EQ(0u, broker.getAcquires());
}

TEST(BrokerTests, ctorSetsByteDepth) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteDepth());
}

TEST(BrokerTests, ctorSetsByteFtdDepth) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteFtdDepth());
}

TEST(BrokerTests, ctorSetsByteFtdDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteFtdDequeues());
}

TEST(BrokerTests, ctorSetsByteFtdEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteFtdEnqueues());
}

TEST(BrokerTests, ctorSetsBytePersistDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getBytePersistDequeues());
}

TEST(BrokerTests, ctorSetsBytePersistEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getBytePersistEnqueues());
}

TEST(BrokerTests, ctorSetsByteTotalDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteTotalDequeues());
}

TEST(BrokerTests, ctorSetsByteTotalEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteTotalEnqueues());
}

TEST(BrokerTests, ctorSetsByteTxnDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteTxnDequeues());
}

TEST(BrokerTests, ctorSetsByteTxnEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getByteTxnEnqueues());
}

TEST(BrokerTests, ctorSetsConnBacklog) {
  Broker broker;

  EXPECT_EQ(0u, broker.getConnBacklog());
}

TEST(BrokerTests, ctorSetsDiscardsLvq) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsLvq());
}

TEST(BrokerTests, ctorSetsDiscardsNoRoute) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsNoRoute());
}

TEST(BrokerTests, ctorSetsDiscardsOverflow) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsOverflow());
}

TEST(BrokerTests, ctorSetsDiscardsPurge) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsPurge());
}

TEST(BrokerTests, ctorSetsDiscardsRing) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsRing());
}

TEST(BrokerTests, ctorSetsDiscardsSubscriber) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsSubscriber());
}

TEST(BrokerTests, ctorSetsDiscardsTtl) {
  Broker broker;

  EXPECT_EQ(0u, broker.getDiscardsTtl());
}

TEST(BrokerTests, ctorSetsMaxConns) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMaxConns());
}

TEST(BrokerTests, ctorSetsMgmtPubInterval) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMgmtPubInterval());
}

TEST(BrokerTests, ctorSetsMsgDepth) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgDepth());
}

TEST(BrokerTests, ctorSetsMsgFtdDepth) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgFtdDepth());
}

TEST(BrokerTests, ctorSetsMsgFtdDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgFtdDequeues());
}

TEST(BrokerTests, ctorSetsMsgFtdEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgFtdEnqueues());
}

TEST(BrokerTests, ctorSetsMsgPersistDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgPersistDequeues());
}

TEST(BrokerTests, ctorSetsMsgPersistEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgPersistEnqueues());
}

TEST(BrokerTests, ctorSetsMsgTotalDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgTotalDequeues());
}

TEST(BrokerTests, ctorSetsMsgTotalEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgTotalEnqueues());
}

TEST(BrokerTests, ctorSetsMsgTxnDequeues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgTxnDequeues());
}

TEST(BrokerTests, ctorSetsMsgTxnEnqueues) {
  Broker broker;

  EXPECT_EQ(0u, broker.getMsgTxnEnqueues());
}

TEST(BrokerTests, ctorSetsQueueCount) {
  Broker broker;

  EXPECT_EQ(0u, broker.getQueueCount());
}

TEST(BrokerTests, ctorSetsReleases) {
  Broker broker;

  EXPECT_EQ(0u, broker.getReleases());
}

TEST(BrokerTests, ctorSetsReroutes) {
  Broker broker;

  EXPECT_EQ(0u, broker.getReroutes());
}

TEST(BrokerTests, ctorSetsStagingThreshold) {
  Broker broker;

  EXPECT_EQ(0u, broker.getStagingThreshold());
}

TEST(BrokerTests, ctorSetsPort) {
  Broker broker;

  EXPECT_EQ(0u, broker.getPort());
}

TEST(BrokerTests, ctorSetsWorkerThreads) {
  Broker broker;

  EXPECT_EQ(0u, broker.getWorkerThreads());
}

TEST(BrokerTests, ctorSetsMgmtPublish) {
  Broker broker;

  EXPECT_FALSE(broker.getMgmtPublish());
}

TEST(BrokerTests, ctorSetsDataDir) {
  Broker broker;

  EXPECT_TRUE(broker.getDataDir().empty());
}

TEST(BrokerTests, ctorSetsName) {
  Broker broker;

  EXPECT_TRUE(broker.getName().empty());
}

TEST(BrokerTests, ctorSetsSystemRef) {
  Broker broker;

  EXPECT_TRUE(broker.getSystemRef().empty());
}

TEST(BrokerTests, ctorSetsVersion) {
  Broker broker;

  EXPECT_TRUE(broker.getVersion().empty());
}

TEST(BrokerTests, ctorSetsUptime) {
  Broker broker;

  EXPECT_EQ(std::chrono::nanoseconds::min(), broker.getUptime());
}

// ***************************************

TEST(BrokerTests, setAbandoned) {
  uint64_t expected = 1;
  Broker broker;
  broker.setAbandoned(expected);

  EXPECT_EQ(expected, broker.getAbandoned());
}

TEST(BrokerTests, setAbandonedViaAlt) {
  uint64_t expected = 2;
  Broker broker;
  broker.setAbandonedViaAlt(expected);

  EXPECT_EQ(expected, broker.getAbandonedViaAlt());
}

TEST(BrokerTests, setAcquires) {
  uint64_t expected = 3;
  Broker broker;
  broker.setAcquires(expected);

  EXPECT_EQ(expected, broker.getAcquires());
}

TEST(BrokerTests, setByteDepth) {
  uint64_t expected = 4;
  Broker broker;
  broker.setByteDepth(expected);

  EXPECT_EQ(expected, broker.getByteDepth());
}

TEST(BrokerTests, setByteFtdDepth) {
  uint64_t expected = 5;
  Broker broker;
  broker.setByteFtdDepth(expected);

  EXPECT_EQ(expected, broker.getByteFtdDepth());
}

TEST(BrokerTests, setByteFtdDequeues) {
  uint64_t expected = 6;
  Broker broker;
  broker.setByteFtdDequeues(expected);

  EXPECT_EQ(expected, broker.getByteFtdDequeues());
}

TEST(BrokerTests, setByteFtdEnqueues) {
  uint64_t expected = 7;
  Broker broker;
  broker.setByteFtdEnqueues(expected);

  EXPECT_EQ(expected, broker.getByteFtdEnqueues());
}

TEST(BrokerTests, setBytePersistDequeues) {
  uint64_t expected = 8;
  Broker broker;
  broker.setBytePersistDequeues(expected);

  EXPECT_EQ(expected, broker.getBytePersistDequeues());
}

TEST(BrokerTests, setBytePersistEnqueues) {
  uint64_t expected = 9;
  Broker broker;
  broker.setBytePersistEnqueues(expected);

  EXPECT_EQ(expected, broker.getBytePersistEnqueues());
}

TEST(BrokerTests, setByteTotalDequeues) {
  uint64_t expected = 10;
  Broker broker;
  broker.setByteTotalDequeues(expected);

  EXPECT_EQ(expected, broker.getByteTotalDequeues());
}

TEST(BrokerTests, setByteTotalEnqueues) {
  uint64_t expected = 11;
  Broker broker;
  broker.setByteTotalEnqueues(expected);

  EXPECT_EQ(expected, broker.getByteTotalEnqueues());
}

TEST(BrokerTests, setByteTxnDequeues) {
  uint64_t expected = 12;
  Broker broker;
  broker.setByteTxnDequeues(expected);

  EXPECT_EQ(expected, broker.getByteTxnDequeues());
}

TEST(BrokerTests, setByteTxnEnqueues) {
  uint64_t expected = 13;
  Broker broker;
  broker.setByteTxnEnqueues(expected);

  EXPECT_EQ(expected, broker.getByteTxnEnqueues());
}

TEST(BrokerTests, setConnBacklog) {
  uint16_t expected = 14;
  Broker broker;
  broker.setConnBacklog(expected);

  EXPECT_EQ(expected, broker.getConnBacklog());
}

TEST(BrokerTests, setDiscardsLvq) {
  uint64_t expected = 15;
  Broker broker;
  broker.setDiscardsLvq(expected);

  EXPECT_EQ(expected, broker.getDiscardsLvq());
}

TEST(BrokerTests, setDiscardsNoRoute) {
  uint64_t expected = 16;
  Broker broker;
  broker.setDiscardsNoRoute(expected);

  EXPECT_EQ(expected, broker.getDiscardsNoRoute());
}

TEST(BrokerTests, setDiscardsOverflow) {
  uint64_t expected = 17;
  Broker broker;
  broker.setDiscardsOverflow(expected);

  EXPECT_EQ(expected, broker.getDiscardsOverflow());
}

TEST(BrokerTests, setDiscardsPurge) {
  uint64_t expected = 18;
  Broker broker;
  broker.setDiscardsPurge(expected);

  EXPECT_EQ(expected, broker.getDiscardsPurge());
}

TEST(BrokerTests, setDiscardsRing) {
  uint64_t expected = 19;
  Broker broker;
  broker.setDiscardsRing(expected);

  EXPECT_EQ(expected, broker.getDiscardsRing());
}

TEST(BrokerTests, setDiscardsSubscriber) {
  uint64_t expected = 20;
  Broker broker;
  broker.setDiscardsSubscriber(expected);

  EXPECT_EQ(expected, broker.getDiscardsSubscriber());
}

TEST(BrokerTests, setDiscardsTtl) {
  uint64_t expected = 21;
  Broker broker;
  broker.setDiscardsTtl(expected);

  EXPECT_EQ(expected, broker.getDiscardsTtl());
}

TEST(BrokerTests, setMaxConns) {
  uint16_t expected = 22;
  Broker broker;
  broker.setMaxConns(expected);

  EXPECT_EQ(expected, broker.getMaxConns());
}

TEST(BrokerTests, setMgmtPubInterval) {
  uint16_t expected = 23;
  Broker broker;
  broker.setMgmtPubInterval(expected);

  EXPECT_EQ(expected, broker.getMgmtPubInterval());
}

TEST(BrokerTests, setMsgDepth) {
  uint64_t expected = 24;
  Broker broker;
  broker.setMsgDepth(expected);

  EXPECT_EQ(expected, broker.getMsgDepth());
}

TEST(BrokerTests, setMsgFtdDepth) {
  uint64_t expected = 25;
  Broker broker;
  broker.setMsgFtdDepth(expected);

  EXPECT_EQ(expected, broker.getMsgFtdDepth());
}

TEST(BrokerTests, setMsgFtdDequeues) {
  uint64_t expected = 26;
  Broker broker;
  broker.setMsgFtdDequeues(expected);

  EXPECT_EQ(expected, broker.getMsgFtdDequeues());
}

TEST(BrokerTests, setMsgFtdEnqueues) {
  uint64_t expected = 27;
  Broker broker;
  broker.setMsgFtdEnqueues(expected);

  EXPECT_EQ(expected, broker.getMsgFtdEnqueues());
}

TEST(BrokerTests, setMsgPersistDequeues) {
  uint64_t expected = 28;
  Broker broker;
  broker.setMsgPersistDequeues(expected);

  EXPECT_EQ(expected, broker.getMsgPersistDequeues());
}

TEST(BrokerTests, setMsgPersistEnqueues) {
  uint64_t expected = 29;
  Broker broker;
  broker.setMsgPersistEnqueues(expected);

  EXPECT_EQ(expected, broker.getMsgPersistEnqueues());
}

TEST(BrokerTests, setMsgTotalDequeues) {
  uint64_t expected = 30;
  Broker broker;
  broker.setMsgTotalDequeues(expected);

  EXPECT_EQ(expected, broker.getMsgTotalDequeues());
}

TEST(BrokerTests, setMsgTotalEnqueues) {
  uint64_t expected = 31;
  Broker broker;
  broker.setMsgTotalEnqueues(expected);

  EXPECT_EQ(expected, broker.getMsgTotalEnqueues());
}

TEST(BrokerTests, setMsgTxnDequeues) {
  uint64_t expected = 32;
  Broker broker;
  broker.setMsgTxnDequeues(expected);

  EXPECT_EQ(expected, broker.getMsgTxnDequeues());
}

TEST(BrokerTests, setMsgTxnEnqueues) {
  uint64_t expected = 33;
  Broker broker;
  broker.setMsgTxnEnqueues(expected);

  EXPECT_EQ(expected, broker.getMsgTxnEnqueues());
}

TEST(BrokerTests, setQueueCount) {
  uint64_t expected = 34;
  Broker broker;
  broker.setQueueCount(expected);

  EXPECT_EQ(expected, broker.getQueueCount());
}

TEST(BrokerTests, setReleases) {
  uint64_t expected = 35;
  Broker broker;
  broker.setReleases(expected);

  EXPECT_EQ(expected, broker.getReleases());
}

TEST(BrokerTests, setReroutes) {
  uint64_t expected = 36;
  Broker broker;
  broker.setReroutes(expected);

  EXPECT_EQ(expected, broker.getReroutes());
}

TEST(BrokerTests, setStagingThreshold) {
  uint16_t expected = 37;
  Broker broker;
  broker.setStagingThreshold(expected);

  EXPECT_EQ(expected, broker.getStagingThreshold());
}

TEST(BrokerTests, setPort) {
  uint16_t expected = 38;
  Broker broker;
  broker.setPort(expected);

  EXPECT_EQ(expected, broker.getPort());
}

TEST(BrokerTests, setWorkerThreads) {
  uint16_t expected = 39;
  Broker broker;
  broker.setWorkerThreads(expected);

  EXPECT_EQ(expected, broker.getWorkerThreads());
}

TEST(BrokerTests, setMgmtPublish) {
  bool expected = true;
  Broker broker;
  broker.setMgmtPublish(expected);

  EXPECT_EQ(expected, broker.getMgmtPublish());
}

TEST(BrokerTests, setDataDir) {
  std::string expected = "test data";
  Broker broker;
  broker.setDataDir(expected);

  EXPECT_EQ(expected, broker.getDataDir());
}

TEST(BrokerTests, setName) {
  std::string expected = "test name";
  Broker broker;
  broker.setName(expected);

  EXPECT_EQ(expected, broker.getName());
}

TEST(BrokerTests, setSystemRef) {
  std::string expected = "test ref";
  Broker broker;
  broker.setSystemRef(expected);

  EXPECT_EQ(expected, broker.getSystemRef());
}

TEST(BrokerTests, setVersion) {
  std::string expected = "test version";
  Broker broker;
  broker.setVersion(expected);

  EXPECT_EQ(expected, broker.getVersion());
}

TEST(BrokerTests, setUptime) {
  auto expected = std::chrono::nanoseconds::max();
  Broker broker;
  broker.setUptime(expected);

  EXPECT_EQ(expected, broker.getUptime());
}
