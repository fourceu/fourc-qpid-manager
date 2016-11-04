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

#ifndef TESTS_UNITTESTS_MOCKDEFAULTVALUEHANDLER_H_
#define TESTS_UNITTESTS_MOCKDEFAULTVALUEHANDLER_H_

/**
 * Applies RAII principle to gmock's default value feature, ensuring that the default value is cleared
 * at the end of the test (or, more specifically, scope of the MockDefaultValueHandler instance)
 *
 * This is necessary to ensure that a failing test does not leave the GMock framework in a dirty state,
 * causing other tests to mysteriously fail.
 *
 * Confucius, he say: "One ugly hack begets another".
 */

template <typename T> class MockDefaultValueHandler {
public:
  MockDefaultValueHandler(const T& value) {
    testing::DefaultValue<T>::Set(value);
  }

  virtual ~MockDefaultValueHandler() {
    testing::DefaultValue<T>::Clear();
  }
};

#endif /* TESTS_UNITTESTS_MOCKDEFAULTVALUEHANDLER_H_ */
