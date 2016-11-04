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

#ifndef TESTS_UNITTESTS_MOCKS_SUBSYSTEM_DURATION_H_
#define TESTS_UNITTESTS_MOCKS_SUBSYSTEM_DURATION_H_

#include <gmock/gmock.h>

namespace subsystem { namespace mocks {

class Duration {
public:
  Duration(long int = 0) {}
  Duration(const Duration&) {}
  Duration(Duration&&) {}
  virtual ~Duration() = default;

  MOCK_CONST_METHOD0(getMilliseconds, uint());

};

}} // Namespaces

#endif /* TESTS_UNITTESTS_MOCKS_SUBSYSTEM_DURATION_H_ */
