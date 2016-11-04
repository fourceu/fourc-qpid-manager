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

#ifndef TESTS_UNITTESTS_MOCKS_SUBSYSTEM_CONNECTION_H_
#define TESTS_UNITTESTS_MOCKS_SUBSYSTEM_CONNECTION_H_

#include <gmock/gmock.h>

#include <string>

namespace subsystem { namespace mocks {

class Session;

class Connection {
public:
  Connection() {}
  Connection(const Connection&) {}
  Connection(const std::string&, const std::string&) {}

  MOCK_CONST_METHOD0(getUrl, std::string());
  MOCK_CONST_METHOD0(isOpen, bool());
  MOCK_CONST_METHOD0(open, void());
  MOCK_CONST_METHOD0(close, void());
  MOCK_CONST_METHOD0(reconnect, void());
  MOCK_CONST_METHOD1(reconnect, void(const std::string&));

  MOCK_METHOD1(createTransactionalSession, Session&(const std::string&));
  MOCK_METHOD1(createSession, Session&(const std::string&));

  MOCK_CONST_METHOD0(getAuthenticatedUsername, std::string());

};

}} // Namespaces

#endif /* TESTS_UNITTESTS_MOCKS_SUBSYSTEM_CONNECTION_H_ */
