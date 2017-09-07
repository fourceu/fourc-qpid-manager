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

#include <SubsystemTypeSpecialisations.h>

using namespace fourc::fmf;

using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;
using ::testing::A;
using ::testing::_;

/**
 * Provides public access to protected fields
 */
class BrokerAgentMockProtectedAccessor : public BrokerAgentMock {
public:
  BrokerAgentMockProtectedAccessor(subsystem::mocks::Session& session) : BrokerAgentMock(session) {}

  int sendMessage(subsystem::mocks::Message& message, subsystem::mocks::Address& replyAddress) {
    return BrokerAgentMock::sendMessage(message, replyAddress);
  }
};

TEST(BrokerAgentTests, ctor) {
  subsystem::mocks::Session session;
  auto instance = new BrokerAgentMock(session);

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BrokerAgentTests, sendMessageSetsCorrelationId) {
  const std::string EXPECTED_CORRELATION_ID = "1";

  subsystem::mocks::Sender ss_sender;

  subsystem::mocks::Address ss_address;
  subsystem::mocks::Session ss_session;
  EXPECT_CALL(ss_session, createSender(A<const std::string&>())).Times(Exactly(1)).WillOnce(Return(ss_sender));

  BrokerAgentMockProtectedAccessor brokerAgent(ss_session);

  subsystem::mocks::Message ss_message;
  EXPECT_CALL(ss_message, setCorrelationId(EXPECTED_CORRELATION_ID)).Times(Exactly(1));
  EXPECT_CALL(ss_message, setReplyTo(A<const subsystem::mocks::Address&>())).Times(Exactly(1));

  brokerAgent.sendMessage(ss_message, ss_address);
}

TEST(BrokerAgentTests, sendMessageIncrementsCorrelationId) {
  int iterations = 10;
  subsystem::mocks::Sender ss_sender;

  subsystem::mocks::Address ss_address;
  subsystem::mocks::Session ss_session;
  EXPECT_CALL(ss_session, createSender(A<const std::string&>())).Times(Exactly(iterations)).WillRepeatedly(Return(ss_sender));

  BrokerAgentMockProtectedAccessor brokerAgent(ss_session);

  subsystem::mocks::Message ss_message;
  EXPECT_CALL(ss_message, setCorrelationId(A<const std::string&>())).Times(Exactly(iterations));
  EXPECT_CALL(ss_message, setReplyTo(A<const subsystem::mocks::Address&>())).Times(Exactly(iterations));

  for (int i = 1; i <= iterations; ++i) {
    EXPECT_EQ(i, brokerAgent.sendMessage(ss_message, ss_address));
  }
}

TEST(BrokerAgentTests, sendMessageSetsSubject) {
  const std::string EXPECTED_SUBJECT = "broker";
  subsystem::mocks::Sender ss_sender;

  subsystem::mocks::Address ss_address;
  subsystem::mocks::Session ss_session;
  EXPECT_CALL(ss_session, createSender(A<const std::string&>())).Times(Exactly(1)).WillOnce(Return(ss_sender));

  BrokerAgentMockProtectedAccessor brokerAgent(ss_session);

  subsystem::mocks::Message ss_message;
  EXPECT_CALL(ss_message, setCorrelationId(A<const std::string&>())).Times(Exactly(1));
  EXPECT_CALL(ss_message, setReplyTo(A<const subsystem::mocks::Address&>())).Times(Exactly(1));

  brokerAgent.sendMessage(ss_message, ss_address);
}

TEST(BrokerAgentTests, sendMessageSetsReplyAddress) {
  subsystem::mocks::Sender ss_sender;
  subsystem::mocks::Address ss_address;

  subsystem::mocks::Session ss_session;
  EXPECT_CALL(ss_session, createSender(A<const std::string&>())).Times(Exactly(1)).WillOnce(Return(ss_sender));

  BrokerAgentMockProtectedAccessor brokerAgent(ss_session);

  subsystem::mocks::Message ss_message;
  EXPECT_CALL(ss_message, setCorrelationId(A<const std::string&>())).Times(Exactly(1));
  EXPECT_CALL(ss_message, setReplyTo(ss_address)).Times(Exactly(1));

  brokerAgent.sendMessage(ss_message, ss_address);
}
