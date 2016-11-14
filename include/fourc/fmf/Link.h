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

#ifndef FOURC_FMF_LINK_H
#define FOURC_FMF_LINK_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Link : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;
  
  Link();
  
  uint64_t getConnectionEpoch() const;
  Link& setConnectionEpoch(uint64_t);
  
  const std::string& getConnectionName() const;
  Link& setConnectionName(const std::string&);
  
  bool isDurable() const;
  Link& setDurable(bool);
  
  const std::string& getHost() const;
  Link& setHost(const std::string&);
  
  uint16_t getPort() const;
  Link& setPort(uint16_t);
  
  const std::string& getLastError() const;
  Link& setLastError(const std::string&);

  const std::string& getName() const;
  Link& setName(const std::string&);
  
  const std::string& getState() const;
  Link& setState(const std::string&);

  const std::string& getTransport() const;
  Link& setTransport(const std::string&);

  const std::string& getVhostRef() const;
  Link& setVhostRef(const std::string&);
  
private:
  uint64_t connectionEpoch;
  std::string connectionName;
  bool durable;
  std::string host;
  uint16_t port;
  std::string lastError;
  std::string name;
  std::string state;
  std::string transport;
  std::string vhostRef;  
};

}} // Namespaces

#endif //FOURC_FMF_LINK_H
