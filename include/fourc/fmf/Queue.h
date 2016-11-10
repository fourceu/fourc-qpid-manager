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

#ifndef FOURC_FMF_QUEUE_H
#define FOURC_FMF_QUEUE_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Queue : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Queue();
  virtual ~Queue() = default;
  
  uint64_t getAcquires() const;
  Queue& setAcquires(uint64_t);
  
  bool isAutoDelete() const;
  Queue& setAutoDelete(bool);
  
  uint32_t getBindingCount() const;
  Queue& setBindingCount(uint32_t);
  
  uint32_t getBindingCountHigh() const;
  Queue& setBindingCountHigh(uint32_t);

  uint32_t getBindingCountLow() const;
  Queue& setBindingCountLow(uint32_t);
  
  uint64_t getByteDepth() const;
  Queue& setByteDepth(uint64_t);

  uint64_t getByteFtdDepth() const;
  Queue& setByteFtdDepth(uint64_t);
  
  uint64_t getByteFtdDequeues() const;
  Queue& setByteFtdDequeues(uint64_t);
  
  uint64_t getByteFtdEnqueues() const;
  Queue& setByteFtdEnqueues(uint64_t);
  
  uint64_t getBytePersistDequeues() const;
  Queue& setBytePersistDequeues(uint64_t);

  uint64_t getBytePersistEnqueues() const;
  Queue& setBytePersistEnqueues(uint64_t);

  uint64_t getByteTotalDequeues() const;
  Queue& setByteTotalDequeues(uint64_t);
  
  uint64_t getByteTotalEnqueues() const;
  Queue& setByteTotalEnqueues(uint64_t);

  uint64_t getByteTxnDequeues() const;
  Queue& setByteTxnDequeues(uint64_t);

  uint64_t getByteTxnEnqueues() const;
  Queue& setByteTxnEnqueues(uint64_t);

  uint32_t getConsumerCount() const;
  Queue& setConsumerCount(uint32_t);

  uint32_t getConsumerCountHigh() const;
  Queue& setConsumerCountHigh(uint32_t);

  uint32_t getConsumerCountLow() const;
  Queue& setConsumerCountLow(uint32_t);
  
  const std::string& getCreator() const;
  Queue& setCreator(const std::string&);

  uint64_t getDiscardsLvq() const;
  Queue& setDiscardsLvq(uint64_t);

  uint64_t getDiscardsOverflow() const;
  Queue& setDiscardsOverflow(uint64_t);

  uint64_t getDiscardsPurge() const;
  Queue& setDiscardsPurge(uint64_t);

  uint64_t getDiscardsRing() const;
  Queue& setDiscardsRing(uint64_t);

  uint64_t getDiscardsSubscriber() const;
  Queue& setDiscardsSubscriber(uint64_t);

  uint64_t getDiscardsTtl() const;
  Queue& setDiscardsTtl(uint64_t);

  bool isDurable() const;
  Queue& setDurable(bool value);
  
  bool isExclusive() const;
  Queue& setExclusive(bool value);
  
  bool isFlowStopped() const;
  Queue& setFlowStopped(bool value);
  
  uint64_t getFlowStoppedCount() const;
  Queue& setFlowStoppedCount(uint64_t);
  
  uint64_t getMessageLatencyAvg() const;
  Queue& setMessageLatencyAvg(uint64_t);

  uint64_t getMessageLatencyCount() const;
  Queue& setMessageLatencyCount(uint64_t);

  uint64_t getMessageLatencyMax() const;
  Queue& setMessageLatencyMax(uint64_t);

  uint64_t getMessageLatencyMin() const;
  Queue& setMessageLatencyMin(uint64_t);
  
  uint64_t getMsgDepth() const;
  Queue& setMsgDepth(uint64_t);

  uint64_t getMsgFtdDepth() const;
  Queue& setMsgFtdDepth(uint64_t);

  uint64_t getMsgFtdDequeues() const;
  Queue& setMsgFtdDequeues(uint64_t);

  uint64_t getMsgFtdEnqueues() const;
  Queue& setMsgFtdEnqueues(uint64_t);

  uint64_t getMsgPersistDequeues() const;
  Queue& setMsgPersistDequeues(uint64_t);

  uint64_t getMsgPersistEnqueues() const;
  Queue& setMsgPersistEnqueues(uint64_t);

  uint64_t getMsgTotalDequeues() const;
  Queue& setMsgTotalDequeues(uint64_t);

  uint64_t getMsgTotalEnqueues() const;
  Queue& setMsgTotalEnqueues(uint64_t);

  uint64_t getMsgTxnDequeues() const;
  Queue& setMsgTxnDequeues(uint64_t);

  uint64_t getMsgTxnEnqueues() const;
  Queue& setMsgTxnEnqueues(uint64_t);

  const std::string& getName() const;
  Queue& setName(const std::string&);

  const std::string& getRedirectPeer() const;
  Queue& setRedirectPeer(const std::string&);
  
  bool isRedirectSource() const;
  Queue& setRedirectSource(bool);
  
  uint64_t getReleases() const;
  Queue& setReleases(uint64_t);

  uint64_t getReroutes() const;
  Queue& setReroutes(uint64_t);

  uint64_t getUnackedMessages() const;
  Queue& setUnackedMessages(uint64_t);

  uint64_t getUnackedMessagesHigh() const;
  Queue& setUnackedMessagesHigh(uint64_t);

  uint64_t getUnackedMessagesLow() const;
  Queue& setUnackedMessagesLow(uint64_t);

  const std::string& getVhostRef() const;
  Queue& setVhostRef(const std::string&);

  bool operator==(const Queue& other) const;

private:
  uint64_t acquires;
  bool autoDelete;
  uint32_t bindingCount;
  uint32_t bindingCountHigh;
  uint32_t bindingCountLow;
  uint64_t byteDepth;
  uint64_t byteFtdDepth;
  uint64_t byteFtdDequeues;
  uint64_t byteFtdEnqueues;
  uint64_t bytePersistDequeues;
  uint64_t bytePersistEnqueues;
  uint64_t byteTotalDequeues;
  uint64_t byteTotalEnqueues;
  uint64_t byteTxnDequeues;
  uint64_t byteTxnEnqueues;
  uint32_t consumerCount;
  uint32_t consumerCountHigh;
  uint32_t consumerCountLow;
  std::string creator;
  uint64_t discardsLvq;
  uint64_t discardsOverflow;
  uint64_t discardsPurge;
  uint64_t discardsRing;
  uint64_t discardsSubscriber;
  uint64_t discardsTtl;
  bool durable;
  bool exclusive;
  bool flowStopped;
  uint64_t flowStoppedCount;
  uint64_t messageLatencyAvg;
  uint64_t messageLatencyCount;
  uint64_t messageLatencyMax;
  uint64_t messageLatencyMin;
  uint64_t msgDepth;
  uint64_t msgFtdDepth;
  uint64_t msgFtdDequeues;
  uint64_t msgFtdEnqueues;
  uint64_t msgPersistDequeus;
  uint64_t msgPersistEnqueues;
  uint64_t msgTotalDequeus;
  uint64_t msgTotalEnqueues;
  uint64_t msgTxnDequeus;
  uint64_t msgTxnEnqueues;
  std::string name;
  std::string redirectPeer;
  bool redirectSource;
  uint64_t releases;
  uint64_t reroutes;
  uint64_t unackedMessages;
  uint64_t unackedMessagesHigh;
  uint64_t unackedMessagesLow;
  std::string vhostRef;
};

}} // Namespaces

#endif //FOURC_FMF_QUEUE_H
