/*
 * Copyright (C) 2016 FourC AS, http://www.fourc.eu/
 * All Rights Reserved.
 */

#ifndef FOURC_FMF_BROKER_H
#define FOURC_FMF_BROKER_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Broker : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Broker();

  uint64_t getAbandoned() const;
  Broker& setAbandoned(const uint64_t);

  uint64_t getAbandonedViaAlt() const;
  Broker& setAbandonedViaAlt(const uint64_t);

  uint64_t getAcquires() const;
  Broker& setAcquires(const uint64_t);

  uint64_t getByteDepth() const;
  Broker& setByteDepth(const uint64_t);

  uint64_t getByteFtdDepth() const;
  Broker& setByteFtdDepth(const uint64_t);

  uint64_t getByteFtdDequeues() const;
  Broker& setByteFtdDequeues(const uint64_t);

  uint64_t getByteFtdEnqueues() const;
  Broker& setByteFtdEnqueues(const uint64_t);

  uint64_t getBytePersistDequeues() const;
  Broker& setBytePersistDequeues(const uint64_t);

  uint64_t getBytePersistEnqueues() const;
  Broker& setBytePersistEnqueues(const uint64_t);

  uint64_t getByteTotalDequeues() const;
  Broker& setByteTotalDequeues(const uint64_t);

  uint64_t getByteTotalEnqueues() const;
  Broker& setByteTotalEnqueues(const uint64_t);

  uint64_t getByteTxnDequeues() const;
  Broker& setByteTxnDequeues(const uint64_t);

  uint64_t getByteTxnEnqueues() const;
  Broker& setByteTxnEnqueues(const uint64_t);

  uint16_t getConnBacklog() const;
  Broker& setConnBacklog(const uint16_t);

  uint64_t getDiscardsLvq() const;
  Broker& setDiscardsLvq(const uint64_t);

  uint64_t getDiscardsNoRoute() const;
  Broker& setDiscardsNoRoute(const uint64_t);

  uint64_t getDiscardsOverflow() const;
  Broker& setDiscardsOverflow(const uint64_t);

  uint64_t getDiscardsPurge() const;
  Broker& setDiscardsPurge(const uint64_t);

  uint64_t getDiscardsRing() const;
  Broker& setDiscardsRing(const uint64_t);

  uint64_t getDiscardsSubscriber() const;
  Broker& setDiscardsSubscriber(const uint64_t);

  uint64_t getDiscardsTtl() const;
  Broker& setDiscardsTtl(const uint64_t);

  uint16_t getMaxConns() const;
  Broker& setMaxConns(const uint16_t);

  uint16_t getMgmtPubInterval() const;
  Broker& setMgmtPubInterval(const uint16_t);

  uint64_t getMsgDepth() const;
  Broker& setMsgDepth(const uint64_t);

  uint64_t getMsgFtdDepth() const;
  Broker& setMsgFtdDepth(const uint64_t);

  uint64_t getMsgFtdDequeues() const;
  Broker& setMsgFtdDequeues(const uint64_t);

  uint64_t getMsgFtdEnqueues() const;
  Broker& setMsgFtdEnqueues(const uint64_t);

  uint64_t getMsgPersistDequeues() const;
  Broker& setMsgPersistDequeues(const uint64_t);

  uint64_t getMsgPersistEnqueues() const;
  Broker& setMsgPersistEnqueues(const uint64_t);

  uint64_t getMsgTotalDequeues() const;
  Broker& setMsgTotalDequeues(const uint64_t);

  uint64_t getMsgTotalEnqueues() const;
  Broker& setMsgTotalEnqueues(const uint64_t);

  uint64_t getMsgTxnDequeues() const;
  Broker& setMsgTxnDequeues(const uint64_t);

  uint64_t getMsgTxnEnqueues() const;
  Broker& setMsgTxnEnqueues(const uint64_t);

  uint64_t getQueueCount() const;
  Broker& setQueueCount(const uint64_t);

  uint64_t getReleases() const;
  Broker& setReleases(const uint64_t);

  uint64_t getReroutes() const;
  Broker& setReroutes(const uint64_t);

  uint32_t getStagingThreshold() const;
  Broker& setStagingThreshold(const uint32_t);

  uint16_t getPort() const;
  Broker& setPort(const uint16_t);

  uint16_t getWorkerThreads() const;
  Broker& setWorkerThreads(const uint16_t);

  bool getMgmtPublish() const;
  Broker& setMgmtPublish(bool);

  const std::string& getDataDir() const;
  Broker& setDataDir(const std::string&);

  const std::string& getName() const;
  Broker& setName(const std::string&);

  const std::string& getSystemRef() const;
  Broker& setSystemRef(const std::string&);

  const std::string& getVersion() const;
  Broker& setVersion(const std::string&);

  const std::chrono::nanoseconds getUptime() const;
  Broker& setUptime(const std::chrono::nanoseconds&);

private:
  uint64_t abandoned;
  uint64_t abandonedViaAlt;
  uint64_t acquires;
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
  uint16_t connBacklog;
  uint64_t discardsLvq;
  uint64_t discardsNoRoute;
  uint64_t discardsOverflow;
  uint64_t discardsPurge;
  uint64_t discardsRing;
  uint64_t discardsSubscriber;
  uint64_t discardsTtl;
  uint16_t maxConns;
  uint16_t mgmtPubInterval;
  uint64_t msgDepth;
  uint64_t msgFtdDepth;
  uint64_t msgFtdDequeues;
  uint64_t msgFtdEnqueues;
  uint64_t msgPersistDequeues;
  uint64_t msgPersistEnqueues;
  uint64_t msgTotalDequeues;
  uint64_t msgTotalEnqueues;
  uint64_t msgTxnDequeues;
  uint64_t msgTxnEnqueues;
  uint64_t queueCount;
  uint64_t releases;
  uint64_t reroutes;
  uint32_t stagingThreshold;

  uint16_t port;
  uint16_t workerThreads;

  bool mgmtPublish;

  std::string dataDir;
  std::string name;
  std::string systemRef;
  std::string version;

  std::chrono::nanoseconds uptime;

};

}} // Namespaces

#endif //FOURC_FMF_BROKER_H
