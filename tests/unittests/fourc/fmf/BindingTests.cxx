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
#include <fourc/fmf/Binding.h>

using namespace fourc::fmf;

TEST(BindingTests, ctor) {
  auto instance = new Binding();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BindingTests, ctorSetsExchangeName) {
  Binding binding;

  EXPECT_TRUE(binding.getExchangeName().empty());
}

TEST(BindingTests, ctorSetsQueueName) {
  Binding binding;

  EXPECT_TRUE(binding.getQueueName().empty());
}

TEST(BindingTests, ctorSetsBindingKey) {
  Binding binding;

  EXPECT_TRUE(binding.getBindingKey().empty());
}

TEST(BindingTests, ctorSetsExchangeEpoch) {
  Binding binding;

  EXPECT_EQ(0u, binding.getExchangeEpoch());
}

TEST(BindingTests, ctorSetsQueueEpoch) {
  Binding binding;

  EXPECT_EQ(0u, binding.getQueueEpoch());
}

TEST(BindingTests, ctorSetsMsgMatched) {
  Binding binding;

  EXPECT_EQ(0u, binding.getMsgMatched());
}

TEST(BindingTests, setExchangeName) {
  std::string expected = "test value";
  Binding binding;
  binding.setExchangeName(expected);

  EXPECT_EQ(expected, binding.getExchangeName());
}

TEST(BindingTests, setQueueName) {
  std::string expected = "test value";
  Binding binding;
  binding.setQueueName(expected);

  EXPECT_EQ(expected, binding.getQueueName());
}

TEST(BindingTests, setBindingKey) {
  std::string expected = "test value";
  Binding binding;
  binding.setBindingKey(expected);

  EXPECT_EQ(expected, binding.getBindingKey());
}

TEST(BindingTests, setExchangeEpoch) {
  uint64_t expected = 42;
  Binding binding;
  binding.setExchangeEpoch(expected);

  EXPECT_EQ(expected, binding.getExchangeEpoch());
}

TEST(BindingTests, setQueueEpoch) {
  uint64_t expected = 42;
  Binding binding;
  binding.setQueueEpoch(expected);

  EXPECT_EQ(expected, binding.getQueueEpoch());
}

TEST(BindingTests, setMsgMatched) {
  uint64_t expected = 42;
  Binding binding;
  binding.setMsgMatched(expected);

  EXPECT_EQ(expected, binding.getMsgMatched());
}
