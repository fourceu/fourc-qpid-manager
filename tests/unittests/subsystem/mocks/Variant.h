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

#ifndef TESTS_UNITTESTS_MOCKS_SUBSYSTEM_VARIANT_H_
#define TESTS_UNITTESTS_MOCKS_SUBSYSTEM_VARIANT_H_

#include <gmock/gmock.h>

#include <map>
#include <list>

namespace subsystem { namespace mocks {

template <typename ListType, typename MapType>
class VariantTemplate {
public:
  typedef MapType Map;
  typedef ListType List;

  VariantTemplate() = default;
  VariantTemplate(const VariantTemplate &) {}
  VariantTemplate(const std::string &) {}
  virtual ~VariantTemplate() = default;
  VariantTemplate &operator=(const VariantTemplate &) { return *this; }
  VariantTemplate &operator=(const Map &) { return *this; };
  VariantTemplate &operator=(const List &) { return *this; };
};

class Variant : public VariantTemplate<std::list<Variant>, std::map<std::string, Variant>> {
public:
//  typedef std::list<Variant> List;
//  typedef std::map<std::string, Variant> Map;

  Variant() = default;
  Variant(const Variant &other) : VariantTemplate<std::list<Variant>, std::map<std::string, Variant>>(other){}
  Variant(const std::string &) {}
  Variant(const char*) {};
  Variant(const Map&) {};
  virtual ~Variant() = default;
  Variant &operator=(const Variant &) { return *this; }
  Variant &operator=(const Map &) { return *this; };
  Variant &operator=(const List &) { return *this; };

  virtual bool operator==(const Variant &other) const {
    return equals(other);
  }
  MOCK_CONST_METHOD1(equals, bool(const Variant&));

  MOCK_CONST_METHOD0(asBool, bool());
  MOCK_CONST_METHOD0(asUint8, uint8_t());
  MOCK_CONST_METHOD0(asUint16, uint16_t());
  MOCK_CONST_METHOD0(asUint32, uint32_t());
  MOCK_CONST_METHOD0(asUint64, uint64_t());
  MOCK_CONST_METHOD0(asInt8, int8_t());
  MOCK_CONST_METHOD0(asInt16, int16_t());
  MOCK_CONST_METHOD0(asInt32, int32_t());
  MOCK_CONST_METHOD0(asInt64, int64_t());
  MOCK_CONST_METHOD0(asFloat, float());
  MOCK_CONST_METHOD0(asDouble, double());
  MOCK_CONST_METHOD0(asString, std::string());
  //MOCK_CONST_METHOD0(asUuid, Uuid());

  operator std::string() const { return asString(); };

  MOCK_CONST_METHOD0(asMap, const Map&());
  MOCK_METHOD0(asMap, Map&());

  MOCK_METHOD1(setEncoding, void(const std::string&));
  MOCK_CONST_METHOD0(getEncoding, const std::string&());
};

class ReferenceVariant : public VariantTemplate<std::list<const ReferenceVariant&>, std::map<std::string, const ReferenceVariant&>> {
public:
  ReferenceVariant() = default;
  ReferenceVariant(const ReferenceVariant &other) : VariantTemplate<std::list<const ReferenceVariant&>, std::map<std::string, const ReferenceVariant&>>(other){}
  ReferenceVariant(const std::string &) {}
  ReferenceVariant(const Map&) {}
  virtual ~ReferenceVariant() = default;
  ReferenceVariant &operator=(const ReferenceVariant &) { return *this; }
  ReferenceVariant &operator=(const Map &) { return *this; };
  ReferenceVariant &operator=(Map &) { return *this; };
  ReferenceVariant &operator=(const List &) { return *this; };

  virtual bool operator==(const ReferenceVariant &other) const {
    return equals(other);
  }
  MOCK_CONST_METHOD1(equals, bool(const ReferenceVariant&));

  MOCK_CONST_METHOD0(asBool, bool());
  MOCK_CONST_METHOD0(asUint8, uint8_t());
  MOCK_CONST_METHOD0(asUint16, uint16_t());
  MOCK_CONST_METHOD0(asUint32, uint32_t());
  MOCK_CONST_METHOD0(asUint64, uint64_t());
  MOCK_CONST_METHOD0(asInt8, int8_t());
  MOCK_CONST_METHOD0(asInt16, int16_t());
  MOCK_CONST_METHOD0(asInt32, int32_t());
  MOCK_CONST_METHOD0(asInt64, int64_t());
  MOCK_CONST_METHOD0(asFloat, float());
  MOCK_CONST_METHOD0(asDouble, double());
  MOCK_CONST_METHOD0(asString, std::string());
  //MOCK_CONST_METHOD0(asUuid, Uuid());

  operator std::string() const { return asString(); };

  MOCK_CONST_METHOD0(asMap, const Map&());

  MOCK_METHOD1(setEncoding, void(const std::string&));
  MOCK_CONST_METHOD0(getEncoding, const std::string&());
};

static std::ostream& operator<<(std::ostream& out, const Variant& ) { out << "<Variant>"; return out; }
static std::ostream& operator<<(std::ostream& out, const ReferenceVariant& ) { out << "<ReferenceVariant>"; return out; }

}} // Namespaces

#endif /* TESTS_UNITTESTS_MOCKS_SUBSYSTEM_VARIANT_H_ */
