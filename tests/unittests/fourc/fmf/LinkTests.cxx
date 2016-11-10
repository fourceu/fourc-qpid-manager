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
#include <fourc/fmf/Link.h>

using namespace fourc::fmf;

TEST(LinkTests, ctor) {
  auto instance = new Link();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(LinkTests, ctorSetsConnectionEpoch) {
  Link link;
  
  EXPECT_EQ(0u, link.getConnectionEpoch());
}

TEST(LinkTests, ctorSetsConnectionName) {
  Link link;

  EXPECT_TRUE(link.getConnectionName().empty());
}

TEST(LinkTests, ctorSetsDurable) {
  Link link;

  EXPECT_FALSE(link.isDurable());
}

TEST(LinkTests, ctorSetsHost) {
  Link link;

  EXPECT_TRUE(link.getHost().empty());
}

TEST(LinkTests, ctorSetsPort) {
  Link link;

  EXPECT_EQ(0u, link.getPort());
}

TEST(LinkTests, ctorSetsLastError) {
  Link link;

  EXPECT_TRUE(link.getLastError().empty());
}

TEST(LinkTests, ctorSetsName) {
  Link link;

  EXPECT_TRUE(link.getName().empty());
}

TEST(LinkTests, ctorSetsState) {
  Link link;

  EXPECT_TRUE(link.getState().empty());
}

TEST(LinkTests, ctorSetsTransport) {
  Link link;

  EXPECT_TRUE(link.getTransport().empty());
}

TEST(LinkTests, ctorSetsVhostRef) {
  Link link;

  EXPECT_TRUE(link.getVhostRef().empty());
}

// ***********************


TEST(LinkTests, setConnectionEpoch) {
  uint32_t expected;
  Link link;
  link.setConnectionEpoch(expected);

  EXPECT_EQ(expected, link.getConnectionEpoch());
}

TEST(LinkTests, setConnectionName) {
  std::string expected = "test value";
  Link link;
  link.setConnectionName(expected);

  EXPECT_EQ(expected, link.getConnectionName());
}

TEST(LinkTests, setDurable) {
  bool expected = true;
  Link link;

  EXPECT_NE(expected, link.isDurable());
  link.setDurable(expected);

  EXPECT_EQ(expected, link.isDurable());
}

TEST(LinkTests, setHost) {
  std::string expected = "test value";
  Link link;
  link.setHost(expected);

  EXPECT_EQ(expected, link.getHost());
}

TEST(LinkTests, setPort) {
  uint16_t expected = 4;
  Link link;
  link.setPort(expected);

  EXPECT_EQ(expected, link.getPort());
}

TEST(LinkTests, setLastError) {
  std::string expected = "test value";
  Link link;
  link.setLastError(expected);

  EXPECT_EQ(expected, link.getLastError());
}

TEST(LinkTests, setName) {
  std::string expected = "test value";
  Link link;
  link.setName(expected);

  EXPECT_EQ(expected, link.getName());
}

TEST(LinkTests, setState) {
  std::string expected = "test value";
  Link link;
  link.setState(expected);

  EXPECT_EQ(expected, link.getState());
}

TEST(LinkTests, setTransport) {
  std::string expected = "test value";
  Link link;
  link.setTransport(expected);

  EXPECT_EQ(expected, link.getTransport());
}

TEST(LinkTests, setVhostRef) {
  std::string expected = "test value";
  Link link;
  link.setVhostRef(expected);

  EXPECT_EQ(expected, link.getVhostRef());
}
