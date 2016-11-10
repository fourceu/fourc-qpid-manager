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

#ifndef FOURC_FMF_QUEUEDECODER_H
#define FOURC_FMF_QUEUEDECODER_H

#include "../Queue.h"
#include "Decoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename VariantT>
class QueueDecoder : public Decoder<Queue, VariantT> {
public:
  typedef typename VariantT::Map MapT;

  static const std::string PROPERTY_NAME_ACQUIRES;
  static const std::string PROPERTY_NAME_AUTO_DELETE;
  static const std::string PROPERTY_NAME_BINDING_COUNT;
  static const std::string PROPERTY_NAME_BINDING_COUNT_HIGH;
  static const std::string PROPERTY_NAME_BINDING_COUNT_LOW;
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
  static const std::string PROPERTY_NAME_CONSUMER_COUNT;
  static const std::string PROPERTY_NAME_CONSUMER_COUNT_HIGH;
  static const std::string PROPERTY_NAME_CONSUMER_COUNT_LOW;
  static const std::string PROPERTY_NAME_CREATOR;
  static const std::string PROPERTY_NAME_DISCARDS_LVQ;
  static const std::string PROPERTY_NAME_DISCARDS_OVERFLOW;
  static const std::string PROPERTY_NAME_DISCARDS_PURGE;
  static const std::string PROPERTY_NAME_DISCARDS_RING;
  static const std::string PROPERTY_NAME_DISCARDS_SUBSCRIBER;
  static const std::string PROPERTY_NAME_DISCARDS_TTL;
  static const std::string PROPERTY_NAME_EXCLUSIVE;
  static const std::string PROPERTY_NAME_FLOW_STOPPED;
  static const std::string PROPERTY_NAME_FLOW_STOPPED_COUNT;
  static const std::string PROPERTY_NAME_MESSAGE_LATENCY_AVG;
  static const std::string PROPERTY_NAME_MESSAGE_LATENCY_COUNT;
  static const std::string PROPERTY_NAME_MESSAGE_LATENCY_MAX;
  static const std::string PROPERTY_NAME_MESSAGE_LATENCY_MIN;
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
  static const std::string PROPERTY_NAME_REDIRECT_PEER;
  static const std::string PROPERTY_NAME_REDIRECT_SOURCE;
  static const std::string PROPERTY_NAME_RELEASES;
  static const std::string PROPERTY_NAME_REROUTES;
  static const std::string PROPERTY_NAME_UNACKED_MESSSAGES;
  static const std::string PROPERTY_NAME_UNACKED_MESSSAGES_HIGH;
  static const std::string PROPERTY_NAME_UNACKED_MESSSAGES_LOW;
  
  virtual ~QueueDecoder() = default;

  std::shared_ptr<Queue> decode(const MapT &objectProperties) const {
    auto decoded = this->createObject(objectProperties);

    auto values = this->getMapProperty(objectProperties, RPNs::VALUES, true).asMap();

    decoded->setAcquires(this->getMapProperty(values, PROPERTY_NAME_ACQUIRES))
        .setAutoDelete(this->getMapProperty(values, PROPERTY_NAME_AUTO_DELETE))
        .setBindingCount(this->getMapProperty(values, PROPERTY_NAME_BINDING_COUNT))
        .setBindingCountHigh(this->getMapProperty(values, PROPERTY_NAME_BINDING_COUNT_HIGH))
        .setBindingCountLow(this->getMapProperty(values, PROPERTY_NAME_BINDING_COUNT_LOW))
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
        .setConsumerCount(this->getMapProperty(values, PROPERTY_NAME_CONSUMER_COUNT))
        .setConsumerCountHigh(this->getMapProperty(values, PROPERTY_NAME_CONSUMER_COUNT_HIGH))
        .setConsumerCountLow(this->getMapProperty(values, PROPERTY_NAME_CONSUMER_COUNT_LOW))
        .setCreator(this->getMapProperty(values, PROPERTY_NAME_CREATOR))
        .setDiscardsLvq(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_LVQ))
        .setDiscardsOverflow(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_OVERFLOW))
        .setDiscardsPurge(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_PURGE))
        .setDiscardsRing(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_RING))
        .setDiscardsSubscriber(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_SUBSCRIBER))
        .setDiscardsTtl(this->getMapProperty(values, PROPERTY_NAME_DISCARDS_TTL))
        .setDurable(this->getMapProperty(values, RPNs::DURABLE))
        .setExclusive(this->getMapProperty(values, PROPERTY_NAME_EXCLUSIVE))
        .setFlowStopped(this->getMapProperty(values, PROPERTY_NAME_FLOW_STOPPED))
        .setFlowStoppedCount(this->getMapProperty(values, PROPERTY_NAME_FLOW_STOPPED_COUNT))
        .setMessageLatencyAvg(this->getMapProperty(values, PROPERTY_NAME_MESSAGE_LATENCY_AVG))
        .setMessageLatencyCount(this->getMapProperty(values, PROPERTY_NAME_MESSAGE_LATENCY_COUNT))
        .setMessageLatencyMax(this->getMapProperty(values, PROPERTY_NAME_MESSAGE_LATENCY_MAX))
        .setMessageLatencyMin(this->getMapProperty(values, PROPERTY_NAME_MESSAGE_LATENCY_MIN))
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
        .setName(this->getMapProperty(values, RPNs::NAME))
        .setRedirectPeer(this->getMapProperty(values, PROPERTY_NAME_REDIRECT_PEER))
        .setRedirectSource(this->getMapProperty(values, PROPERTY_NAME_REDIRECT_SOURCE))
        .setReleases(this->getMapProperty(values, PROPERTY_NAME_RELEASES))
        .setReroutes(this->getMapProperty(values, PROPERTY_NAME_REROUTES))
        .setUnackedMessages(this->getMapProperty(values, PROPERTY_NAME_UNACKED_MESSSAGES))
        .setUnackedMessagesHigh(this->getMapProperty(values, PROPERTY_NAME_UNACKED_MESSSAGES_HIGH))
        .setUnackedMessagesLow(this->getMapProperty(values, PROPERTY_NAME_UNACKED_MESSSAGES_LOW))
        .setVhostRef(this->decodeVhostRef(values));

    return decoded;
  }
};

template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_ACQUIRES = "acquires";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_AUTO_DELETE = "autoDelete";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BINDING_COUNT = "bindingCount";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BINDING_COUNT_HIGH = "bindingCountHigh";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BINDING_COUNT_LOW = "bindingCountLow";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_DEPTH = "byteDepth";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_FTD_DEPTH = "byteFtdDepth";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_FTD_DEQUEUES = "byteFtdDequeues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_FTD_ENQUEUES = "byteFtdEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_PERSIST_DEQUEUES = "bytePersistDequeues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_PERSIST_ENQUEUES = "bytePersistEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_TOTAL_DEQUEUES = "byteTotalDequeues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_TOTAL_ENQUEUES = "byteTotalEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_TXN_DEQUEUES = "byteTxnDequeues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_BYTE_TXN_ENQUEUES = "byteTxnEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_CONSUMER_COUNT = "consumerCount";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_CONSUMER_COUNT_HIGH = "consumerCountHigh";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_CONSUMER_COUNT_LOW = "consumerCountLow";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_CREATOR = "creator";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_DISCARDS_LVQ = "discardsLvq";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_DISCARDS_OVERFLOW = "discardsOverflow";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_DISCARDS_PURGE = "discardsPurge";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_DISCARDS_RING = "discardsRing";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_DISCARDS_SUBSCRIBER = "discardsSubscriber";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_DISCARDS_TTL = "discardsTtl";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_EXCLUSIVE = "exclusive";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_FLOW_STOPPED = "flowStopped";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_FLOW_STOPPED_COUNT = "flowStoppedCount";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MESSAGE_LATENCY_AVG = "messageLatencyAvg";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MESSAGE_LATENCY_COUNT = "messageLatencyCount";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MESSAGE_LATENCY_MAX = "messageLatencyMax";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MESSAGE_LATENCY_MIN = "messageLatencyMin";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_DEPTH = "msgDepth";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_FTD_DEPTH = "msgFtdDepth";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_FTD_DEQUEUES = "msgFtdDequeues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_FTD_ENQUEUES = "msgFtdEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_PERSIST_DEQUEUES = "msgPersistDequeus";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_PERSIST_ENQUEUES = "msgPersistEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_TOTAL_DEQUEUES = "msgTotalDequeus";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_TOTAL_ENQUEUES = "msgTotalEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_TXN_DEQUEUES = "msgTxnDequeus";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_MSG_TXN_ENQUEUES = "msgTxnEnqueues";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_REDIRECT_PEER = "redirectPeer";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_REDIRECT_SOURCE = "redirectSource";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_RELEASES = "releases";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_REROUTES = "reroutes";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_UNACKED_MESSSAGES = "unackedMessages";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_UNACKED_MESSSAGES_HIGH = "unackedMessagesHigh";
template<typename VariantT> const std::string QueueDecoder<VariantT>::PROPERTY_NAME_UNACKED_MESSSAGES_LOW = "unackedMessagesLow";

}}} // Namespaces

#endif //FOURC_FMF_QUEUEDECODER_H
