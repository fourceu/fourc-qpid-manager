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
#include <fourc/fmf/Subscription.h>

using namespace fourc::fmf;

TEST(SubscriptionTests, ctor) {
  auto instance = new Subscription();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(SubscriptionTests, ctorSetsAcknowledged) {
  Subscription subscription;
  
  EXPECT_FALSE(subscription.isAcknowledged());
}

TEST(SubscriptionTests, ctorSetsBrowsing) {
  Subscription subscription;

  EXPECT_FALSE(subscription.isBrowsing());
}

TEST(SubscriptionTests, ctorSetsCreditMode) {
  Subscription subscription;

  EXPECT_TRUE(subscription.getCreditMode().empty());
}

TEST(SubscriptionTests, ctorSetsDelivered) {
  Subscription subscription;

  EXPECT_EQ(0u, subscription.getDelivered());
}

TEST(SubscriptionTests, ctorSetsExclusive) {
  Subscription subscription;

  EXPECT_FALSE(subscription.isExclusive());
}

TEST(SubscriptionTests, ctorSetsName) {
  Subscription subscription;

  EXPECT_TRUE(subscription.getName().empty());
}

TEST(SubscriptionTests, ctorSetsQueueEpoch) {
  Subscription subscription;

  EXPECT_EQ(0u, subscription.getQueueEpoch());
}

TEST(SubscriptionTests, ctorSetsQueueName) {
  Subscription subscription;

  EXPECT_TRUE(subscription.getQueueName().empty());
}

TEST(SubscriptionTests, ctorSetsSessionEpoch) {
  Subscription subscription;

  EXPECT_EQ(0u, subscription.getSessionEpoch());
}

TEST(SubscriptionTests, ctorSetsSessionName) {
  Subscription subscription;

  EXPECT_TRUE(subscription.getSessionName().empty());
}

// ************************

TEST(SubscriptionTests, setAcknowledged) {
  bool expected = true;
  Subscription subscription;

  EXPECT_NE(expected, subscription.isAcknowledged());
  subscription.setAcknowledged(expected);
  
  EXPECT_EQ(expected, subscription.isAcknowledged());
}

TEST(SubscriptionTests, setBrowsing) {
  bool expected = true;
  Subscription subscription;

  EXPECT_NE(expected, subscription.isBrowsing());
  subscription.setBrowsing(expected);

  EXPECT_EQ(expected, subscription.isBrowsing());
}

TEST(SubscriptionTests, setCreditMode) {
  std::string expected = "credit mode";
  Subscription subscription;
  subscription.setCreditMode(expected);

  EXPECT_EQ(expected, subscription.getCreditMode());
}

TEST(SubscriptionTests, setDelivered) {
  uint64_t expected = 29;
  Subscription subscription;
  subscription.setDelivered(expected);

  EXPECT_EQ(expected, subscription.getDelivered());
}

TEST(SubscriptionTests, setExclusive) {
  bool expected = true;
  Subscription subscription;

  EXPECT_NE(expected, subscription.isExclusive());
  subscription.setExclusive(expected);

  EXPECT_EQ(expected, subscription.isExclusive());
}

TEST(SubscriptionTests, setName) {
  std::string expected = "test name";
  Subscription subscription;
  subscription.setName(expected);

  EXPECT_EQ(expected, subscription.getName());
}

TEST(SubscriptionTests, setQueueEpoch) {
  uint32_t expected = 29;
  Subscription subscription;
  subscription.setQueueEpoch(expected);

  EXPECT_EQ(expected, subscription.getQueueEpoch());
}

TEST(SubscriptionTests, setQueueName) {
  std::string expected = "queue name";
  Subscription subscription;
  subscription.setQueueName(expected);

  EXPECT_EQ(expected, subscription.getQueueName());
}

TEST(SubscriptionTests, setSessionEpoch) {
  uint64_t expected = 29;
  Subscription subscription;
  subscription.setSessionEpoch(expected);

  EXPECT_EQ(expected, subscription.getSessionEpoch());
}

TEST(SubscriptionTests, setSessionName) {
  std::string expected = "session name";
  Subscription subscription;
  subscription.setSessionName(expected);

  EXPECT_EQ(expected, subscription.getSessionName());
}
