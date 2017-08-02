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
#include <fourc/fmf/codec/BridgeDecoder.h>

#include <qpid/types/Variant.h>
#include <subsystem/mocks/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

TEST(BridgeDecoderTests, ctor) {
  auto instance = new BridgeDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BridgeDecoderTests, dynamicCast) {
  auto instance = new BridgeDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Bridge, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(BridgeDecoderTests, decodeBridge) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  uint64_t agent_epoch = 10;

  std::string schema_class = "bridge";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.bridge";
  std::string schema_type = "_data";

  std::string link_ref = "link ref";
  std::string name = "bridge name";
  uint16_t channel_id = 4;
  bool durable = true;
  std::string src = "bridge src";
  std::string dest = "bridge dest";
  std::string bridge_key = "bridge key";
  bool src_is_queue = true;
  bool src_is_local = true;
  std::string bridge_tag = "bridge tag";
  std::string bridge_excludes = "bridge excludes";
  bool dynamic = true;
  uint16_t sync = 12;
  uint32_t credit = 17;

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

  qpid::types::Variant::Map values = {
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_LINK_REF, link_ref },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_NAME, name },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_CHANNEL_ID, channel_id },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_DURABLE, durable },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_SRC, src },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_DEST, dest },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_KEY, bridge_key },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_SRC_IS_QUEUE, src_is_queue },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_SRC_IS_LOCAL, src_is_local },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_TAG, bridge_tag },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_EXCLUDES, bridge_excludes },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_DYNAMIC, dynamic },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_SYNC, sync },
      { BridgeDecoder<qpid::types::Variant>::PROPERTY_NAME_CREDIT, credit }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, now_tp.time_since_epoch().count() },
      { ResponsePropertyNames::DELETED, 0 },
      { ResponsePropertyNames::UPDATED, 0 },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  BridgeDecoder<qpid::types::Variant> decoder;

  auto bridge = decoder.decode(objectProperties);

  EXPECT_TRUE(bridge);

  EXPECT_EQ(now_tp, bridge->getTimeCreated());
  EXPECT_EQ(0, bridge->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, bridge->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, bridge->getObjectId().getName());
  EXPECT_EQ(agent_epoch, bridge->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, bridge->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, bridge->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, bridge->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, bridge->getSchemaId().getType());

  EXPECT_EQ(link_ref, bridge->getLinkRef());
  EXPECT_EQ(name, bridge->getName());
  EXPECT_EQ(channel_id, bridge->getChannelId());
  EXPECT_EQ(durable, bridge->isDurable());
  EXPECT_EQ(src, bridge->getSrc());
  EXPECT_EQ(dest, bridge->getDest());
  EXPECT_EQ(bridge_key, bridge->getKey());
  EXPECT_EQ(src_is_queue, bridge->isSrcQueue());
  EXPECT_EQ(src_is_local, bridge->isSrcLocal());
  EXPECT_EQ(bridge_tag, bridge->getTag());
  EXPECT_EQ(bridge_excludes, bridge->getExcludes());
  EXPECT_EQ(dynamic, bridge->isDynamic());
  EXPECT_EQ(sync, bridge->getSync());
  EXPECT_EQ(credit, bridge->getCredit());
}
