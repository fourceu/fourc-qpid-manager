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

#ifndef FOURC_QPID_MANAGER_RESPONSEPROPERTYNAMES_H
#define FOURC_QPID_MANAGER_RESPONSEPROPERTYNAMES_H

#include <string>

namespace fourc {
namespace fmf {
namespace codec {

class ResponsePropertyNames {
public:
  static const std::string CREATED;
  static const std::string DELETED;
  static const std::string UPDATED;
  static const std::string VALUES;
  static const std::string NAME;
  static const std::string OBJECT_ID;
  static const std::string OBJECT_NAME;
  static const std::string OBJECT_AGENT_EPOCH;
  static const std::string DURABLE;
  static const std::string SCHEMA_ID;
  static const std::string SCHEMA_CLASS_NAME;
  static const std::string SCHEMA_HASH;
  static const std::string SCHEMA_PACKAGE_NAME;
  static const std::string SCHEMA_TYPE;
  static const std::string VHOST_REF;
};

}}} // Namespaces

#endif //FOURC_QPID_MANAGER_RESPONSEPROPERTYNAMES_H
