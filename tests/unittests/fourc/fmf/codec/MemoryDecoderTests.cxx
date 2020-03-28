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
#include <fourc/fmf/codec/MemoryDecoder.h>

#include <subsystem/mocks/Variant.h>
#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;
using namespace fourc::fmf;

using ::testing::Return;
using ::testing::ReturnRef;

TEST(MemoryDecoderTests, ctor) {
  auto instance = new MemoryDecoder<subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(MemoryDecoderTests, dynamicCast) {
  auto instance = new MemoryDecoder<subsystem::mocks::Variant>();
  auto cast_instance = dynamic_cast<Decoder<Memory, subsystem::mocks::Variant>*>(instance);

  EXPECT_NE(nullptr, cast_instance);

  delete instance;
}

TEST(MemoryDecoderTests, decodeMemory) {
  auto now_tp = std::chrono::system_clock::now();
  std::string oid = "oid";
  uint64_t agent_epoch = 10;

  std::string schema_class = "memory";
  std::string schema_hash = "12345";
  std::string schema_package_name = "org.apache.qpid.memory";
  std::string schema_type = "_data";

  uint64_t malloc_arena = 1;
  uint64_t malloc_fordblks = 2;
  uint64_t malloc_hblkhd = 3;
  uint64_t malloc_hblks = 4;
  uint64_t malloc_keepcost = 5;
  uint64_t malloc_ordblks = 6;
  uint64_t malloc_uordblks = 7;
  std::string name = "test name";

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
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_ARENA, malloc_arena },
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_FORDBLKS, malloc_fordblks },
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_HBLKHD, malloc_hblkhd },
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_HBLKS, malloc_hblks },
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_KEEPCOST, malloc_keepcost },
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_ORDBLKS, malloc_ordblks },
      { MemoryDecoder<qpid::types::Variant>::PROPERTY_NAME_MALLOC_UORDBLKS, malloc_uordblks },
      { RPNs::NAME, name }
  };

  qpid::types::Variant::Map objectProperties = {
      { ResponsePropertyNames::CREATED, now_tp.time_since_epoch().count() },
      { ResponsePropertyNames::DELETED, 0 },
      { ResponsePropertyNames::UPDATED, 0 },
      { ResponsePropertyNames::OBJECT_ID, object_id },
      { ResponsePropertyNames::SCHEMA_ID, schema_id },
      { ResponsePropertyNames::VALUES, values }
  };

  MemoryDecoder<qpid::types::Variant> decoder;

  auto memory = decoder.decode(objectProperties);

  EXPECT_TRUE(memory);

  EXPECT_EQ(now_tp, memory->getTimeCreated());
  EXPECT_EQ(0, memory->getTimeDeleted().time_since_epoch().count());
  EXPECT_EQ(0, memory->getTimeUpdated().time_since_epoch().count());

  EXPECT_EQ(oid, memory->getObjectId().getName());
  EXPECT_EQ(agent_epoch, memory->getObjectId().getAgentEpoch());

  EXPECT_EQ(schema_class, memory->getSchemaId().getClassName());
  EXPECT_EQ(schema_hash, memory->getSchemaId().getHash());
  EXPECT_EQ(schema_package_name, memory->getSchemaId().getPackageName());
  EXPECT_EQ(schema_type, memory->getSchemaId().getType());

  EXPECT_EQ(malloc_arena, memory->getMallocArena());
  EXPECT_EQ(malloc_fordblks, memory->getMallocFordblks());
  EXPECT_EQ(malloc_hblkhd, memory->getMallocHblkhd());
  EXPECT_EQ(malloc_hblks, memory->getMallocHblks());
  EXPECT_EQ(malloc_keepcost, memory->getMallocKeepcost());
  EXPECT_EQ(malloc_ordblks, memory->getMallocOrdblks());
  EXPECT_EQ(malloc_uordblks, memory->getMallocUordblks());
  EXPECT_EQ(name, memory->getName());
}
