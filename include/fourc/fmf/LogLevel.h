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

#ifndef FOURC_QPID_MANAGER_LOGLEVEL_H
#define FOURC_QPID_MANAGER_LOGLEVEL_H

#include "BrokerObject.h"

#include <string>

namespace fourc {
namespace fmf {

class LogLevel : public BrokerObject {
public:
  LogLevel() = default;

  const std::string& getLevel() const;
  void setLevel(const std::string& level);

protected:
  std::string level;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_LOGLEVEL_H
