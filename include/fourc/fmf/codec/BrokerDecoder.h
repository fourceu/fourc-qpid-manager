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

#ifndef FOURC_QPID_MANAGER_BROKERDECODER_H
#define FOURC_QPID_MANAGER_BROKERDECODER_H

#include "../Broker.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class BrokerDecoder : public Decoder<Broker, VariantT> {
public:
  static const std::string PROPERTY_NAME_ABANDONED;
  static const std::string PROPERTY_NAME_ABANDONED_VIA_ALT;
  static const std::string PROPERTY_NAME_ACQUIRES;
  static const std::string PROPERTY_NAME_BYTE_DEPTH;
  static const std::string PROPERTY_NAME_BYTE_FTD_DEPTH;
  static const std::string PROPERTY_NAME_BYTE_FTD_DEQUEUES;
  static const std::string PROPERTY_NAME_BYTE_FTD_ENQUEUES;
  static const std::string PROPERTY_NAME_BYTE_PERSIST_DEQUEUES;
  static const std::string PROPERTY_NAME_BYTE_PERSIST_ENQUEUES;
  static const std::string PROPERTY_NAME_BYTE_TOTAL_DEQUEUES;
  static const std::string PROPERTY_NAME_BYTE_TOTAL_ENQUEUES;
  static const std::string PROPERTY_NAME_BYTE_TXN_DEQUEUES;
  static const std::string PROPERTY_NAME_BYTE_TXN_ENQUEUES;
  static const std::string PROPERTY_NAME_CONN_BACKLOG;
  static const std::string PROPERTY_NAME_DISCARDS_LVQ;
  static const std::string PROPERTY_NAME_DISCARDS_NO_ROUTE;
  static const std::string PROPERTY_NAME_DISCARDS_OVERFLOW;
  static const std::string PROPERTY_NAME_DISCARDS_PURGE;
  static const std::string PROPERTY_NAME_DISCARDS_RING;
  static const std::string PROPERTY_NAME_DISCARDS_SUBSCRIBER;
  static const std::string PROPERTY_NAME_DISCARDS_TTL;
  static const std::string PROPERTY_NAME_MAX_CONNS;
  static const std::string PROPERTY_NAME_MGMT_PUB_INTERVAL;
  static const std::string PROPERTY_NAME_MGMT_PUBLISH;
  static const std::string PROPERTY_NAME_MSG_DEPTH;
  static const std::string PROPERTY_NAME_MSG_FTD_DEPTH;
  static const std::string PROPERTY_NAME_MSG_FTD_DEQUEUES;
  static const std::string PROPERTY_NAME_MSG_FTD_ENQUEUES;
  static const std::string PROPERTY_NAME_MSG_PERSIST_DEQUEUES;
  static const std::string PROPERTY_NAME_MSG_PERSIST_ENQUEUES;
  static const std::string PROPERTY_NAME_MSG_TOTAL_DEQUEUES;
  static const std::string PROPERTY_NAME_MSG_TOTAL_ENQUEUES;
  static const std::string PROPERTY_NAME_MSG_TXN_DEQUEUES;
  static const std::string PROPERTY_NAME_MSG_TXN_ENQUEUES;
  static const std::string PROPERTY_NAME_QUEUE_COUNT;
  static const std::string PROPERTY_NAME_RELEASES;
  static const std::string PROPERTY_NAME_REROUTES;
  static const std::string PROPERTY_NAME_STAGING_THRESHOLD;
  static const std::string PROPERTY_NAME_PORT;
  static const std::string PROPERTY_NAME_WORKER_THREADS;
  static const std::string PROPERTY_NAME_DATA_DIR;
  static const std::string PROPERTY_NAME_SYSTEM_REF;
  static const std::string PROPERTY_NAME_NAME;
  static const std::string PROPERTY_NAME_VERSION;
  static const std::string PROPERTY_NAME_UPTIME;
  
  typedef typename VariantT::Map MapT;
  
  virtual ~BrokerDecoder() = default;

  std::shared_ptr<Broker> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();
    
    auto system_ref_map = this->getMapProperty(values, PROPERTY_NAME_SYSTEM_REF, true).asMap();

    auto uptime = std::chrono::nanoseconds(this->getMapProperty(values, PROPERTY_NAME_UPTIME).asInt64());
    
    decoded->setAbandoned(this->getMapProperty(values, PROPERTY_NAME_ABANDONED))
      .setAbandonedViaAlt(this->getMapProperty(values, PROPERTY_NAME_ABANDONED_VIA_ALT))
      .setAcquires(this->getMapProperty(values, PROPERTY_NAME_ACQUIRES))
      .setByteDepth(this->getMapProperty(values, PROPERTY_NAME_BYTE_DEPTH))
      .setByteFtdDepth(this->getMapProperty(values, PROPERTY_NAME_BYTE_FTD_DEPTH))
      .setByteFtdDequeues(this->getMapProperty(values, PROPERTY_NAME_BYTE_FTD_DEQUEUES))
      .setByteFtdEnqueues(this->getMapProperty(values, PROPERTY_NAME_BYTE_FTD_ENQUEUES))
      .setBytePersistDequeues(this->getMapProperty(values, PROPERTY_NAME_BYTE_PERSIST_DEQUEUES))
      .setBytePersistEnqueues(this->getMapProperty(values, PROPERTY_NAME_BYTE_PERSIST_ENQUEUES))
      .setByteTotalDequeues(this->getMapProperty(values, PROPERTY_NAME_BYTE_TOTAL_DEQUEUES))
      .setByteTotalEnqueues(this->getMapProperty(values, PROPERTY_NAME_BYTE_TOTAL_ENQUEUES))
      .setByteTxnDequeues(this->getMapProperty(values, PROPERTY_NAME_BYTE_TXN_DEQUEUES))
      .setByteTxnEnqueues(this->getMapProperty(values, PROPERTY_NAME_BYTE_TXN_ENQUEUES))
      .setConnBacklog(this->getMapProperty(values, PROPERTY_NAME_CONN_BACKLOG))
      .setDataDir(this->getMapProperty(values, PROPERTY_NAME_DATA_DIR))
      .setDiscardsLvq(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_LVQ))
      .setDiscardsNoRoute(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_NO_ROUTE))
      .setDiscardsOverflow(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_OVERFLOW))
      .setDiscardsPurge(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_PURGE))
      .setDiscardsRing(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_RING))
      .setDiscardsSubscriber(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_SUBSCRIBER))
      .setDiscardsTtl(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_TTL))
      .setMaxConns(this->getMapProperty(values, PROPERTY_NAME_MAX_CONNS))
      .setMgmtPubInterval(this->getMapProperty(values, PROPERTY_NAME_MGMT_PUB_INTERVAL))
      .setMgmtPublish(this->getMapProperty(values, PROPERTY_NAME_MGMT_PUBLISH))
      .setMsgDepth(this->getMapProperty(values, PROPERTY_NAME_MSG_DEPTH))
      .setMsgFtdDepth(this->getMapProperty(values, PROPERTY_NAME_MSG_FTD_DEPTH))
      .setMsgFtdDequeues(this->getMapProperty(values, PROPERTY_NAME_MSG_FTD_DEQUEUES))
      .setMsgFtdEnqueues(this->getMapProperty(values, PROPERTY_NAME_MSG_FTD_ENQUEUES))
      .setMsgPersistDequeues(this->getMapProperty(values, PROPERTY_NAME_MSG_PERSIST_DEQUEUES))
      .setMsgPersistEnqueues(this->getMapProperty(values, PROPERTY_NAME_MSG_PERSIST_ENQUEUES))
      .setMsgTotalDequeues(this->getMapProperty(values, PROPERTY_NAME_MSG_TOTAL_DEQUEUES))
      .setMsgTotalEnqueues(this->getMapProperty(values, PROPERTY_NAME_MSG_TOTAL_ENQUEUES))
      .setMsgTxnDequeues(this->getMapProperty(values, PROPERTY_NAME_MSG_TXN_DEQUEUES))
      .setMsgTxnEnqueues(this->getMapProperty(values, PROPERTY_NAME_MSG_TXN_ENQUEUES))
      .setQueueCount(this->getMapProperty(values, PROPERTY_NAME_QUEUE_COUNT))
      .setReleases(this->getMapProperty(values, PROPERTY_NAME_RELEASES))
      .setReroutes(this->getMapProperty(values, PROPERTY_NAME_REROUTES))
      .setStagingThreshold(this->getMapProperty(values, PROPERTY_NAME_STAGING_THRESHOLD))
      .setPort(this->getMapProperty(values, PROPERTY_NAME_PORT))
      .setWorkerThreads(this->getMapProperty(values, PROPERTY_NAME_WORKER_THREADS))
      .setDataDir(this->getMapProperty(values, PROPERTY_NAME_DATA_DIR))
      .setName(this->getMapProperty(values, PROPERTY_NAME_NAME))
      .setSystemRef(this->getMapProperty(system_ref_map, RPNs::OBJECT_NAME))
      .setVersion(this->getMapProperty(values, PROPERTY_NAME_VERSION))
      .setUptime(uptime);
          
    return decoded;
  }
};

template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_ABANDONED = "abandoned";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_ABANDONED_VIA_ALT = "abandonedViaAlt";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_ACQUIRES = "acquires";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_DEPTH = "byteDepth";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_FTD_DEPTH = "byteFtdDepth";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_FTD_DEQUEUES = "byteFtdDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_FTD_ENQUEUES = "byteFtdEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_PERSIST_DEQUEUES = "bytePersistDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_PERSIST_ENQUEUES = "bytePersistEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_TOTAL_DEQUEUES = "byteTotalDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_TOTAL_ENQUEUES = "byteTotalEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_TXN_DEQUEUES = "byteTxnDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_BYTE_TXN_ENQUEUES = "byteTxnEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_CONN_BACKLOG = "connBacklog";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_LVQ = "discardsLvq";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_NO_ROUTE = "discardsNoRoute";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_OVERFLOW = "discardsOverflow";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_PURGE = "discardsPurge";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_RING = "discardsRing";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_SUBSCRIBER = "discardsSubscriber";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DISCARDS_TTL = "discardsTtl";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MAX_CONNS = "maxConns";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MGMT_PUB_INTERVAL = "mgmtPubInterval";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MGMT_PUBLISH = "mgmtPublish";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_DEPTH = "msgDepth";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_FTD_DEPTH = "msgFtdDepth";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_FTD_DEQUEUES = "msgFtdDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_FTD_ENQUEUES = "msgFtdEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_PERSIST_DEQUEUES = "msgPersistDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_PERSIST_ENQUEUES = "msgPersistEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_TOTAL_DEQUEUES = "msgTotalDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_TOTAL_ENQUEUES = "msgTotalEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_TXN_DEQUEUES = "msgTxnDequeues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_MSG_TXN_ENQUEUES = "msgTxnEnqueues";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_QUEUE_COUNT = "queueCount";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_RELEASES = "releases";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_REROUTES = "reroutes";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_STAGING_THRESHOLD = "stagingThreshold";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_PORT = "port";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_WORKER_THREADS = "workerThreads";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_DATA_DIR = "dataDir";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_SYSTEM_REF = "systemRef";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_NAME = "name";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_VERSION = "version";
template <typename VariantT> const std::string BrokerDecoder<VariantT>::PROPERTY_NAME_UPTIME = "uptime";

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_BROKERDECODER_H
