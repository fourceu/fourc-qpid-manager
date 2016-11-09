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

#include <fourc/fmf/codec/ResponsePropertyNames.h>

namespace fourc {
namespace fmf {
namespace codec {

const std::string ResponsePropertyNames::CREATED = "_create_ts";
const std::string ResponsePropertyNames::DELETED = "_delete_ts";
const std::string ResponsePropertyNames::UPDATED = "_update_ts";
const std::string ResponsePropertyNames::VALUES = "_values";
const std::string ResponsePropertyNames::NAME = "name";
const std::string ResponsePropertyNames::OBJECT_ID = "_object_id";
const std::string ResponsePropertyNames::OBJECT_NAME = "_object_name";
const std::string ResponsePropertyNames::OBJECT_AGENT_EPOCH = "_agent_epoch";
const std::string ResponsePropertyNames::DURABLE = "durable";
const std::string ResponsePropertyNames::SCHEMA_ID = "_schema_id";
const std::string ResponsePropertyNames::SCHEMA_CLASS_NAME = "_class_name";
const std::string ResponsePropertyNames::SCHEMA_HASH = "_hash";
const std::string ResponsePropertyNames::SCHEMA_PACKAGE_NAME = "_package_name";
const std::string ResponsePropertyNames::SCHEMA_TYPE = "_type";
const std::string ResponsePropertyNames::VHOST_REF = "vhostRef";

}}} // Namespaces