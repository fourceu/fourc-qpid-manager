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
#include <fourc/fmf/Queue.h>

using namespace fourc::fmf;

TEST(QueueTests, ctor) {
  auto instance = new Queue();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(QueueTests, ctorSetsAcquires) {
  Queue queue;

  EXPECT_EQ(0u, queue.getAcquires());
}

TEST(QueueTests, ctorSetsAutoDelete) {
  Queue queue;
  
  EXPECT_FALSE(queue.isAutoDelete());
}

TEST(QueueTests, ctorSetsBindingCount) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getBindingCount());
}

TEST(QueueTests, ctorSetsBindingCountHigh) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getBindingCountHigh());
}

TEST(QueueTests, ctorSetsBindingCountLow) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getBindingCountLow());
}

TEST(QueueTests, ctorSetsByteDepth) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteDepth());
}

TEST(QueueTests, ctorSetsByteFtdDepth) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteFtdDepth());
}

TEST(QueueTests, ctorSetsByteFtdDequeues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteFtdDequeues());
}

TEST(QueueTests, ctorSetsByteFtdEnqueues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteFtdEnqueues());
}

TEST(QueueTests, ctorSetsBytePersistDequeues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getBytePersistDequeues());
}

TEST(QueueTests, ctorSetsBytePersistEnqueues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getBytePersistEnqueues());
}

TEST(QueueTests, ctorSetsByteTotalDequeues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteTotalDequeues());
}

TEST(QueueTests, ctorSetsByteTotalEnqueues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteTotalEnqueues());
}

TEST(QueueTests, ctorSetsByteTxnDequeues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteTxnDequeues());
}

TEST(QueueTests, ctorSetsByteTxnEnqueues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getByteTxnEnqueues());
}

TEST(QueueTests, ctorSetsConsumerCount) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getConsumerCount());
}

TEST(QueueTests, ctorSetsConsumerCountHigh) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getConsumerCountHigh());
}

TEST(QueueTests, ctorSetsConsumerCountLow) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getConsumerCountLow());
}

TEST(QueueTests, ctorSetsDiscardsLvq) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getDiscardsLvq());
}

TEST(QueueTests, ctorSetsDiscardsOverflow) {
  Queue queue;

  EXPECT_EQ(0u, queue.getDiscardsOverflow());
}

TEST(QueueTests, ctorSetsDiscardsPurge) {
  Queue queue;

  EXPECT_EQ(0u, queue.getDiscardsPurge());
}

TEST(QueueTests, ctorSetsDiscardsRing) {
  Queue queue;

  EXPECT_EQ(0u, queue.getDiscardsRing());
}

TEST(QueueTests, ctorSetsDiscardsSubscriber) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getDiscardsSubscriber());
}

TEST(QueueTests, ctorSetsDiscardsTtl) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getDiscardsTtl());
}

TEST(QueueTests, ctorSetsDurable) {
  Queue queue;
  
  EXPECT_FALSE(queue.isDurable());
}

TEST(QueueTests, ctorSetsExclusive) {
  Queue queue;
  
  EXPECT_FALSE(queue.isExclusive());
}

TEST(QueueTests, ctorSetsFlowStopped) {
  Queue queue;
  
  EXPECT_FALSE(queue.isFlowStopped());
}

TEST(QueueTests, ctorSetsFlowStoppedCount) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getFlowStoppedCount());
}

TEST(QueueTests, ctorSetsMessageLatencyAvg) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMessageLatencyAvg());
}

TEST(QueueTests, ctorSetsMessageLatencyCount) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMessageLatencyCount());
}

TEST(QueueTests, ctorSetsMessageLatencyMax) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMessageLatencyMax());
}

TEST(QueueTests, ctorSetsMessageLatencyMin) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMessageLatencyMin());
}

TEST(QueueTests, ctorSetsMsgDepth) {
  Queue queue;

  EXPECT_EQ(0u, queue.getMsgDepth());
}

TEST(QueueTests, ctorSetsMsgFtdDepth) {
  Queue queue;

  EXPECT_EQ(0u, queue.getMsgFtdDepth());
  }

TEST(QueueTests, ctorSetsMsgFtdDequeues) {
  Queue queue;

  EXPECT_EQ(0u, queue.getMsgFtdDequeues());
}

TEST(QueueTests, ctorSetsMsgFtdEnqueues) {
  Queue queue;

  EXPECT_EQ(0u, queue.getMsgFtdEnqueues());
}

TEST(QueueTests, ctorSetsMsgPersistDequeues) {
  Queue queue;

  EXPECT_EQ(0u, queue.getMsgPersistDequeues());
}

TEST(QueueTests, ctorSetsMsgPersistEnqueues) {
  Queue queue;

  EXPECT_EQ(0u, queue.getMsgPersistEnqueues());
}

TEST(QueueTests, ctorSetsMsgTotalDequeues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMsgTotalDequeues());
}

TEST(QueueTests, ctorSetsMsgTotalEnqueues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMsgTotalEnqueues());
}

TEST(QueueTests, ctorSetsMsgTxnDequeues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMsgTxnDequeues());
}

TEST(QueueTests, ctorSetsMsgTxnEnqueues) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getMsgTxnEnqueues());
}

TEST(QueueTests, ctorSetsName) {
  Queue queue;
  
  EXPECT_TRUE(queue.getName().empty());
}

TEST(QueueTests, ctorSetsRedirectPeer) {
  Queue queue;
  
  EXPECT_TRUE(queue.getRedirectPeer().empty());
}

TEST(QueueTests, ctorSetsRedirectSource) {
  Queue queue;
  
  EXPECT_FALSE(queue.isRedirectSource());
}

TEST(QueueTests, ctorSetsReleases) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getReleases());
}

TEST(QueueTests, ctorSetsReroutes) {
  Queue queue;
  
  EXPECT_EQ(0u, queue.getReroutes());
}

TEST(QueueTests, ctorSetsUnackedMessages) {
  Queue queue;

  EXPECT_EQ(0u, queue.getUnackedMessages());
}

TEST(QueueTests, ctorSetsUnackedMessagesHigh) {
  Queue queue;

  EXPECT_EQ(0u, queue.getUnackedMessagesHigh());
}

TEST(QueueTests, ctorSetsUnackedMessagesLow) {
  Queue queue;

  EXPECT_EQ(0u, queue.getUnackedMessagesLow());
}

TEST(QueueTests, ctorSetsVhostRef) {
  Queue queue;

  EXPECT_TRUE(queue.getVhostRef().empty());
}

// *****************

TEST(QueueTests, setAcquires) {
  uint64_t expected = 7;
  Queue queue;
  queue.setAcquires(expected);

  EXPECT_EQ(expected, queue.getAcquires());
}

TEST(QueueTests, setAutoDelete) {
  bool expected = true;
  Queue queue;

  EXPECT_NE(expected, queue.isAutoDelete());
  queue.setAutoDelete(expected);

  EXPECT_EQ(expected, queue.isAutoDelete());
}

TEST(QueueTests, setBindingCount) {
  uint32_t expected = 7;
  Queue queue;
  queue.setBindingCount(expected);

  EXPECT_EQ(expected, queue.getBindingCount());
}

TEST(QueueTests, setBindingCountHigh) {
  uint32_t expected = 7;
  Queue queue;
  queue.setBindingCountHigh(expected);

  EXPECT_EQ(expected, queue.getBindingCountHigh());
}

TEST(QueueTests, setBindingCountLow) {
  uint32_t expected = 7;
  Queue queue;
  queue.setBindingCountLow(expected);

  EXPECT_EQ(expected, queue.getBindingCountLow());
}

TEST(QueueTests, setByteDepth) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteDepth(expected);

  EXPECT_EQ(expected, queue.getByteDepth());
}

TEST(QueueTests, setByteFtdDepth) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteFtdDepth(expected);

  EXPECT_EQ(expected, queue.getByteFtdDepth());
}

TEST(QueueTests, setByteFtdDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteFtdDequeues(expected);

  EXPECT_EQ(expected, queue.getByteFtdDequeues());
}

TEST(QueueTests, setByteFtdEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteFtdEnqueues(expected);

  EXPECT_EQ(expected, queue.getByteFtdEnqueues());
}

TEST(QueueTests, setBytePersistDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setBytePersistDequeues(expected);

  EXPECT_EQ(expected, queue.getBytePersistDequeues());
}

TEST(QueueTests, setBytePersistEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setBytePersistEnqueues(expected);

  EXPECT_EQ(expected, queue.getBytePersistEnqueues());
}

TEST(QueueTests, setByteTotalDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteTotalDequeues(expected);

  EXPECT_EQ(expected, queue.getByteTotalDequeues());
}

TEST(QueueTests, setByteTotalEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteTotalEnqueues(expected);

  EXPECT_EQ(expected, queue.getByteTotalEnqueues());
}

TEST(QueueTests, setByteTxnDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteTxnDequeues(expected);

  EXPECT_EQ(expected, queue.getByteTxnDequeues());
}

TEST(QueueTests, setByteTxnEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setByteTxnEnqueues(expected);

  EXPECT_EQ(expected, queue.getByteTxnEnqueues());
}

TEST(QueueTests, setConsumerCount) {
  uint32_t expected = 7;
  Queue queue;
  queue.setConsumerCount(expected);

  EXPECT_EQ(expected, queue.getConsumerCount());
}

TEST(QueueTests, setConsumerCountHigh) {
  uint32_t expected = 7;
  Queue queue;
  queue.setConsumerCountHigh(expected);

  EXPECT_EQ(expected, queue.getConsumerCountHigh());
}

TEST(QueueTests, setConsumerCountLow) {
  uint32_t expected = 7;
  Queue queue;
  queue.setConsumerCountLow(expected);

  EXPECT_EQ(expected, queue.getConsumerCountLow());
}

TEST(QueueTests, setDiscardsLvq) {
  uint64_t expected = 7;
  Queue queue;
  queue.setDiscardsLvq(expected);

  EXPECT_EQ(expected, queue.getDiscardsLvq());
}

TEST(QueueTests, setDiscardsOverflow) {
  uint64_t expected = 7;
  Queue queue;
  queue.setDiscardsOverflow(expected);

  EXPECT_EQ(expected, queue.getDiscardsOverflow());
}

TEST(QueueTests, setDiscardsPurge) {
  uint64_t expected = 7;
  Queue queue;
  queue.setDiscardsPurge(expected);

  EXPECT_EQ(expected, queue.getDiscardsPurge());
}

TEST(QueueTests, setDiscardsRing) {
  uint64_t expected = 7;
  Queue queue;
  queue.setDiscardsRing(expected);

  EXPECT_EQ(expected, queue.getDiscardsRing());
}

TEST(QueueTests, setDiscardsSubscriber) {
  uint64_t expected = 7;
  Queue queue;
  queue.setDiscardsSubscriber(expected);

  EXPECT_EQ(expected, queue.getDiscardsSubscriber());
}

TEST(QueueTests, setDiscardsTtl) {
  uint64_t expected = 7;
  Queue queue;
  queue.setDiscardsTtl(expected);

  EXPECT_EQ(expected, queue.getDiscardsTtl());
}

TEST(QueueTests, setDurable) {
  bool expected = true;
  Queue queue;

  EXPECT_NE(expected, queue.isDurable());
  queue.setDurable(expected);

  EXPECT_EQ(expected, queue.isDurable());
}

TEST(QueueTests, setExclusive) {
  bool expected = true;
  Queue queue;

  EXPECT_NE(expected, queue.isExclusive());
  queue.setExclusive(expected);

  EXPECT_EQ(expected, queue.isExclusive());
}

TEST(QueueTests, setFlowStopped) {
  bool expected = true;
  Queue queue;

  EXPECT_NE(expected, queue.isFlowStopped());
  queue.setFlowStopped(expected);

  EXPECT_EQ(expected, queue.isFlowStopped());
}

TEST(QueueTests, setFlowStoppedCount) {
  uint64_t expected = 7;
  Queue queue;
  queue.setFlowStoppedCount(expected);

  EXPECT_EQ(expected, queue.getFlowStoppedCount());
}

TEST(QueueTests, setMessageLatencyAvg) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMessageLatencyAvg(expected);

  EXPECT_EQ(expected, queue.getMessageLatencyAvg());
}

TEST(QueueTests, setMessageLatencyCount) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMessageLatencyCount(expected);

  EXPECT_EQ(expected, queue.getMessageLatencyCount());
}

TEST(QueueTests, setMessageLatencyMax) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMessageLatencyMax(expected);

  EXPECT_EQ(expected, queue.getMessageLatencyMax());
}

TEST(QueueTests, setMessageLatencyMin) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMessageLatencyMin(expected);

  EXPECT_EQ(expected, queue.getMessageLatencyMin());
}

TEST(QueueTests, setMsgDepth) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgDepth(expected);

  EXPECT_EQ(expected, queue.getMsgDepth());
}

TEST(QueueTests, setMsgFtdDepth) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgFtdDepth(expected);

  EXPECT_EQ(expected, queue.getMsgFtdDepth());
}

TEST(QueueTests, setMsgFtdDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgFtdDequeues(expected);

  EXPECT_EQ(expected, queue.getMsgFtdDequeues());
}

TEST(QueueTests, setMsgFtdEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgFtdEnqueues(expected);

  EXPECT_EQ(expected, queue.getMsgFtdEnqueues());
}

TEST(QueueTests, setMsgPersistDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgPersistDequeues(expected);

  EXPECT_EQ(expected, queue.getMsgPersistDequeues());
}

TEST(QueueTests, setMsgPersistEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgPersistEnqueues(expected);

  EXPECT_EQ(expected, queue.getMsgPersistEnqueues());
}

TEST(QueueTests, setMsgTotalDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgTotalDequeues(expected);

  EXPECT_EQ(expected, queue.getMsgTotalDequeues());
}

TEST(QueueTests, setMsgTotalEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgTotalEnqueues(expected);

  EXPECT_EQ(expected, queue.getMsgTotalEnqueues());
}

TEST(QueueTests, setMsgTxnDequeues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgTxnDequeues(expected);

  EXPECT_EQ(expected, queue.getMsgTxnDequeues());
}

TEST(QueueTests, setMsgTxnEnqueues) {
  uint64_t expected = 7;
  Queue queue;
  queue.setMsgTxnEnqueues(expected);

  EXPECT_EQ(expected, queue.getMsgTxnEnqueues());
}

TEST(QueueTests, setName) {
  std::string expected = "test name";
  Queue queue;
  queue.setName(expected);

  EXPECT_EQ(expected, queue.getName());
}

TEST(QueueTests, setRedirectPeer) {
  std::string expected = "test redirect";
  Queue queue;
  queue.setRedirectPeer(expected);

  EXPECT_EQ(expected, queue.getRedirectPeer());
}

TEST(QueueTests, setRedirectSource) {
  bool expected = true;
  Queue queue;

  EXPECT_NE(expected, queue.isRedirectSource());
  queue.setRedirectSource(expected);

  EXPECT_EQ(expected, queue.isRedirectSource());
}

TEST(QueueTests, setReleases) {
  uint64_t expected = 7;
  Queue queue;
  queue.setReleases(expected);

  EXPECT_EQ(expected, queue.getReleases());
}

TEST(QueueTests, setReroutes) {
  uint64_t expected = 7;
  Queue queue;
  queue.setReroutes(expected);

  EXPECT_EQ(expected, queue.getReroutes());
}

TEST(QueueTests, setUnackedMessages) {
  uint64_t expected = 7;
  Queue queue;
  queue.setUnackedMessages(expected);

  EXPECT_EQ(expected, queue.getUnackedMessages());
}

TEST(QueueTests, setUnackedMessagesHigh) {
  uint64_t expected = 7;
  Queue queue;
  queue.setUnackedMessagesHigh(expected);

  EXPECT_EQ(expected, queue.getUnackedMessagesHigh());
}

TEST(QueueTests, setUnackedMessagesLow) {
  uint64_t expected = 7;
  Queue queue;
  queue.setUnackedMessagesLow(expected);

  EXPECT_EQ(expected, queue.getUnackedMessagesLow());
}

TEST(QueueTests, setVhostRef) {
  std::string expected = "test vhost ref";
  Queue queue;
  queue.setVhostRef(expected);

  EXPECT_EQ(expected, queue.getVhostRef());
}

// *****************

TEST(QueueTests, operatorEquals_SameInstance) {
  Queue node1;
  auto& node2(node1);

  EXPECT_EQ(node1, node2);
}

TEST(QueueTests, operatorEquals_CopiedInstance) {
  Queue node1;
  Queue node2 = node1;

  EXPECT_EQ(node1, node2);
}

TEST(QueueTests, operatorEquals_CopyConstructedInstance) {
  Queue node1;
  Queue node2(node1);

  EXPECT_EQ(node1, node2);
}

TEST(QueueTests, operatorEqualsFalse_DifferentName) {
  Queue node1;
  Queue node2;
  node2.setName("test");

  EXPECT_FALSE(node1 == node2);
}

TEST(QueueTests, operatorEqualsFalse_DifferentDurability) {
  Queue node1;
  Queue node2;
  node2.setDurable(true);

  EXPECT_FALSE(node1 == node2);
}