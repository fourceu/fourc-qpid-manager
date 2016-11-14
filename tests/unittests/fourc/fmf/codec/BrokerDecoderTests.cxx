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
#include <fourc/fmf/codec/BrokerDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestBrokerDecoder_VariantReferenceMap : public BrokerDecoder<subsystem::mocks::ReferenceVariant> {
public:
};

TEST(BrokerDecoderTests, ctor) {
  auto instance = new BrokerDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BrokerDecoderTests, dynamicCast) {
  auto instance = new BrokerDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Broker, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(BrokerDecoderTests, decodeBroker) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  uint64_t agent_epoch = 10;

  std::string schema_class = "broker";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.broker";
  std::string schema_type = "_data";

  uint64_t abandoned = 1;
  uint64_t abandonedViaAlt = 2;
  uint64_t acquires = 3;
  uint64_t byteDepth = 4;
  uint64_t byteFtdDepth = 5;
  uint64_t byteFtdDequeues = 6;
  uint64_t byteFtdEnqueues = 7;
  uint64_t bytePersistDequeues = 8;
  uint64_t bytePersistEnqueues = 9;
  uint64_t byteTotalDequeues = 10;
  uint64_t byteTotalEnqueues = 11;
  uint64_t byteTxnDequeues = 12;
  uint64_t byteTxnEnqueues = 13;
  uint32_t connBacklog = 14;
  uint64_t discardsLvq = 15;
  uint64_t discardsNoRoute = 16;
  uint64_t discardsOverflow = 17;
  uint64_t discardsPurge = 18;
  uint64_t discardsRing = 19;
  uint64_t discardsSubscriber = 20;
  uint64_t discardsTtl = 21;
  uint16_t maxConns = 22;
  uint16_t mgmtPubInterval = 23;
  uint64_t msgDepth = 24;
  uint64_t msgFtdDepth = 25;
  uint64_t msgFtdDequeues = 26;
  uint64_t msgFtdEnqueues = 27;
  uint64_t msgPersistDequeues = 28;
  uint64_t msgPersistEnqueues = 29;
  uint64_t msgTotalDequeues = 30;
  uint64_t msgTotalEnqueues = 31;
  uint64_t msgTxnDequeues = 32;
  uint64_t msgTxnEnqueues = 33;
  uint64_t queueCount = 34;
  uint64_t releases = 35;
  uint64_t reroutes = 36;
  uint32_t stagingThreshold = 37;

  uint16_t port = 38;
  uint16_t workerThreads = 39;

  bool mgmtPublish = false;

  std::string dataDir = "test data dir";
  std::string name = "test name";
  std::string version = "1.2.3.4";

  auto uptime = std::chrono::nanoseconds(54672);
  std::string system_ref = "org.apache.qpid.broker:system:6a98d5b1-1cd1-4200-8323-c88ac5502821";

  qpid::types::Variant::Map object_id = {
      {ResponsePropertyNames::OBJECT_NAME,        oid},
      {ResponsePropertyNames::OBJECT_AGENT_EPOCH, agent_epoch}
  };

  qpid::types::Variant::Map schema_id = {
      {ResponsePropertyNames::SCHEMA_CLASS_NAME,   schema_class},
      {ResponsePropertyNames::SCHEMA_HASH,         schema_hash},
      {ResponsePropertyNames::SCHEMA_PACKAGE_NAME, schema_package_name},
      {ResponsePropertyNames::SCHEMA_TYPE,         schema_type},
  };

  qpid::types::Variant::Map system_ref_map = {
      {ResponsePropertyNames::OBJECT_NAME, system_ref}
  };

  qpid::types::Variant::Map values = {
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_ABANDONED, abandoned },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_ABANDONED_VIA_ALT, abandonedViaAlt },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_ACQUIRES, acquires },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_DEPTH, byteDepth },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_FTD_DEPTH, byteFtdDepth },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_FTD_DEQUEUES, byteFtdDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_FTD_ENQUEUES, byteFtdEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_PERSIST_DEQUEUES, bytePersistDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_PERSIST_ENQUEUES, bytePersistEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TOTAL_DEQUEUES, byteTotalDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TOTAL_ENQUEUES, byteTotalEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TXN_DEQUEUES, byteTxnDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTE_TXN_ENQUEUES, byteTxnEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_CONN_BACKLOG, connBacklog },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_LVQ, discardsLvq },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_NO_ROUTE, discardsNoRoute },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_OVERFLOW, discardsOverflow },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_PURGE, discardsPurge },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_RING, discardsRing },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_SUBSCRIBER, discardsSubscriber},
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DISCARDS_TTL, discardsTtl },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MAX_CONNS, maxConns },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MGMT_PUB_INTERVAL, mgmtPubInterval },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MGMT_PUBLISH, mgmtPublish },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_DEPTH, msgDepth },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_FTD_DEPTH, msgFtdDepth },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_FTD_DEQUEUES, msgFtdDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_FTD_ENQUEUES, msgFtdEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_PERSIST_DEQUEUES, msgPersistDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_PERSIST_ENQUEUES, msgPersistEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TOTAL_DEQUEUES, msgTotalDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TOTAL_ENQUEUES, msgTotalEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TXN_DEQUEUES, msgTxnDequeues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_MSG_TXN_ENQUEUES, msgTxnEnqueues },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_QUEUE_COUNT, queueCount },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_RELEASES, releases },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_REROUTES, reroutes },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_STAGING_THRESHOLD, stagingThreshold },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_PORT, port },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_WORKER_THREADS, workerThreads },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_DATA_DIR, dataDir },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_NAME, name },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_VERSION, version },
      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_UPTIME, uptime.count() },

      { BrokerDecoder<qpid::types::Variant>::PROPERTY_NAME_SYSTEM_REF, system_ref_map }
  };

  qpid::types::Variant::Map objectProperties = {
      {ResponsePropertyNames::CREATED,   now_tp.time_since_epoch().count()},
      {ResponsePropertyNames::DELETED,   0},
      {ResponsePropertyNames::UPDATED,   0},
      {ResponsePropertyNames::OBJECT_ID, object_id},
      {ResponsePropertyNames::SCHEMA_ID, schema_id},
      {ResponsePropertyNames::VALUES,    values}
  };

  BrokerDecoder<qpid::types::Variant> decoder;

  auto broker = decoder.decode(objectProperties);

  EXPECT_TRUE(broker);

  EXPECT_EQ(now_tp, broker->getTimeCreated());
  EXPECT_EQ(0, broker->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, broker->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, broker->getObjectId().getName());
  EXPECT_EQ(agent_epoch, broker->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, broker->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, broker->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, broker->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, broker->getSchemaId().getType());

  EXPECT_EQ(abandoned, broker->getAbandoned());
  EXPECT_EQ(abandonedViaAlt, broker->getAbandonedViaAlt());
  EXPECT_EQ(acquires, broker->getAcquires());
  EXPECT_EQ(byteDepth, broker->getByteDepth());
  EXPECT_EQ(byteFtdDepth, broker->getByteFtdDepth());
  EXPECT_EQ(byteFtdDequeues, broker->getByteFtdDequeues());
  EXPECT_EQ(byteFtdEnqueues, broker->getByteFtdEnqueues());
  EXPECT_EQ(bytePersistDequeues, broker->getBytePersistDequeues());
  EXPECT_EQ(bytePersistEnqueues, broker->getBytePersistEnqueues());
  EXPECT_EQ(byteTotalDequeues, broker->getByteTotalDequeues());
  EXPECT_EQ(byteTotalEnqueues, broker->getByteTotalEnqueues());
  EXPECT_EQ(byteTxnDequeues, broker->getByteTxnDequeues());
  EXPECT_EQ(byteTxnEnqueues, broker->getByteTxnEnqueues());
  EXPECT_EQ(connBacklog, broker->getConnBacklog());
  EXPECT_EQ(discardsLvq, broker->getDiscardsLvq());
  EXPECT_EQ(discardsNoRoute, broker->getDiscardsNoRoute());
  EXPECT_EQ(discardsOverflow, broker->getDiscardsOverflow());
  EXPECT_EQ(discardsPurge, broker->getDiscardsPurge());
  EXPECT_EQ(discardsRing, broker->getDiscardsRing());
  EXPECT_EQ(discardsSubscriber, broker->getDiscardsSubscriber());
  EXPECT_EQ(discardsTtl, broker->getDiscardsTtl());
  EXPECT_EQ(maxConns, broker->getMaxConns());
  EXPECT_EQ(mgmtPubInterval, broker->getMgmtPubInterval());
  EXPECT_EQ(mgmtPublish, broker->getMgmtPublish());
  EXPECT_EQ(msgDepth, broker->getMsgDepth());
  EXPECT_EQ(msgFtdDepth, broker->getMsgFtdDepth());
  EXPECT_EQ(msgFtdDequeues, broker->getMsgFtdDequeues());
  EXPECT_EQ(msgFtdEnqueues, broker->getMsgFtdEnqueues());
  EXPECT_EQ(msgPersistDequeues, broker->getMsgPersistDequeues());
  EXPECT_EQ(msgPersistEnqueues, broker->getMsgPersistEnqueues());
  EXPECT_EQ(msgTotalDequeues, broker->getMsgTotalDequeues());
  EXPECT_EQ(msgTotalEnqueues, broker->getMsgTotalEnqueues());
  EXPECT_EQ(msgTxnDequeues, broker->getMsgTxnDequeues());
  EXPECT_EQ(msgTxnEnqueues, broker->getMsgTxnEnqueues());
  EXPECT_EQ(queueCount, broker->getQueueCount());
  EXPECT_EQ(releases, broker->getReleases());
  EXPECT_EQ(reroutes, broker->getReroutes());
  EXPECT_EQ(stagingThreshold, broker->getStagingThreshold());
  EXPECT_EQ(port, broker->getPort());
  EXPECT_EQ(workerThreads, broker->getWorkerThreads());
  EXPECT_EQ(dataDir, broker->getDataDir());
  EXPECT_EQ(name, broker->getName());
  EXPECT_EQ(system_ref, broker->getSystemRef());
  EXPECT_EQ(version, broker->getVersion());
  EXPECT_EQ(uptime, broker->getUptime());
}