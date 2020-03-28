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
#include <fourc/fmf/codec/SessionDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

TEST(SessionDecoderTests, ctor) {
  auto instance = new SessionDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(SessionDecoderTests, dynamicCast) {
  auto instance = new SessionDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Session, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(SessionDecoderTests, decodeSession) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  uint64_t agent_epoch = 10;

  std::string schema_class = "session";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.session";
  std::string schema_type = "_data";

  uint64_t txn_commits = 1;
  uint32_t txn_count = 2;
  uint64_t txn_rejects = 3;
  uint64_t txn_starts = 4;
  bool attached = true;
  uint16_t channel_id = 5;
  uint32_t client_credit = 6;
  uint64_t connection_epoch = 7;
  std::string connection_name = "test connection name";
  uint32_t detached_lifespan = 9;
  uint32_t frames_outstanding = 10;
  std::string full_name = "test full name";
  std::string name = "test name";
  uint64_t unacked_messages = 11;
  std::string vhost_ref = "test vhost ref";

  qpid::types::Variant::Map object_id = {
      { ResponsePropertyNames::OBJECT_NAME, oid },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, agent_epoch }
  };

  qpid::types::Variant::Map schema_id = {
      { ResponsePropertyNames::SCHEMA_CLASS_NAME, schema_class },
      { ResponsePropertyNames::SCHEMA_HASH, schema_hash },
      { ResponsePropertyNames::SCHEMA_PACKAGE_NAME, schema_package_name },
      { ResponsePropertyNames::SCHEMA_TYPE, schema_type },
  };

  qpid::types::Variant::Map connection_ref_map = {
      { ResponsePropertyNames::OBJECT_NAME, connection_name },
      { ResponsePropertyNames::OBJECT_AGENT_EPOCH, connection_epoch }
  };

  qpid::types::Variant::Map vhost_ref_map = {
      { RPNs::OBJECT_NAME, vhost_ref }
  };

  qpid::types::Variant::Map values = {
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_TXN_COMMITS, txn_commits },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_TXN_COUNT, txn_count },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_TXN_REJECTS, txn_rejects },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_TXN_STARTS, txn_starts },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_ATTACHED, attached },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_CHANNEL_ID, channel_id },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_CLIENT_CREDIT, client_credit },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_CONNECTION_REF, connection_ref_map },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_DETACHED_LIFESPAN, detached_lifespan },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_FRAMES_OUTSTANDING, frames_outstanding },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_FULL_NAME, full_name },
      { RPNs::NAME, name },
      { SessionDecoder<qpid::types::Variant>::PROPERTY_NAME_UNACKED_MESSAGES, unacked_messages },
      { RPNs::VHOST_REF, vhost_ref_map }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, now_tp.time_since_epoch().count() },
      { ResponsePropertyNames::DELETED, 0 },
      { ResponsePropertyNames::UPDATED, 0 },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  SessionDecoder<qpid::types::Variant> decoder;

  auto session = decoder.decode(objectProperties);

  EXPECT_TRUE(session);

  EXPECT_EQ(now_tp, session->getTimeCreated());
  EXPECT_EQ(0, session->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, session->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, session->getObjectId().getName());
  EXPECT_EQ(agent_epoch, session->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, session->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, session->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, session->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, session->getSchemaId().getType());

  EXPECT_EQ(txn_commits, session->getTxnCommits());
  EXPECT_EQ(txn_count, session->getTxnCount());
  EXPECT_EQ(txn_rejects, session->getTxnRejects());
  EXPECT_EQ(txn_starts, session->getTxnStarts());
  EXPECT_EQ(attached, session->isAttached());
  EXPECT_EQ(channel_id, session->getChannelId());
  EXPECT_EQ(client_credit, session->getClientCredit());
  EXPECT_EQ(connection_epoch, session->getConnectionEpoch());
  EXPECT_EQ(connection_name, session->getConnectionName());
  EXPECT_EQ(detached_lifespan, session->getDetachedLifespan());
  EXPECT_EQ(frames_outstanding, session->getFramesOutstanding());
  EXPECT_EQ(full_name, session->getFullName());
  EXPECT_EQ(name, session->getName());
  EXPECT_EQ(unacked_messages, session->getUnackedMessages());
  EXPECT_EQ(vhost_ref, session->getVhostRef());
}
