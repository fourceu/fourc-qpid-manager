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
#include <fourc/fmf/codec/QueueDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestQueueDecoder_VariantReferenceMap : public QueueDecoder<subsystem::mocks::ReferenceVariant> {
public:
};

TEST(QueueDecoderTests, ctor) {
  auto instance = new QueueDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(QueueDecoderTests, dynamicCast) {
  auto instance = new QueueDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Queue, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(QueueDecoderTests, decodeQueue) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  int agent_epoch = 10;

  std::string schema_class = "queue";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.queue";
  std::string schema_type = "_data";
  
  uint64_t acquires = 1;
  bool auto_delete = true;
  uint32_t binding_count = 2;
  uint32_t binding_count_high = 3;
  uint32_t binding_count_low = 4;
  uint64_t byte_depth = 5;
  uint64_t byte_ftd_depth = 6;
  uint64_t byte_ftd_dequeues = 7;
  uint64_t byte_ftd_enqueues = 8;
  uint64_t byte_persist_dequeues = 9;
  uint64_t byte_persist_enqueues = 10;
  uint64_t byte_total_dequeues = 11;
  uint64_t byte_total_enqueues = 12;
  uint64_t byte_txn_dequeues = 13;
  uint64_t byte_txn_enqueues = 14;
  uint32_t consumer_count = 15;
  uint32_t consumer_count_high = 16;
  uint32_t consumer_count_low = 17;
  std::string creator = "test creator";
  uint64_t discards_lvq = 18;
  uint64_t discards_overflow = 19;
  uint64_t discards_purge = 20;
  uint64_t discards_ring = 21;
  uint64_t discards_subscriber = 22;
  uint64_t discards_ttl = 23;
  bool durable = true;
  bool exclusive = true;
  bool flow_stopped = true;
  uint64_t flow_stopped_count = 24;
  uint64_t message_latency_avg = 25;
  uint64_t message_latency_count = 26;
  uint64_t message_latency_max = 28;
  uint64_t message_latency_min = 29;
  uint64_t msg_depth = 30;
  uint64_t msg_ftd_depth = 31;
  uint64_t msg_ftd_dequeues = 32;
  uint64_t msg_ftd_enqueues = 33;
  uint64_t msg_persist_dequeues = 34;
  uint64_t msg_persist_enqueues = 35;
  uint64_t msg_total_dequeues = 36;
  uint64_t msg_total_enqueues = 37;
  uint64_t msg_txn_dequeues = 38;
  uint64_t msg_txn_enqueues = 39;
  std::string name = "test name";
  std::string redirect_peer = "test redirect peer";
  bool redirect_source = true;
  uint64_t releases = 40;
  uint64_t reroutes = 41;
  uint64_t unacked_messages = 42;
  uint64_t unacked_messages_high = 43;
  uint64_t unacked_messages_low = 44;
  std::string vhost_ref = "test vhost ref";

  qpid::types::Variant::Map object_id = {
      { RPNs::OBJECT_NAME, oid },
      { RPNs::OBJECT_AGENT_EPOCH, agent_epoch }
  };

  qpid::types::Variant::Map schema_id = {
      { RPNs::SCHEMA_CLASS_NAME, schema_class },
      { RPNs::SCHEMA_HASH, schema_hash },
      { RPNs::SCHEMA_PACKAGE_NAME, schema_package_name },
      { RPNs::SCHEMA_TYPE, schema_type }
  };

  qpid::types::Variant::Map vhost_ref_map = {
      { RPNs::OBJECT_NAME, vhost_ref }
  };

  qpid::types::Variant::Map values = {
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_ACQUIRES, acquires },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_AUTO_DELETE, auto_delete },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_COUNT, binding_count },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_COUNT_HIGH, binding_count_high },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BINDING_COUNT_LOW, binding_count_low },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_DEPTH, byte_depth },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_FTD_DEPTH, byte_ftd_depth },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_FTD_DEQUEUES, byte_ftd_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_FTD_ENQUEUES, byte_ftd_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_PERSIST_DEQUEUES, byte_persist_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_PERSIST_ENQUEUES, byte_persist_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TOTAL_DEQUEUES, byte_total_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TOTAL_ENQUEUES, byte_total_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TXN_DEQUEUES, byte_txn_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TXN_ENQUEUES, byte_txn_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_CONSUMER_COUNT, consumer_count },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_CONSUMER_COUNT_HIGH, consumer_count_high },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_CONSUMER_COUNT_LOW, consumer_count_low },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_CREATOR, creator },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_LVQ, discards_lvq },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_OVERFLOW, discards_overflow },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_PURGE, discards_purge },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_RING, discards_ring },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_SUBSCRIBER, discards_subscriber },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_TTL, discards_ttl },
      { RPNs::DURABLE, durable },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_EXCLUSIVE, exclusive },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_FLOW_STOPPED, flow_stopped },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_FLOW_STOPPED_COUNT, flow_stopped_count },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MESSAGE_LATENCY_AVG, message_latency_avg },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MESSAGE_LATENCY_COUNT, message_latency_count },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MESSAGE_LATENCY_MAX, message_latency_max },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MESSAGE_LATENCY_MIN, message_latency_min },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_DEPTH, msg_depth },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_FTD_DEPTH, msg_ftd_depth },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_FTD_DEQUEUES, msg_ftd_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_FTD_ENQUEUES, msg_ftd_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_PERSIST_DEQUEUES, msg_persist_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_PERSIST_ENQUEUES, msg_persist_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TOTAL_DEQUEUES, msg_total_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TOTAL_ENQUEUES, msg_total_enqueues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TXN_DEQUEUES, msg_txn_dequeues },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TXN_ENQUEUES, msg_txn_enqueues },
      { RPNs::NAME, name },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_REDIRECT_PEER, redirect_peer },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_REDIRECT_SOURCE, redirect_source },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_RELEASES, releases },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_REROUTES, reroutes },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_UNACKED_MESSSAGES, unacked_messages },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_UNACKED_MESSSAGES_HIGH, unacked_messages_high },
      { QueueDecoder<qpid::types::Variant>::PROPERTY_NAME_UNACKED_MESSSAGES_LOW, unacked_messages_low },
      { RPNs::VHOST_REF, vhost_ref_map }
  };

  qpid::types::Variant::Map objectProperties = {
      { RPNs::CREATED, now_tp.time_since_epoch().count() },
      { RPNs::DELETED, 0 },
      { RPNs::UPDATED, 0 },
      { RPNs::OBJECT_ID, object_id },
      { RPNs::SCHEMA_ID, schema_id },
      { RPNs::VALUES, values }
  };

  QueueDecoder<qpid::types::Variant> decoder;

  auto queue = decoder.decode(objectProperties);

  EXPECT_TRUE(queue);

  EXPECT_EQ(now_tp, queue->getTimeCreated());
  EXPECT_EQ(0, queue->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, queue->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, queue->getObjectId().getName());
  EXPECT_EQ(agent_epoch, queue->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, queue->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, queue->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, queue->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, queue->getSchemaId().getType());

  EXPECT_EQ(acquires, queue->getAcquires());
  EXPECT_EQ(auto_delete, queue->isAutoDelete());
  EXPECT_EQ(binding_count, queue->getBindingCount());
  EXPECT_EQ(binding_count_high, queue->getBindingCountHigh());
  EXPECT_EQ(binding_count_low, queue->getBindingCountLow());
  EXPECT_EQ(byte_depth, queue->getByteDepth());
  EXPECT_EQ(byte_ftd_depth, queue->getByteFtdDepth());
  EXPECT_EQ(byte_ftd_dequeues, queue->getByteFtdDequeues());
  EXPECT_EQ(byte_ftd_enqueues, queue->getByteFtdEnqueues());
  EXPECT_EQ(byte_persist_dequeues, queue->getBytePersistDequeues());
  EXPECT_EQ(byte_persist_enqueues, queue->getBytePersistEnqueues());
  EXPECT_EQ(byte_total_dequeues, queue->getByteTotalDequeues());
  EXPECT_EQ(byte_total_enqueues, queue->getByteTotalEnqueues());
  EXPECT_EQ(byte_txn_dequeues, queue->getByteTxnDequeues());
  EXPECT_EQ(byte_txn_enqueues, queue->getByteTxnEnqueues());
  EXPECT_EQ(consumer_count, queue->getConsumerCount());
  EXPECT_EQ(consumer_count_high, queue->getConsumerCountHigh());
  EXPECT_EQ(consumer_count_low, queue->getConsumerCountLow());
  EXPECT_EQ(creator, queue->getCreator());
  EXPECT_EQ(discards_lvq, queue->getDiscardsLvq());
  EXPECT_EQ(discards_overflow, queue->getDiscardsOverflow());
  EXPECT_EQ(discards_purge, queue->getDiscardsPurge());
  EXPECT_EQ(discards_ring, queue->getDiscardsRing());
  EXPECT_EQ(discards_subscriber, queue->getDiscardsSubscriber());
  EXPECT_EQ(discards_ttl, queue->getDiscardsTtl());
  EXPECT_EQ(durable, queue->isDurable());
  EXPECT_EQ(exclusive, queue->isExclusive());
  EXPECT_EQ(flow_stopped, queue->isFlowStopped());
  EXPECT_EQ(flow_stopped_count, queue->getFlowStoppedCount());
  EXPECT_EQ(message_latency_avg, queue->getMessageLatencyAvg());
  EXPECT_EQ(message_latency_count, queue->getMessageLatencyCount());
  EXPECT_EQ(message_latency_max, queue->getMessageLatencyMax());
  EXPECT_EQ(message_latency_min, queue->getMessageLatencyMin());
  EXPECT_EQ(msg_depth, queue->getMsgDepth());
  EXPECT_EQ(msg_ftd_depth, queue->getMsgFtdDepth());
  EXPECT_EQ(msg_ftd_dequeues, queue->getMsgFtdDequeues());
  EXPECT_EQ(msg_ftd_enqueues, queue->getMsgFtdEnqueues());
  EXPECT_EQ(msg_persist_dequeues, queue->getMsgPersistDequeues());
  EXPECT_EQ(msg_persist_enqueues, queue->getMsgPersistEnqueues());
  EXPECT_EQ(msg_total_dequeues, queue->getMsgTotalDequeues());
  EXPECT_EQ(msg_total_enqueues, queue->getMsgTotalEnqueues());
  EXPECT_EQ(msg_txn_dequeues, queue->getMsgTxnDequeues());
  EXPECT_EQ(msg_txn_enqueues, queue->getMsgTxnEnqueues());
  EXPECT_EQ(name, queue->getName());
  EXPECT_EQ(redirect_peer, queue->getRedirectPeer());
  EXPECT_EQ(redirect_source, queue->isRedirectSource());
  EXPECT_EQ(releases, queue->getReleases());
  EXPECT_EQ(reroutes, queue->getReroutes());
  EXPECT_EQ(unacked_messages, queue->getUnackedMessages());
  EXPECT_EQ(unacked_messages_high, queue->getUnackedMessagesHigh());
  EXPECT_EQ(unacked_messages_low, queue->getUnackedMessagesLow());
  EXPECT_EQ(vhost_ref, queue->getVhostRef());

}


// Problems with mocking maps
//TEST(QueueDecoderTests, decodeDurableQueue) {
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = true;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { RPNs::NAME, name_value },
//      { RPNs::DURABLE, durable_value }
//  };
//  const subsystem::mocks::ReferenceVariant values(values_map);
//  EXPECT_CALL(values, asMap()).WillOnce(ReturnRef(values_map));
//
//  const subsystem::mocks::ReferenceVariant::Map objectProperties = {
//      { RPNs::VALUES, values }
//  };
//
//  // This is what we should get back from the codec
//  auto expected = std::make_shared<Queue>();
//
//  TestQueueDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}
//
//TEST(QueueDecoderTests, decodeNondurableQueue) {
//  std::string name = "test name";
//  const subsystem::mocks::ReferenceVariant name_value;
//  EXPECT_CALL(name_value, asString()).WillOnce(Return(name));
//
//  bool durable = false;
//  const subsystem::mocks::ReferenceVariant durable_value;
//  EXPECT_CALL(durable_value, asBool()).WillOnce(Return(durable));
//
//  const subsystem::mocks::ReferenceVariant::Map values_map = {
//      { RPNs::NAME, name_value },
//      { RPNs::DURABLE, durable_value }
//  };
//  const subsystem::mocks::ReferenceVariant values(values_map);
//  EXPECT_CALL(values, asMap()).WillOnce(ReturnRef(values_map));
//
//  const subsystem::mocks::ReferenceVariant::Map objectProperties = {
//      { RPNs::VALUES, values }
//  };
//
//  // This is what we should get back from the codec
//  auto expected = std::make_shared<Queue>();
//
//  TestQueueDecoder_VariantReferenceMap decoder;
//
//  auto actual = decoder.decode(objectProperties);
//
//  EXPECT_EQ(*expected, *actual);
//}