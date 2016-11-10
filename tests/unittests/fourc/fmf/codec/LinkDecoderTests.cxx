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
#include <fourc/fmf/codec/LinkDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

class TestLinkDecoder_VariantReferenceMap : public LinkDecoder<subsystem::mocks::ReferenceVariant> {
public:
};

TEST(LinkDecoderTests, ctor) {
  auto instance = new LinkDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(LinkDecoderTests, dynamicCast) {
  auto instance = new LinkDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Link, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(LinkDecoderTests, decodeLink) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  int agent_epoch = 10;

  std::string schema_class = "link";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.link";
  std::string schema_type = "_data";

  uint32_t connection_epoch = 1;
  std::string connection_name = "connection name";
  bool durable = true;
  std::string host = "host";
  uint16_t port = 2;
  std::string last_error = "last error";
  std::string name = "name";
  std::string state = "state";
  std::string transport = "transport";
  std::string vhost_ref = "vhost ref";

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
      { RPNs::OBJECT_AGENT_EPOCH, connection_epoch },
      { RPNs::OBJECT_NAME, connection_name }
  };

  qpid::types::Variant::Map vhost_ref_map = {
      { RPNs::OBJECT_NAME, vhost_ref }
  };

  qpid::types::Variant::Map values = {
      { LinkDecoder<qpid::types::Variant>::PROPERTY_NAME_CONNECTION_REF, connection_ref_map },
      { RPNs::DURABLE, durable },
      { LinkDecoder<qpid::types::Variant>::PROPERTY_NAME_HOST, host },
      { LinkDecoder<qpid::types::Variant>::PROPERTY_NAME_PORT, port },
      { LinkDecoder<qpid::types::Variant>::PROPERTY_NAME_LAST_ERROR, last_error },
      { RPNs::NAME, name },
      { LinkDecoder<qpid::types::Variant>::PROPERTY_NAME_STATE, state },
      { LinkDecoder<qpid::types::Variant>::PROPERTY_NAME_TRANSPORT, transport },
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

  LinkDecoder<qpid::types::Variant> decoder;

  auto link = decoder.decode(objectProperties);

  EXPECT_TRUE(link);

  EXPECT_EQ(now_tp, link->getTimeCreated());
  EXPECT_EQ(0, link->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, link->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, link->getObjectId().getName());
  EXPECT_EQ(agent_epoch, link->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, link->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, link->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, link->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, link->getSchemaId().getType());

  EXPECT_EQ(connection_epoch, link->getConnectionEpoch());
  EXPECT_EQ(connection_name, link->getConnectionName());
  EXPECT_EQ(durable, link->isDurable());
  EXPECT_EQ(host, link->getHost());
  EXPECT_EQ(port, link->getPort());
  EXPECT_EQ(last_error, link->getLastError());
  EXPECT_EQ(name, link->getName());
  EXPECT_EQ(state, link->getState());
  EXPECT_EQ(transport, link->getTransport());
  EXPECT_EQ(vhost_ref, link->getVhostRef());
}
