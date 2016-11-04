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
#include <fourc/fmf/ObjectId.h>

using namespace fourc::fmf;

TEST(ObjectIdTests, ctor) {
  auto instance = new ObjectId();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(ObjectIdTests, ctorSetsAgentEpoch) {
  ObjectId objectId;

  EXPECT_EQ(0, objectId.getAgentEpoch());
}

TEST(ObjectIdTests, setAgentEpoch) {
  int expected = 42;
  ObjectId objectId;

  objectId.setAgentEpoch(expected);

  EXPECT_EQ(expected, objectId.getAgentEpoch());
}

TEST(ObjectIdTests, setName) {
  std::string expected = "Test";
  ObjectId objectId;

  objectId.setName(expected);

  EXPECT_EQ(expected, objectId.getName());
}

TEST(ObjectIdTests, equalsSameObject) {
  ObjectId objectId;

  EXPECT_EQ(objectId, objectId);
}

TEST(ObjectIdTests, equalsEqualObject) {
  ObjectId objectId1;
  ObjectId objectId2;

  EXPECT_EQ(objectId1, objectId2);
}

TEST(ObjectIdTests, notEqualsDifferentName) {
  ObjectId objectId1;
  ObjectId objectId2;

  objectId2.setName("test");

  EXPECT_FALSE(objectId1 == objectId2);
}

TEST(ObjectIdTests, notEqualsDifferentAgentEpoch) {
  ObjectId objectId1;
  ObjectId objectId2;

  objectId2.setAgentEpoch(4);

  EXPECT_FALSE(objectId1 == objectId2);
}