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

#include <fourc/fmf/Queue.h>

namespace fourc {
namespace fmf {

const std::string Queue::OBJECT_TYPE_NAME = "queue";

Queue::Queue() : 
    acquires(0),
    autoDelete(false),
    bindingCount(0),
    bindingCountHigh(0),
    bindingCountLow(0),
    byteDepth(0),
    byteFtdDepth(0),
    byteFtdDequeues(0),
    byteFtdEnqueues(0),
    bytePersistDequeues(0),
    bytePersistEnqueues(0),
    byteTotalDequeues(0),
    byteTotalEnqueues(0),
    byteTxnDequeues(0),
    byteTxnEnqueues(0),
    consumerCount(0),
    consumerCountHigh(0),
    consumerCountLow(0),
    discardsLvq(0),
    discardsOverflow(0),
    discardsPurge(0),
    discardsRing(0),
    discardsSubscriber(0),
    discardsTtl(0),
    durable(false),
    exclusive(false),
    flowStopped(false),
    flowStoppedCount(0),
    messageLatencyAvg(0),
    messageLatencyCount(0),
    messageLatencyMax(0),
    messageLatencyMin(0),
    msgDepth(0),
    msgFtdDepth(0),
    msgFtdDequeues(0),
    msgFtdEnqueues(0),
    msgPersistDequeus(0),
    msgPersistEnqueues(0),
    msgTotalDequeus(0),
    msgTotalEnqueues(0),
    msgTxnDequeus(0),
    msgTxnEnqueues(0),
    redirectSource(false),
    releases(0),
    reroutes(0),
    unackedMessages(0),
    unackedMessagesHigh(0),
    unackedMessagesLow(0) {
}

uint64_t Queue::getAcquires() const {
  return acquires;
}

Queue& Queue::setAcquires(uint64_t value) {
  acquires = value;

  return *this;
}

bool Queue::isAutoDelete() const {
  return autoDelete;
}

Queue& Queue::setAutoDelete(bool value) {
  autoDelete = value;

  return *this;
}

uint32_t Queue::getBindingCount() const {
  return bindingCount;
}

Queue& Queue::setBindingCount(uint32_t value) {
  bindingCount = value;

  return *this;
}

uint32_t Queue::getBindingCountHigh() const {
  return bindingCountHigh;
}

Queue& Queue::setBindingCountHigh(uint32_t value) {
  bindingCountHigh = value;

  return *this;
}

uint32_t Queue::getBindingCountLow() const {
  return bindingCountLow;
}

Queue& Queue::setBindingCountLow(uint32_t value) {
  bindingCountLow = value;

  return *this;
}

uint64_t Queue::getByteDepth() const {
  return byteDepth;
}

Queue& Queue::setByteDepth(uint64_t value) {
  byteDepth = value;

  return *this;
}

uint64_t Queue::getByteFtdDepth() const {
  return byteFtdDepth;
}

Queue& Queue::setByteFtdDepth(uint64_t value) {
  byteFtdDepth = value;

  return *this;
}

uint64_t Queue::getByteFtdDequeues() const {
  return byteFtdDequeues;
}

Queue& Queue::setByteFtdDequeues(uint64_t value) {
  byteFtdDequeues = value;

  return *this;
}

uint64_t Queue::getByteFtdEnqueues() const {
  return byteFtdEnqueues;
}

Queue& Queue::setByteFtdEnqueues(uint64_t value) {
  byteFtdEnqueues = value;

  return *this;
}

uint64_t Queue::getBytePersistDequeues() const {
  return bytePersistDequeues;
}

Queue& Queue::setBytePersistDequeues(uint64_t value) {
  bytePersistDequeues = value;

  return *this;
}

uint64_t Queue::getBytePersistEnqueues() const {
  return bytePersistEnqueues;
}

Queue& Queue::setBytePersistEnqueues(uint64_t value) {
  bytePersistEnqueues = value;

  return *this;
}

uint64_t Queue::getByteTotalDequeues() const {
  return byteTotalDequeues;
}

Queue& Queue::setByteTotalDequeues(uint64_t value) {
  byteTotalDequeues = value;

  return *this;
}

uint64_t Queue::getByteTotalEnqueues() const {
  return byteTotalEnqueues;
}

Queue& Queue::setByteTotalEnqueues(uint64_t value) {
  byteTotalEnqueues = value;

  return *this;
}

uint64_t Queue::getByteTxnDequeues() const {
  return byteTxnDequeues;
}

Queue& Queue::setByteTxnDequeues(uint64_t value) {
  byteTxnDequeues = value;

  return *this;
}

uint64_t Queue::getByteTxnEnqueues() const {
  return byteTxnEnqueues;
}

Queue& Queue::setByteTxnEnqueues(uint64_t value) {
  byteTxnEnqueues = value;

  return *this;
}

uint32_t Queue::getConsumerCount() const {
  return consumerCount;
}

Queue& Queue::setConsumerCount(uint32_t value) {
  consumerCount = value;

  return *this;
}

uint32_t Queue::getConsumerCountHigh() const {
  return consumerCountHigh;
}

Queue& Queue::setConsumerCountHigh(uint32_t value) {
  consumerCountHigh = value;

  return *this;
}

uint32_t Queue::getConsumerCountLow() const {
  return consumerCountLow;
}

Queue& Queue::setConsumerCountLow(uint32_t value) {
  consumerCountLow = value;

  return *this;
}

const std::string& Queue::getCreator() const {
  return creator;
}

Queue& Queue::setCreator(const std::string& value) {
  creator = value;

  return *this;
}

uint64_t Queue::getDiscardsLvq() const {
  return discardsLvq;
}

Queue& Queue::setDiscardsLvq(uint64_t value) {
  discardsLvq = value;

  return *this;
}

uint64_t Queue::getDiscardsOverflow() const {
  return discardsOverflow;
}

Queue& Queue::setDiscardsOverflow(uint64_t value) {
  discardsOverflow = value;

  return *this;
}

uint64_t Queue::getDiscardsPurge() const {
  return discardsPurge;
}

Queue& Queue::setDiscardsPurge(uint64_t value) {
  discardsPurge = value;

  return *this;
}

uint64_t Queue::getDiscardsRing() const {
  return discardsRing;
}

Queue& Queue::setDiscardsRing(uint64_t value) {
  discardsRing = value;

  return *this;
}

uint64_t Queue::getDiscardsSubscriber() const {
  return discardsSubscriber;
}

Queue& Queue::setDiscardsSubscriber(uint64_t value) {
  discardsSubscriber = value;

  return *this;
}

uint64_t Queue::getDiscardsTtl() const {
  return discardsTtl;
}

Queue& Queue::setDiscardsTtl(uint64_t value) {
  discardsTtl = value;

  return *this;
}

bool Queue::isDurable() const {
  return durable;
}

Queue& Queue::setDurable(bool value) {
  durable = value;

  return *this;
}

bool Queue::isExclusive() const {
  return exclusive;
}

Queue& Queue::setExclusive(bool value) {
  exclusive = value;

  return *this;
}

bool Queue::isFlowStopped() const {
  return flowStopped;
}

Queue& Queue::setFlowStopped(bool value) {
  flowStopped = value;

  return *this;
}

uint32_t Queue::getFlowStoppedCount() const {
  return flowStoppedCount;
}

Queue& Queue::setFlowStoppedCount(uint32_t value) {
  flowStoppedCount = value;

  return *this;
}

uint32_t Queue::getMessageLatencyAvg() const {
  return messageLatencyAvg;
}

Queue& Queue::setMessageLatencyAvg(uint32_t value) {
  messageLatencyAvg = value;

  return *this;
}

uint64_t Queue::getMessageLatencyCount() const {
  return messageLatencyCount;
}

Queue& Queue::setMessageLatencyCount(uint64_t value) {
  messageLatencyCount = value;

  return *this;
}

uint64_t Queue::getMessageLatencyMax() const {
  return messageLatencyMax;
}

Queue& Queue::setMessageLatencyMax(uint64_t value) {
  messageLatencyMax = value;

  return *this;
}

uint32_t Queue::getMessageLatencyMin() const {
  return messageLatencyMin;
}

Queue& Queue::setMessageLatencyMin(uint32_t value) {
  messageLatencyMin = value;

  return *this;
}

uint64_t Queue::getMsgDepth() const {
  return msgDepth;
}

Queue& Queue::setMsgDepth(uint64_t value) {
  msgDepth = value;

  return *this;
}

uint64_t Queue::getMsgFtdDepth() const {
  return msgFtdDepth;
}

Queue& Queue::setMsgFtdDepth(uint64_t value) {
  msgFtdDepth = value;

  return *this;
}

uint64_t Queue::getMsgFtdDequeues() const {
  return msgFtdDequeues;
}

Queue& Queue::setMsgFtdDequeues(uint64_t value) {
  msgFtdDequeues = value;

  return *this;
}

uint64_t Queue::getMsgFtdEnqueues() const {
  return msgFtdEnqueues;
}

Queue& Queue::setMsgFtdEnqueues(uint64_t value) {
  msgFtdEnqueues = value;

  return *this;
}

uint64_t Queue::getMsgPersistDequeues() const {
  return msgPersistDequeus;
}

Queue& Queue::setMsgPersistDequeues(uint64_t value) {
  msgPersistDequeus = value;

  return *this;
}

uint64_t Queue::getMsgPersistEnqueues() const {
  return msgPersistEnqueues;
}

Queue& Queue::setMsgPersistEnqueues(uint64_t value) {
  msgPersistEnqueues = value;

  return *this;
}

uint64_t Queue::getMsgTotalDequeues() const {
  return msgTotalDequeus;
}

Queue& Queue::setMsgTotalDequeues(uint64_t value) {
  msgTotalDequeus = value;

  return *this;
}

uint64_t Queue::getMsgTotalEnqueues() const {
  return msgTotalEnqueues;
}

Queue& Queue::setMsgTotalEnqueues(uint64_t value) {
  msgTotalEnqueues = value;

  return *this;
}

uint64_t Queue::getMsgTxnDequeues() const {
  return msgTxnDequeus;
}

Queue& Queue::setMsgTxnDequeues(uint64_t value) {
  msgTxnDequeus = value;

  return *this;
}

uint64_t Queue::getMsgTxnEnqueues() const {
  return msgTxnEnqueues;
}

Queue& Queue::setMsgTxnEnqueues(uint64_t value) {
  msgTxnEnqueues = value;

  return *this;
}

const std::string& Queue::getName() const {
  return name;
}

Queue& Queue::setName(const std::string& value) {
  name = value;

  return *this;
}

const std::string& Queue::getRedirectPeer() const {
  return redirectPeer;
}

Queue& Queue::setRedirectPeer(const std::string& value) {
  redirectPeer = value;

  return *this;
}

bool Queue::isRedirectSource() const {
  return redirectSource;
}

Queue& Queue::setRedirectSource(bool value) {
  redirectSource = value;

  return *this;
}

uint64_t Queue::getReleases() const {
  return releases;
}

Queue& Queue::setReleases(uint64_t value) {
  releases = value;

  return *this;
}

uint64_t Queue::getReroutes() const {
  return reroutes;
}

Queue& Queue::setReroutes(uint64_t value) {
  reroutes = value;

  return *this;
}

uint32_t Queue::getUnackedMessages() const {
  return unackedMessages;
}

Queue& Queue::setUnackedMessages(uint32_t value) {
  unackedMessages = value;

  return *this;
}

uint32_t Queue::getUnackedMessagesHigh() const {
  return unackedMessagesHigh;
}

Queue& Queue::setUnackedMessagesHigh(uint32_t value) {
  unackedMessagesHigh = value;

  return *this;
}

uint32_t Queue::getUnackedMessagesLow() const {
  return unackedMessagesLow;
}

Queue& Queue::setUnackedMessagesLow(uint32_t value) {
  unackedMessagesLow = value;

  return *this;
}

const std::string& Queue::getVhostRef() const {
  return vhostRef;
}

Queue& Queue::setVhostRef(const std::string& value) {
  vhostRef = value;

  return *this;
}

bool Queue::operator==(const Queue& other) const {
  return BrokerObject::operator==(other)
         && acquires == other.acquires
         && autoDelete == other.autoDelete
         && bindingCount == other.bindingCount
         && bindingCountHigh == other.bindingCountHigh
         && bindingCountLow == other.bindingCountLow
         && byteDepth == other.byteDepth
         && byteFtdDepth == other.byteFtdDepth
         && byteFtdDequeues == other.byteFtdDequeues
         && byteFtdEnqueues == other.byteFtdEnqueues
         && bytePersistDequeues == other.bytePersistDequeues
         && bytePersistEnqueues == other.bytePersistEnqueues
         && byteTotalDequeues == other.byteTotalDequeues
         && byteTotalEnqueues == other.byteTotalEnqueues
         && byteTxnDequeues == other.byteTxnDequeues
         && byteTxnEnqueues == other.byteTxnEnqueues
         && consumerCount == other.consumerCount
         && consumerCountHigh == other.consumerCountHigh
         && consumerCountLow == other.consumerCountLow
         && creator == other.creator
         && discardsLvq == other.discardsLvq
         && discardsOverflow == other.discardsOverflow
         && discardsPurge == other.discardsPurge
         && discardsSubscriber == other.discardsSubscriber
         && discardsTtl == other.discardsTtl
         && durable == other.durable
         && exclusive == other.exclusive
         && flowStopped == other.flowStopped
         && flowStoppedCount == other.flowStoppedCount
         && messageLatencyAvg == other.messageLatencyAvg
         && messageLatencyCount == other.messageLatencyCount
         && messageLatencyMax == other.messageLatencyMax
         && messageLatencyMin == other.messageLatencyMin
         && msgDepth == other.msgDepth
         && msgFtdDepth == other.msgFtdDepth
         && msgPersistDequeus == other.msgPersistDequeus
         && msgPersistEnqueues == other.msgPersistEnqueues
         && msgTotalDequeus == other.msgTotalDequeus
         && msgTotalEnqueues == other.msgTotalEnqueues
         && msgTxnDequeus == other.msgTxnDequeus
         && msgTxnEnqueues == other.msgTxnEnqueues
         && name == other.name
         && redirectPeer == other.redirectPeer
         && redirectSource == other.redirectSource
         && releases == other.releases
         && reroutes == other.reroutes
         && unackedMessages == other.unackedMessages
         && unackedMessagesHigh == other.unackedMessagesHigh
         && unackedMessagesLow == other.unackedMessagesLow
         && vhostRef == other.vhostRef;
}

}} // Namespaces