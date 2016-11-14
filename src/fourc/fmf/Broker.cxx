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

#include <fourc/fmf/Broker.h>

namespace fourc {
namespace fmf {

const std::string Broker::OBJECT_TYPE_NAME = "broker";

Broker::Broker() :
  abandoned(0),
  abandonedViaAlt(0),
  acquires(0),
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
  connBacklog(0),
  discardsLvq(0),
  discardsNoRoute(0),
  discardsOverflow(0),
  discardsPurge(0),
  discardsRing(0),
  discardsSubscriber(0),
  discardsTtl(0),
  maxConns(0),
  mgmtPubInterval(0),
  msgDepth(0),
  msgFtdDepth(0),
  msgFtdDequeues(0),
  msgFtdEnqueues(0),
  msgPersistDequeues(0),
  msgPersistEnqueues(0),
  msgTotalDequeues(0),
  msgTotalEnqueues(0),
  msgTxnDequeues(0),
  msgTxnEnqueues(0),
  queueCount(0),
  releases(0),
  reroutes(0),
  stagingThreshold(0),
  port(0),
  workerThreads(0),
  mgmtPublish(false),
  uptime(std::chrono::nanoseconds::min()) {}

uint64_t Broker::getAbandoned() const {
  return abandoned;
}

Broker& Broker::setAbandoned(const uint64_t value) {
  abandoned = value;

  return *this;
}

uint64_t Broker::getAbandonedViaAlt() const {
  return abandonedViaAlt;
}

Broker& Broker::setAbandonedViaAlt(const uint64_t value) {
  abandonedViaAlt = value;

  return *this;
}

uint64_t Broker::getAcquires() const {
  return acquires;
}

Broker& Broker::setAcquires(const uint64_t value) {
  acquires = value;

  return *this;
}

uint64_t Broker::getByteDepth() const {
  return byteDepth;
}

Broker& Broker::setByteDepth(const uint64_t value) {
  byteDepth = value;

  return *this;
}

uint64_t Broker::getByteFtdDepth() const {
  return byteFtdDepth;
}

Broker& Broker::setByteFtdDepth(const uint64_t value) {
  byteFtdDepth = value;

  return *this;
}

uint64_t Broker::getByteFtdDequeues() const {
  return byteFtdDequeues;
}

Broker& Broker::setByteFtdDequeues(const uint64_t value) {
  byteFtdDequeues = value;

  return *this;
}

uint64_t Broker::getByteFtdEnqueues() const {
  return byteFtdEnqueues;
}

Broker& Broker::setByteFtdEnqueues(const uint64_t value) {
  byteFtdEnqueues = value;

  return *this;
}

uint64_t Broker::getBytePersistDequeues() const {
  return bytePersistDequeues;
}

Broker& Broker::setBytePersistDequeues(const uint64_t value) {
  bytePersistDequeues = value;

  return *this;
}

uint64_t Broker::getBytePersistEnqueues() const {
  return bytePersistEnqueues;
}

Broker& Broker::setBytePersistEnqueues(const uint64_t value) {
  bytePersistEnqueues = value;

  return *this;
}

uint64_t Broker::getByteTotalDequeues() const {
  return byteTotalDequeues;
}

Broker& Broker::setByteTotalDequeues(const uint64_t value) {
  byteTotalDequeues = value;

  return *this;
}

uint64_t Broker::getByteTotalEnqueues() const {
  return byteTotalEnqueues;
}

Broker& Broker::setByteTotalEnqueues(const uint64_t value) {
  byteTotalEnqueues = value;

  return *this;
}

uint64_t Broker::getByteTxnDequeues() const {
  return byteTxnDequeues;
}

Broker& Broker::setByteTxnDequeues(const uint64_t value) {
  byteTxnDequeues = value;

  return *this;
}

uint64_t Broker::getByteTxnEnqueues() const {
  return byteTxnEnqueues;
}

Broker& Broker::setByteTxnEnqueues(const uint64_t value) {
  byteTxnEnqueues = value;

  return *this;
}

uint16_t Broker::getConnBacklog() const {
  return connBacklog;
}

Broker& Broker::setConnBacklog(const uint16_t value) {
  connBacklog = value;

  return *this;
}

uint64_t Broker::getDiscardsLvq() const {
  return discardsLvq;
}

Broker& Broker::setDiscardsLvq(const uint64_t value) {
  discardsLvq = value;

  return *this;
}

uint64_t Broker::getDiscardsNoRoute() const {
  return discardsNoRoute;
}

Broker& Broker::setDiscardsNoRoute(const uint64_t value) {
  discardsNoRoute = value;

  return *this;
}

uint64_t Broker::getDiscardsOverflow() const {
  return discardsOverflow;
}

Broker& Broker::setDiscardsOverflow(const uint64_t value) {
  discardsOverflow = value;

  return *this;
}

uint64_t Broker::getDiscardsPurge() const {
  return discardsPurge;
}

Broker& Broker::setDiscardsPurge(const uint64_t value) {
  discardsPurge = value;

  return *this;
}

uint64_t Broker::getDiscardsRing() const {
  return discardsRing;
}

Broker& Broker::setDiscardsRing(const uint64_t value) {
  discardsRing = value;

  return *this;
}

uint64_t Broker::getDiscardsSubscriber() const {
  return discardsSubscriber;
}

Broker& Broker::setDiscardsSubscriber(const uint64_t value) {
  discardsSubscriber = value;

  return *this;
}

uint64_t Broker::getDiscardsTtl() const {
  return discardsTtl;
}

Broker& Broker::setDiscardsTtl(const uint64_t value) {
  discardsTtl = value;

  return *this;
}

uint16_t Broker::getMaxConns() const {
  return maxConns;
}

Broker& Broker::setMaxConns(const uint16_t value) {
  maxConns = value;

  return *this;
}

uint16_t Broker::getMgmtPubInterval() const {
  return mgmtPubInterval;
}

Broker& Broker::setMgmtPubInterval(const uint16_t value) {
  mgmtPubInterval = value;

  return *this;
}

uint64_t Broker::getMsgDepth() const {
  return msgDepth;
}

Broker& Broker::setMsgDepth(const uint64_t value) {
  msgDepth = value;

  return *this;
}

uint64_t Broker::getMsgFtdDepth() const {
  return msgFtdDepth;
}

Broker& Broker::setMsgFtdDepth(const uint64_t value) {
  msgFtdDepth = value;

  return *this;
}

uint64_t Broker::getMsgFtdDequeues() const {
  return msgFtdDequeues;
}

Broker& Broker::setMsgFtdDequeues(const uint64_t value) {
  msgFtdDequeues = value;

  return *this;
}

uint64_t Broker::getMsgFtdEnqueues() const {
  return msgFtdEnqueues;
}

Broker& Broker::setMsgFtdEnqueues(const uint64_t value) {
  msgFtdEnqueues = value;

  return *this;
}

uint64_t Broker::getMsgPersistDequeues() const {
  return msgPersistDequeues;
}

Broker& Broker::setMsgPersistDequeues(const uint64_t value) {
  msgPersistDequeues = value;

  return *this;
}

uint64_t Broker::getMsgPersistEnqueues() const {
  return msgPersistEnqueues;
}

Broker& Broker::setMsgPersistEnqueues(const uint64_t value) {
  msgPersistEnqueues = value;

  return *this;
}

uint64_t Broker::getMsgTotalDequeues() const {
  return msgTotalDequeues;
}

Broker& Broker::setMsgTotalDequeues(const uint64_t value) {
  msgTotalDequeues = value;

  return *this;
}

uint64_t Broker::getMsgTotalEnqueues() const {
  return msgTotalEnqueues;
}

Broker& Broker::setMsgTotalEnqueues(const uint64_t value) {
  msgTotalEnqueues = value;

  return *this;
}

uint64_t Broker::getMsgTxnDequeues() const {
  return msgTxnDequeues;
}

Broker& Broker::setMsgTxnDequeues(const uint64_t value) {
  msgTxnDequeues = value;

  return *this;
}

uint64_t Broker::getMsgTxnEnqueues() const {
  return msgTxnEnqueues;
}

Broker& Broker::setMsgTxnEnqueues(const uint64_t value) {
  msgTxnEnqueues = value;

  return *this;
}

uint64_t Broker::getQueueCount() const {
  return queueCount;
}

Broker& Broker::setQueueCount(const uint64_t value) {
  queueCount = value;

  return *this;
}

uint64_t Broker::getReleases() const {
  return releases;
}

Broker& Broker::setReleases(const uint64_t value) {
  releases = value;

  return *this;
}

uint64_t Broker::getReroutes() const {
  return reroutes;
}

Broker& Broker::setReroutes(const uint64_t value) {
  reroutes = value;

  return *this;
}

uint32_t Broker::getStagingThreshold() const {
  return stagingThreshold;
}

Broker& Broker::setStagingThreshold(const uint32_t value) {
  stagingThreshold = value;

  return *this;
}

uint16_t Broker::getPort() const {
  return port;
}

Broker& Broker::setPort(const uint16_t value) {
  port = value;

  return *this;
}

uint16_t Broker::getWorkerThreads() const {
  return workerThreads;
}

Broker& Broker::setWorkerThreads(const uint16_t value) {
  workerThreads = value;

  return *this;
}

bool Broker::getMgmtPublish() const {
  return mgmtPublish;
}

Broker& Broker::setMgmtPublish(bool value) {
  mgmtPublish = value;

  return *this;
}

const std::string& Broker::getDataDir() const {
  return dataDir;
}

Broker& Broker::setDataDir(const std::string& value) {
  dataDir = value;

  return *this;
}

const std::string& Broker::getName() const {
  return name;
}

Broker& Broker::setName(const std::string& value) {
  name = value;

  return *this;
}

const std::string& Broker::getSystemRef() const {
  return systemRef;
}

Broker& Broker::setSystemRef(const std::string& value) {
  systemRef = value;

  return *this;
}

const std::string& Broker::getVersion() const {
  return version;
}

Broker& Broker::setVersion(const std::string& value) {
  version = value;

  return *this;
}

const std::chrono::nanoseconds Broker::getUptime() const {
  return uptime;
}

Broker& Broker::setUptime(const std::chrono::nanoseconds& value) {
  uptime = value;

  return *this;
}

}} // Namespaces
