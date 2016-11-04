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
#include <fourc/fmf/BrokerObject.h>

using namespace fourc::fmf;

TEST(BrokerObjectTests, ctor) {
  auto instance = new BrokerObject();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BrokerObjectTests, getTimeCreated) {
  std::chrono::system_clock::time_point time_point;
  auto expected = std::chrono::system_clock::now();

  BrokerObject brokerObject;
  brokerObject.setTimeCreated(expected);

  EXPECT_NE(time_point, brokerObject.getTimeCreated());
  EXPECT_EQ(time_point, brokerObject.getTimeDeleted());
  EXPECT_EQ(time_point, brokerObject.getTimeUpdated());

  EXPECT_EQ(expected, brokerObject.getTimeCreated());
}

TEST(BrokerObjectTests, getTimeDeleted) {
  std::chrono::system_clock::time_point time_point;
  auto expected = std::chrono::system_clock::now();

  BrokerObject brokerObject;
  brokerObject.setTimeDeleted(expected);

  EXPECT_EQ(time_point, brokerObject.getTimeCreated());
  EXPECT_NE(time_point, brokerObject.getTimeDeleted());
  EXPECT_EQ(time_point, brokerObject.getTimeUpdated());

  EXPECT_EQ(expected, brokerObject.getTimeDeleted());
}

TEST(BrokerObjectTests, getTimeUpdated) {
  std::chrono::system_clock::time_point time_point;
  auto expected = std::chrono::system_clock::now();

  BrokerObject brokerObject;
  brokerObject.setTimeUpdated(expected);

  EXPECT_EQ(time_point, brokerObject.getTimeCreated());
  EXPECT_EQ(time_point, brokerObject.getTimeDeleted());
  EXPECT_NE(time_point, brokerObject.getTimeUpdated());

  EXPECT_EQ(expected, brokerObject.getTimeUpdated());
}