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
#include <fourc/fmf/Memory.h>

using namespace fourc::fmf;

TEST(MemoryTests, ctor) {
  auto instance = new Memory();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(MemoryTests, ctorSetsMallocArena) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocArena());
}

TEST(MemoryTests, ctorSetsMallocFordblks) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocFordblks());
}

TEST(MemoryTests, ctorSetsMallocHblkhd) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocHblkhd());
}

TEST(MemoryTests, ctorSetsMallocHblks) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocHblks());
}

TEST(MemoryTests, ctorSetsMallocKeepcost) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocKeepcost());
}

TEST(MemoryTests, ctorSetsMallocOrdblks) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocOrdblks());
}

TEST(MemoryTests, ctorSetsMallocUordblks) {
  Memory memory;

  EXPECT_EQ(0u, memory.getMallocUordblks());
}

TEST(MemoryTests, ctorSetsName) {
  Memory memory;

  EXPECT_TRUE(memory.getName().empty());
}

// ********************

TEST(MemoryTests, setMallocArena) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocArena(expected);

  EXPECT_EQ(expected, memory.getMallocArena());
}

TEST(MemoryTests, setMallocFordblks) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocFordblks(expected);

  EXPECT_EQ(expected, memory.getMallocFordblks());
}

TEST(MemoryTests, setMallocHblkhd) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocHblkhd(expected);

  EXPECT_EQ(expected, memory.getMallocHblkhd());
}

TEST(MemoryTests, setMallocHblks) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocHblks(expected);

  EXPECT_EQ(expected, memory.getMallocHblks());
}

TEST(MemoryTests, setMallocKeepcost) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocKeepcost(expected);

  EXPECT_EQ(expected, memory.getMallocKeepcost());
}

TEST(MemoryTests, setMallocOrdblks) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocOrdblks(expected);

  EXPECT_EQ(expected, memory.getMallocOrdblks());
}

TEST(MemoryTests, setMallocUordblks) {
  uint64_t expected = 11;
  Memory memory;
  memory.setMallocUordblks(expected);

  EXPECT_EQ(expected, memory.getMallocUordblks());
}

TEST(MemoryTests, setName) {
  std::string expected = "test name";
  Memory memory;
  memory.setName(expected);

  EXPECT_EQ(expected, memory.getName());
}