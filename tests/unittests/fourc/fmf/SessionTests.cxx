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
#include <fourc/fmf/Session.h>

using namespace fourc::fmf;

TEST(SessionTests, ctor) {
  auto instance = new Session();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(SessionTests, ctorSetsTxnCommits) {
  Session session;

  EXPECT_EQ(0u, session.getTxnCommits());
}

TEST(SessionTests, ctorSetsTxnCount) {
  Session session;

  EXPECT_EQ(0u, session.getTxnCount());
}

TEST(SessionTests, ctorSetsTxnRejects) {
  Session session;

  EXPECT_EQ(0u, session.getTxnRejects());
}

TEST(SessionTests, ctorSetsTxnStarts) {
  Session session;

  EXPECT_EQ(0u, session.getTxnStarts());
}

TEST(SessionTests, ctorSetsAttached) {
  Session session;

  EXPECT_FALSE(session.isAttached());
}

TEST(SessionTests, ctorSetsChannelId) {
  Session session;

  EXPECT_EQ(0u, session.getChannelId());
}

TEST(SessionTests, ctorSetsClientCredit) {
  Session session;

  EXPECT_EQ(0u, session.getClientCredit());
}

TEST(SessionTests, ctorSetsConnectionEpoch) {
  Session session;

  EXPECT_EQ(0u, session.getConnectionEpoch());
}

TEST(SessionTests, ctorSetsConnectionName) {
  Session session;

  EXPECT_TRUE(session.getConnectionName().empty());
}

TEST(SessionTests, ctorSetsDetachedLifespan) {
  Session session;

  EXPECT_EQ(0u, session.getDetachedLifespan());
}

TEST(SessionTests, ctorSetsFramesOutstanding) {
  Session session;

  EXPECT_EQ(0u, session.getFramesOutstanding());
}

TEST(SessionTests, ctorSetsFullName) {
  Session session;

  EXPECT_TRUE(session.getFullName().empty());
}

TEST(SessionTests, ctorSetsName) {
  Session session;

  EXPECT_TRUE(session.getName().empty());
}

TEST(SessionTests, ctorSetsUnackedMessages) {
  Session session;

  EXPECT_EQ(0u, session.getUnackedMessages());
}

TEST(SessionTests, ctorSetsVhostRef) {
  Session session;

  EXPECT_TRUE(session.getVhostRef().empty());
}

// ****************

TEST(SessionTests, setTxnCommits) {
  uint64_t expected = 23;
  Session session;
  session.setTxnCommmits(expected);

  EXPECT_EQ(expected, session.getTxnCommits());
}

TEST(SessionTests, setTxnCount) {
  uint32_t expected = 23;
  Session session;
  session.setTxnCount(expected);

  EXPECT_EQ(expected, session.getTxnCount());
}

TEST(SessionTests, setTxnRejects) {
  uint64_t expected = 23;
  Session session;
  session.setTxnRejects(expected);

  EXPECT_EQ(expected, session.getTxnRejects());
}

TEST(SessionTests, setTxnStarts) {
  uint64_t expected = 23;
  Session session;
  session.setTxnStarts(expected);

  EXPECT_EQ(expected, session.getTxnStarts());
}

TEST(SessionTests, setAttached) {
  bool expected = true;
  Session session;

  EXPECT_NE(expected, session.isAttached());
  session.setAttached(expected);

  EXPECT_EQ(expected, session.isAttached());
}

TEST(SessionTests, setChannelId) {
  uint16_t expected = 23;
  Session session;
  session.setChannelId(expected);

  EXPECT_EQ(expected, session.getChannelId());
}

TEST(SessionTests, setClientCredit) {
  uint32_t expected = 23;
  Session session;
  session.setClientCredit(expected);

  EXPECT_EQ(expected, session.getClientCredit());
}

TEST(SessionTests, setConnectionEpoch) {
  uint64_t expected = 23;
  Session session;
  session.setConnectionEpoch(expected);

  EXPECT_EQ(expected, session.getConnectionEpoch());
}

TEST(SessionTests, setConnectionName) {
  std::string expected = "test conn name";
  Session session;
  session.setConnectionName(expected);

  EXPECT_EQ(expected, session.getConnectionName());
}

TEST(SessionTests, setDetachedLifespan) {
  uint32_t expected = 23;
  Session session;
  session.setDetachedLifespan(expected);

  EXPECT_EQ(expected, session.getDetachedLifespan());
}

TEST(SessionTests, setFramesOutstanding) {
  uint32_t expected = 23;
  Session session;
  session.setFramesOutstanding(expected);

  EXPECT_EQ(expected, session.getFramesOutstanding());
}

TEST(SessionTests, setFullName) {
  std::string expected = "test full name";
  Session session;
  session.setFullName(expected);

  EXPECT_EQ(expected, session.getFullName());
}

TEST(SessionTests, setName) {
  std::string expected = "test name";
  Session session;
  session.setName(expected);

  EXPECT_EQ(expected, session.getName());
}

TEST(SessionTests, setUnackedMessages) {
  uint64_t expected = 23;
  Session session;
  session.setUnackedMessages(expected);

  EXPECT_EQ(expected, session.getUnackedMessages());
}

TEST(SessionTests, setVhostRef) {
  std::string expected = "test vhost ref";
  Session session;
  session.setVhostRef(expected);

  EXPECT_EQ(expected, session.getVhostRef());
}
