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

#include <fourc/fmf/SchemaId.h>

namespace fourc {
namespace fmf {

bool SchemaId::operator==(const SchemaId& other) const {
  return className == other.className
      && packageName == other.packageName
      && hash == other.hash;
}

const std::string& SchemaId::getClassName() const {
  return className;
}

SchemaId& SchemaId::setClassName(const std::string& value) {
  className = value;

  return *this;
}

const std::string& SchemaId::getHash() const {
  return hash;
}

SchemaId& SchemaId::setHash(const std::string& value) {
  hash = value;

  return *this;
}

const std::string& SchemaId::getPackageName() const {
  return packageName;
}

SchemaId& SchemaId::setPackageName(const std::string& value) {
  packageName = value;

  return *this;
}

const std::string& SchemaId::getType() const {
  return type;
}

SchemaId& SchemaId::setType(const std::string& value) {
  type = value;

  return *this;
}

}} // Namespaces