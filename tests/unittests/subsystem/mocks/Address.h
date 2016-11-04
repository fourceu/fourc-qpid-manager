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

#ifndef TESTS_UNITTESTS_MOCKS_SUBSYSTEM_ADDRESS_H_
#define TESTS_UNITTESTS_MOCKS_SUBSYSTEM_ADDRESS_H_

#include <gmock/gmock.h>

#include "Variant.h"

namespace subsystem { namespace mocks {

class Address {
public:
  Address() = default;
  Address(const Address&) {}
  Address(const std::string&) {}
  Address(const std::string&, const std::string&, const Variant::Map& , const std::string& = "") {}
  virtual ~Address() = default;

  MOCK_CONST_METHOD1(equals, bool(const Address&));

  virtual bool operator==(const Address& ) const {
    return true;
  };
};

}} // Namespaces

#endif /* TESTS_UNITTESTS_MOCKS_SUBSYSTEM_ADDRESS_H_ */
