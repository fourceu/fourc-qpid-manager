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

#include <fourc/fmf/Link.h>

namespace fourc {
namespace fmf {

const std::string Link::OBJECT_TYPE_NAME = "link";


Link::Link() :
  connectionEpoch(0),
  durable(false),
  port(0) {
}

uint64_t Link::getConnectionEpoch() const {
  return connectionEpoch;
}

Link& Link::setConnectionEpoch(uint64_t value) {
  connectionEpoch = value;

  return *this;
}

const std::string& Link::getConnectionName() const {
  return connectionName;
}

Link& Link::setConnectionName(const std::string& value) {
  connectionName = value;

  return *this;
}

bool Link::isDurable() const {
  return durable;
}

Link& Link::setDurable(bool value) {
  durable = value;

  return *this;
}

const std::string& Link::getHost() const {
  return host;
}

Link& Link::setHost(const std::string& value) {
  host = value;

  return *this;
}

uint16_t Link::getPort() const {
  return port;
}

Link& Link::setPort(uint16_t value) {
  port = value;

  return *this;
}

const std::string& Link::getLastError() const {
  return lastError;
}

Link& Link::setLastError(const std::string& value) {
  lastError = value;

  return *this;
}

const std::string& Link::getName() const {
  return name;
}

Link& Link::setName(const std::string& value) {
  name = value;

  return *this;
}

const std::string& Link::getState() const {
  return state;
}

Link& Link::setState(const std::string& value) {
  state = value;

  return *this;
}

const std::string& Link::getTransport() const {
  return transport;
}

Link& Link::setTransport(const std::string& value) {
  transport = value;

  return *this;
}

const std::string& Link::getVhostRef() const {
  return vhostRef;
}

Link& Link::setVhostRef(const std::string& value) {
  vhostRef = value;

  return *this;
}

}} // Namespaces
