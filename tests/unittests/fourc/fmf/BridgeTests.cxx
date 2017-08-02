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
#include <fourc/fmf/Bridge.h>

using namespace fourc::fmf;

TEST(BridgeTests, ctor) {
  auto instance = new Bridge();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BridgeTests, getLinkRef) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getLinkRef().empty());
}

TEST(BridgeTests, setLinkRef) {
  std::string expected("test_link_ref");
  Bridge bridge;
  bridge.setLinkRef(expected);

  EXPECT_EQ(expected, bridge.getLinkRef());
}

TEST(BridgeTests, getName) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getName().empty());
}

TEST(BridgeTests, setName) {
  std::string expected("test_name");
  Bridge bridge;
  bridge.setName(expected);

  EXPECT_EQ(expected, bridge.getName());
}

TEST(BridgeTests, getChannelId) {
  Bridge bridge;

  EXPECT_EQ(0u, bridge.getChannelId());
}

TEST(BridgeTests, setChannelId) {
  uint16_t expected = 4u;
  Bridge bridge;
  bridge.setChannelId(expected);

  EXPECT_EQ(expected, bridge.getChannelId());
}

TEST(BridgeTests, isDurable) {
  Bridge bridge;

  EXPECT_FALSE(bridge.isDurable());
}

TEST(BridgeTests, setDurable_true) {
  bool expected = true;
  Bridge bridge;
  bridge.setDurable(expected);

  EXPECT_EQ(expected, bridge.isDurable());
}

TEST(BridgeTests, setDurable_false) {
  bool expected = false;
  Bridge bridge;
  bridge.setDurable(true);
  EXPECT_TRUE(bridge.isDurable());

  bridge.setDurable(expected);
  EXPECT_EQ(expected, bridge.isDurable());
}

TEST(BridgeTests, getSrc) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getSrc().empty());
}

TEST(BridgeTests, setSrc) {
  std::string expected("test_src");
  Bridge bridge;
  bridge.setSrc(expected);

  EXPECT_EQ(expected, bridge.getSrc());
}

TEST(BridgeTests, getDest) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getDest().empty());
}

TEST(BridgeTests, setDest) {
  std::string expected("test_dest");
  Bridge bridge;
  bridge.setDest(expected);

  EXPECT_EQ(expected, bridge.getDest());
}

TEST(BridgeTests, getKey) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getKey().empty());
}

TEST(BridgeTests, setKey) {
  std::string expected("test_key");
  Bridge bridge;
  bridge.setKey(expected);

  EXPECT_EQ(expected, bridge.getKey());
}

TEST(BridgeTests, isSrcQueue) {
  Bridge bridge;

  EXPECT_FALSE(bridge.isSrcQueue());
}

TEST(BridgeTests, setSrcQueue_true) {
  bool expected = true;
  Bridge bridge;
  bridge.setSrcQueue(expected);

  EXPECT_EQ(expected, bridge.isSrcQueue());
}

TEST(BridgeTests, setSrcQueue_false) {
  bool expected = false;
  Bridge bridge;
  bridge.setSrcQueue(true);
  EXPECT_TRUE(bridge.isSrcQueue());

  bridge.setSrcQueue(expected);
  EXPECT_EQ(expected, bridge.isSrcQueue());
}

TEST(BridgeTests, isSrcLocal) {
  Bridge bridge;

  EXPECT_FALSE(bridge.isSrcLocal());
}

TEST(BridgeTests, setSrcLocal_true) {
  bool expected = true;
  Bridge bridge;
  bridge.setSrcLocal(expected);

  EXPECT_EQ(expected, bridge.isSrcLocal());
}

TEST(BridgeTests, setSrcLocal_false) {
  bool expected = false;
  Bridge bridge;
  bridge.setSrcLocal(true);
  EXPECT_TRUE(bridge.isSrcLocal());

  bridge.setSrcLocal(expected);
  EXPECT_EQ(expected, bridge.isSrcLocal());
}

TEST(BridgeTests, getTag) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getTag().empty());
}

TEST(BridgeTests, setTag) {
  std::string expected("test_tag");
  Bridge bridge;
  bridge.setTag(expected);

  EXPECT_EQ(expected, bridge.getTag());
}

TEST(BridgeTests, getExcludes) {
  Bridge bridge;

  EXPECT_TRUE(bridge.getExcludes().empty());
}

TEST(BridgeTests, setExcludes) {
  std::string expected("test_excludes");
  Bridge bridge;
  bridge.setExcludes(expected);

  EXPECT_EQ(expected, bridge.getExcludes());
}

TEST(BridgeTests, isDynamic) {
  Bridge bridge;

  EXPECT_FALSE(bridge.isDynamic());
}

TEST(BridgeTests, setDynamic_true) {
  bool expected = true;
  Bridge bridge;
  bridge.setDynamic(expected);

  EXPECT_EQ(expected, bridge.isDynamic());
}

TEST(BridgeTests, setDynamic_false) {
  bool expected = false;
  Bridge bridge;
  bridge.setDynamic(true);
  EXPECT_TRUE(bridge.isDynamic());

  bridge.setDynamic(expected);
  EXPECT_EQ(expected, bridge.isDynamic());
}

TEST(BridgeTests, getSync) {
  Bridge bridge;

  EXPECT_EQ(0u, bridge.getSync());
}

TEST(BridgeTests, setSync) {
  uint16_t expected = 5u;
  Bridge bridge;
  bridge.setSync(expected);

  EXPECT_EQ(expected, bridge.getSync());
}

TEST(BridgeTests, getCredit) {
  Bridge bridge;

  EXPECT_EQ(0u, bridge.getCredit());
}

TEST(BridgeTests, setCredit) {
  uint32_t expected = 6u;
  Bridge bridge;
  bridge.setCredit(expected);

  EXPECT_EQ(expected, bridge.getCredit());
}
