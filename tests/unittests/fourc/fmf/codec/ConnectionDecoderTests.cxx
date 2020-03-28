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
#include <fourc/fmf/codec/ConnectionDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

TEST(ConnectionDecoderTests, ctor) {
  auto instance = new ConnectionDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(ConnectionDecoderTests, dynamicCast) {
  auto instance = new ConnectionDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Connection, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(ConnectionDecoderTests, decodeConnection) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  uint64_t agent_epoch = 10;

  std::string schema_class = "connection";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.connection";
  std::string schema_type = "_data";

  bool system_connection = true;
  std::string address = "address";
  std::string authIdentity = "ident";
  uint64_t bytesFromClient = 1;
  uint64_t bytesToClient = 2;
  bool closing = true;
  bool federationLink = true;
  uint64_t framesFromClient = 3;
  uint64_t framesToClient = 4;
  bool incoming = true;
  uint64_t msgsFromClient = 5;
  uint64_t msgsToClient = 6;
  std::string protocol = "amqp";
  uint32_t remoteParentPid = 7;
  uint32_t remotePid = 8;
  std::string remoteProcessName = "remote proc name";
  std::string saslMechanism = "sasl mech";
  uint64_t saslSsf = 9;
  bool shadow = true;
  bool userProxyAuth = true;
  std::string vhost_ref = "org.apache.qpid.broker:vhost:org.apache.qpid.broker:broker:amqp-broker";

  qpid::types::Variant::Map object_id = {
      { RPNs::OBJECT_NAME, oid },
      { RPNs::OBJECT_AGENT_EPOCH, agent_epoch }
  };

  qpid::types::Variant::Map schema_id = {
      { RPNs::SCHEMA_CLASS_NAME, schema_class },
      { RPNs::SCHEMA_HASH, schema_hash },
      { RPNs::SCHEMA_PACKAGE_NAME, schema_package_name },
      { RPNs::SCHEMA_TYPE, schema_type },
  };

  qpid::types::Variant::Map vhost_ref_map = {
      { RPNs::OBJECT_NAME, vhost_ref }
  };

  qpid::types::Variant::Map values = {
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_SYSTEM_CONNECTION, system_connection },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_ADDRESS, address },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_AUTH_IDENTITY, authIdentity },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTES_FROM_CLIENT, bytesFromClient },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_BYTES_TO_CLIENT, bytesToClient },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_CLOSING, closing },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_FEDERATION_LINK, federationLink },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_FRAMES_FROM_CLIENT, framesFromClient },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_FRAMES_TO_CLIENT, framesToClient },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_INCOMING, incoming },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_MSGS_FROM_CLIENT, msgsFromClient },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_MSGS_TO_CLIENT, msgsToClient },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_PROTOCOL, protocol },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_REMOTE_PARENT_PID, remoteParentPid },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_REMOTE_PID, remotePid },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_REMOTE_PROCESS_NAME, remoteProcessName },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_SASL_MECHANISM, saslMechanism },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_SASL_SSF, saslSsf },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_SHADOW, shadow },
      { ConnectionDecoder<qpid::types::Variant>::PROPERTY_NAME_USER_PROXY_AUTH, userProxyAuth },

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

  ConnectionDecoder<qpid::types::Variant> decoder;

  auto connection = decoder.decode(objectProperties);

  EXPECT_TRUE(connection);

  EXPECT_EQ(now_tp, connection->getTimeCreated());
  EXPECT_EQ(0, connection->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, connection->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, connection->getObjectId().getName());
  EXPECT_EQ(agent_epoch, connection->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, connection->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, connection->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, connection->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, connection->getSchemaId().getType());

  EXPECT_EQ(system_connection, connection->isSystemConnection());
  EXPECT_EQ(address, connection->getAddress());
  EXPECT_EQ(authIdentity, connection->getAuthIdentity());
  EXPECT_EQ(bytesFromClient, connection->getBytesFromClient());
  EXPECT_EQ(bytesToClient, connection->getBytesToClient());
  EXPECT_EQ(closing, connection->isClosing());
  EXPECT_EQ(federationLink, connection->isFederationLink());
  EXPECT_EQ(framesFromClient, connection->getFramesFromClient());
  EXPECT_EQ(framesToClient, connection->getFramesToClient());
  EXPECT_EQ(incoming, connection->isIncoming());
  EXPECT_EQ(msgsFromClient, connection->getMsgsFromClient());
  EXPECT_EQ(msgsToClient, connection->getMsgsToClient());
  EXPECT_EQ(protocol, connection->getProtocol());
  EXPECT_EQ(remoteParentPid, connection->getRemoteParentPid());
  EXPECT_EQ(remotePid, connection->getRemotePid());
  EXPECT_EQ(remoteProcessName, connection->getRemoteProcessName());
  EXPECT_EQ(saslMechanism, connection->getSaslMechanism());
  EXPECT_EQ(saslSsf, connection->getSaslSsf());
  EXPECT_EQ(shadow, connection->isShadow());
  EXPECT_EQ(userProxyAuth, connection->isUserProxyAuth());
  EXPECT_EQ(vhost_ref, connection->getVhostRef());
}
