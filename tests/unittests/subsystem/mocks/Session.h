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

#ifndef TESTS_UNITTESTS_MOCKS_SUBSYSTEM_SESSION_H_
#define TESTS_UNITTESTS_MOCKS_SUBSYSTEM_SESSION_H_

#include <gmock/gmock.h>

namespace subsystem { namespace mocks {

class Connection;
class Duration;
class Message;
class Receiver;
class Sender;

class Session {
public:
  Session() = default;
  Session(const Session&) {}
  Session(Session&&) {}

  operator bool() {return false;}

  MOCK_METHOD0(close, void());

  MOCK_METHOD0(commit, void());
  MOCK_METHOD0(rollback, void());


  MOCK_METHOD1(acknowledge, void(bool));
  MOCK_METHOD2(acknowledge, void(const Message&, bool));

  MOCK_METHOD2(acknowledgeUpTo, void(const Message&, bool));

  MOCK_METHOD1(reject, void(const Message&));
  MOCK_METHOD1(release, void(const Message&));

  MOCK_METHOD1(sync, void(bool));

  MOCK_METHOD0(getReceivable, uint32_t(void));
  MOCK_METHOD0(getUnsettledAcks, uint32_t(void));

  MOCK_METHOD2(nextReceiver, bool(Receiver&, Duration));
  MOCK_METHOD1(nextReceiver, Receiver(Duration));

  MOCK_METHOD1(createSender, Sender(const Address&));
  MOCK_METHOD1(createSender, Sender(const std::string&));

  MOCK_METHOD1(createReceiver, Receiver(const Address&));
  MOCK_METHOD1(createReceiver, Receiver(const std::string&));

  MOCK_CONST_METHOD1(getSender, Sender(const std::string&));
  MOCK_CONST_METHOD1(getReceiver, Receiver(const std::string&));

  MOCK_CONST_METHOD0(getConnection, Connection());

  MOCK_METHOD0(hasError, bool());
  MOCK_METHOD0(checkError, void());
};

}} // Namespaces

#endif /* TESTS_UNITTESTS_MOCKS_SUBSYSTEM_SESSION_H_ */
