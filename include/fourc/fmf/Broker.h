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

  uint32_t getAbandoned() const;
  Broker& setAbandoned(const uint32_t);

  uint32_t getAbandonedViaAlt() const;
  Broker& setAbandonedViaAlt(const uint32_t);

  uint32_t getAcquires() const;
  Broker& setAcquires(const uint32_t);

  uint32_t getByteDepth() const;
  Broker& setByteDepth(const uint32_t);

  uint32_t getByteFtdDepth() const;
  Broker& setByteFtdDepth(const uint32_t);

  uint32_t getByteFtdDequeues() const;
  Broker& setByteFtdDequeues(const uint32_t);

  uint32_t getByteFtdEnqueues() const;
  Broker& setByteFtdEnqueues(const uint32_t);

  uint32_t getBytePersistDequeues() const;
  Broker& setBytePersistDequeues(const uint32_t);

  uint32_t getBytePersistEnqueues() const;
  Broker& setBytePersistEnqueues(const uint32_t);

  uint32_t getByteTotalDequeues() const;
  Broker& setByteTotalDequeues(const uint32_t);

  uint32_t getByteTotalEnqueues() const;
  Broker& setByteTotalEnqueues(const uint32_t);

  uint32_t getByteTxnDequeues() const;
  Broker& setByteTxnDequeues(const uint32_t);

  uint32_t getByteTxnEnqueues() const;
  Broker& setByteTxnEnqueues(const uint32_t);

  uint32_t getConnBacklog() const;
  Broker& setConnBacklog(const uint32_t);

  uint32_t getDiscardsLvq() const;
  Broker& setDiscardsLvq(const uint32_t);

  uint32_t getDiscardsNoRoute() const;
  Broker& setDiscardsNoRoute(const uint32_t);

  uint32_t getDiscardsOverflow() const;
  Broker& setDiscardsOverflow(const uint32_t);

  uint32_t getDiscardsPurge() const;
  Broker& setDiscardsPurge(const uint32_t);

  uint32_t getDiscardsRing() const;
  Broker& setDiscardsRing(const uint32_t);

  uint32_t getDiscardsSubscriber() const;
  Broker& setDiscardsSubscriber(const uint32_t);

  uint32_t getDiscardsTtl() const;
  Broker& setDiscardsTtl(const uint32_t);

  uint32_t getMaxConns() const;
  Broker& setMaxConns(const uint32_t);

  uint32_t getMgmtPubInterval() const;
  Broker& setMgmtPubInterval(const uint32_t);

  uint32_t getMsgDepth() const;
  Broker& setMsgDepth(const uint32_t);

  uint32_t getMsgFtdDepth() const;
  Broker& setMsgFtdDepth(const uint32_t);

  uint32_t getMsgFtdDequeues() const;
  Broker& setMsgFtdDequeues(const uint32_t);

  uint32_t getMsgFtdEnqueues() const;
  Broker& setMsgFtdEnqueues(const uint32_t);

  uint32_t getMsgPersistDequeues() const;
  Broker& setMsgPersistDequeues(const uint32_t);

  uint32_t getMsgPersistEnqueues() const;
  Broker& setMsgPersistEnqueues(const uint32_t);

  uint32_t getMsgTotalDequeues() const;
  Broker& setMsgTotalDequeues(const uint32_t);

  uint32_t getMsgTotalEnqueues() const;
  Broker& setMsgTotalEnqueues(const uint32_t);

  uint32_t getMsgTxnDequeues() const;
  Broker& setMsgTxnDequeues(const uint32_t);

  uint32_t getMsgTxnEnqueues() const;
  Broker& setMsgTxnEnqueues(const uint32_t);

  uint32_t getQueueCount() const;
  Broker& setQueueCount(const uint32_t);

  uint32_t getReleases() const;
  Broker& setReleases(const uint32_t);

  uint32_t getReroutes() const;
  Broker& setReroutes(const uint32_t);

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
  uint32_t abandoned;
  uint32_t abandonedViaAlt;
  uint32_t acquires;
  uint32_t byteDepth;
  uint32_t byteFtdDepth;
  uint32_t byteFtdDequeues;
  uint32_t byteFtdEnqueues;
  uint32_t bytePersistDequeues;
  uint32_t bytePersistEnqueues;
  uint32_t byteTotalDequeues;
  uint32_t byteTotalEnqueues;
  uint32_t byteTxnDequeues;
  uint32_t byteTxnEnqueues;
  uint32_t connBacklog;
  uint32_t discardsLvq;
  uint32_t discardsNoRoute;
  uint32_t discardsOverflow;
  uint32_t discardsPurge;
  uint32_t discardsRing;
  uint32_t discardsSubscriber;
  uint32_t discardsTtl;
  uint32_t maxConns;
  uint32_t mgmtPubInterval;
  uint32_t msgDepth;
  uint32_t msgFtdDepth;
  uint32_t msgFtdDequeues;
  uint32_t msgFtdEnqueues;
  uint32_t msgPersistDequeues;
  uint32_t msgPersistEnqueues;
  uint32_t msgTotalDequeues;
  uint32_t msgTotalEnqueues;
  uint32_t msgTxnDequeues;
  uint32_t msgTxnEnqueues;
  uint32_t queueCount;
  uint32_t releases;
  uint32_t reroutes;
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
