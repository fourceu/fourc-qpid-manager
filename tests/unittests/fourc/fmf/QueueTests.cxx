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
#include <fourc/fmf/Queue.h>

using namespace fourc::fmf;

TEST(QueueTests, ctor) {
  auto instance = new Queue();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(QueueTests, ctorSetsDefaultDurableFalse) {
  Queue queue;

  EXPECT_FALSE(queue.isDurable());
}

TEST(QueueTests, ctorSetsDurableFalse) {
  Queue queue;

  EXPECT_FALSE(queue.isDurable());
}

TEST(QueueTests, operatorEquals_SameInstance) {
  Queue node1;
  auto& node2(node1);

  EXPECT_EQ(node1, node2);
}

TEST(QueueTests, operatorEquals_CopiedInstance) {
  Queue node1;
  Queue node2 = node1;

  EXPECT_EQ(node1, node2);
}

TEST(QueueTests, operatorEquals_CopyConstructedInstance) {
  Queue node1;
  Queue node2(node1);

  EXPECT_EQ(node1, node2);
}

TEST(QueueTests, operatorEqualsFalse_DifferentName) {
  Queue node1;
  Queue node2;
  node2.setName("test");

  EXPECT_FALSE(node1 == node2);
}

TEST(QueueTests, operatorEqualsFalse_DifferentDurability) {
  Queue node1;
  Queue node2;
  node2.setDurable(true);

  EXPECT_FALSE(node1 == node2);
}