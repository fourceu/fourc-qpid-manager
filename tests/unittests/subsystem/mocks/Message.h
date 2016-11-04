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

#ifndef TESTS_UNITTESTS_MOCKS_SUBSYSTEM_MESSAGE_H_
#define TESTS_UNITTESTS_MOCKS_SUBSYSTEM_MESSAGE_H_

#include <gmock/gmock.h>

#include "Variant.h"

namespace subsystem { namespace mocks {

class Address;
class Duration;

class Message {
public:
  Message(const std::string& = std::string()) {
//    ON_CALL(*this, getProperties()).WillByDefault(testing::ReturnRef(properties));
//    ON_CALL(testing::Const(*this), getProperties()).WillByDefault(testing::ReturnRef(const_properties));
  }
  Message(const Message&) {
//    ON_CALL(*this, getProperties()).WillByDefault(testing::ReturnRef(properties));
//    ON_CALL(testing::Const(*this), getProperties()).WillByDefault(testing::ReturnRef(const_properties));
  }

  MOCK_CONST_METHOD0(getReplyTo, const Address&());
  MOCK_METHOD1(setReplyTo, void(const Address&));

  MOCK_CONST_METHOD0(getSubject, std::string&());
  MOCK_METHOD1(setSubject, void(const std::string&));

  MOCK_CONST_METHOD0(getContentType, std::string&());
  MOCK_METHOD1(setContentType, void(const std::string&));

  MOCK_CONST_METHOD0(getMessageId, std::string&());
  MOCK_METHOD1(setMessageId, void(const std::string&));

  MOCK_CONST_METHOD0(getUserId, std::string&());
  MOCK_METHOD1(setUserId, void(const std::string&));

  MOCK_CONST_METHOD0(getCorrelationId, std::string&());
  MOCK_METHOD1(setCorrelationId, void(const std::string&));

  MOCK_CONST_METHOD0(getPriority, uint8_t());
  MOCK_METHOD1(setPriority, void( uint8_t));

  MOCK_METHOD0(getTtl, Duration&()); // Naughty - doesn't match qpid signature, but makes testing nicer!
  MOCK_METHOD1(setTtl, void(const Duration&));

  MOCK_CONST_METHOD0(getDurable, bool());
  MOCK_METHOD1(setDurable, void(bool));

  MOCK_CONST_METHOD0(getRedelivered, bool());
  MOCK_METHOD1(setRedelivered, void(bool));

  MOCK_CONST_METHOD0(getContent, std::string());
  MOCK_METHOD1(setContent, void(const std::string&));
  MOCK_METHOD2(setContent, void(const char*, size_t));

  MOCK_CONST_METHOD0(getContentBytes, std::string());
  MOCK_METHOD1(setContentBytes, void(const std::string&));

  MOCK_METHOD1(setContentObject, void(const Variant&));
  MOCK_METHOD0(getContentObject, Variant&());
  MOCK_CONST_METHOD0(getContentObject, const Variant&());

  MOCK_CONST_METHOD0(getContentPtr, const char*());
  MOCK_CONST_METHOD0(getContentSize, size_t());

  MOCK_CONST_METHOD0(getProperties, const std::map<std::string, Variant>&());
  MOCK_METHOD0(getProperties, std::map<std::string, Variant>&());

  MOCK_METHOD2(setProperty, void(const std::string&, const Variant&));
};

}} // Namespaces

#endif /* TESTS_UNITTESTS_MOCKS_SUBSYSTEM_MESSAGE_H_ */
