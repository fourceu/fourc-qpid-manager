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

#ifndef TESTS_UNITTESTS_SUBSYSTEM_MOCKS_SENDER_H_
#define TESTS_UNITTESTS_SUBSYSTEM_MOCKS_SENDER_H_

#include <gmock/gmock.h>

namespace subsystem { namespace mocks {

class Address;
class Message;

class Sender {
public:
  Sender() = default;
  Sender(const Sender&) {}

  MOCK_METHOD0(close, void());

  MOCK_METHOD1(setCapacity, void(uint32_t));

  // The following integral getters are declared non-const to match the qpid interface
  MOCK_METHOD0(getCapacity, uint32_t());
  MOCK_METHOD0(getUnsettled, uint32_t());
  MOCK_METHOD0(getAvailable, uint32_t());

  MOCK_METHOD2(send, void(const Message& message, bool sync));

  MOCK_CONST_METHOD0(getName, const std::string&());
  MOCK_CONST_METHOD0(getAddress, const Address());
  //MOCK_CONST_METHOD0(getSession, Session());

};

}} // Namespaces

#endif /* TESTS_UNITTESTS_SUBSYSTEM_MOCKS_SENDER_H_ */
