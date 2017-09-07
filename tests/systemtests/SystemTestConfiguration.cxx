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

#include "SystemTestConfiguration.h"
#include "SystemTestConstants.h"
#include "LocalHostAddress.h"

#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>

namespace fourc {
namespace testing {

std::string SystemTestConfiguration::getHost() {
  char *addr = getenv(ENV_BROKER_ADDRESS.c_str());

  std::string address;
  if (addr != nullptr) {
    address = addr;
    address = address.substr(0, address.find(":"));
  } else {
    address = LocalHostAddress::getLocalHostAddress();
  }

  return address;
}

uint16_t SystemTestConfiguration::getPort() {
  char *p = getenv(ENV_BROKER_PORT.c_str());

  uint16_t port = 5672;
  if (p != nullptr) {
    port = boost::lexical_cast<uint16_t>(p, strlen(p));
  }

  return port;
}

std::string SystemTestConfiguration::buildUrl() {
  return boost::str(boost::format("%s:%d") % getHost() % getPort());
}

std::string SystemTestConfiguration::getConnectionOptions() {
  char *opts = getenv(ENV_BROKER_CONNECTION_OPTIONS.c_str());

  std::string options = "{transport:tcp, protocol:amqp0-10}";
  if (opts != nullptr) {
    options = opts;
  }

  return options;
}

}} // Namespaces
