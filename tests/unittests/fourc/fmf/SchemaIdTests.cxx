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
#include <fourc/fmf/SchemaId.h>

using namespace fourc::fmf;

TEST(SchemaIdTests, ctor) {
  auto instance = new SchemaId();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(SchemaIdTests, setClassName) {
  std::string expected = "test class name";
  SchemaId schemaId;

  schemaId.setClassName(expected);

  EXPECT_EQ(expected, schemaId.getClassName());
}

TEST(SchemaIdTests, setHash) {
  std::string expected = "test hash";
  SchemaId schemaId;

  schemaId.setHash(expected);

  EXPECT_EQ(expected, schemaId.getHash());
}

TEST(SchemaIdTests, setPackageName) {
  std::string expected = "test package name";
  SchemaId schemaId;

  schemaId.setPackageName(expected);

  EXPECT_EQ(expected, schemaId.getPackageName());
}

TEST(SchemaIdTests, setType) {
  std::string expected = "test type name";
  SchemaId schemaId;

  schemaId.setType(expected);

  EXPECT_EQ(expected, schemaId.getType());
}

TEST(SchemaIdTests, equalsSameObject) {
  SchemaId schemaId;

  EXPECT_EQ(schemaId, schemaId);
}

TEST(SchemaIdTests, equalsEqualObject) {
  SchemaId schemaId1;
  SchemaId schemaId2;

  EXPECT_EQ(schemaId1, schemaId2);
}

TEST(SchemaIdTests, notEqualsDifferentClassName) {
  SchemaId schemaId1;
  SchemaId schemaId2;

  schemaId2.setClassName("test");

  EXPECT_FALSE(schemaId1 == schemaId2);
}

TEST(SchemaIdTests, notEqualsDifferentHash) {
  SchemaId schemaId1;
  SchemaId schemaId2;

  schemaId2.setHash("test");

  EXPECT_FALSE(schemaId1 == schemaId2);
}

TEST(SchemaIdTests, notEqualsDifferentPackageName) {
  SchemaId schemaId1;
  SchemaId schemaId2;

  schemaId2.setPackageName("test");

  EXPECT_FALSE(schemaId1 == schemaId2);
}