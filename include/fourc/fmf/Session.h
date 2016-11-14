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

#ifndef FOURC_FMF_SESSION_H
#define FOURC_FMF_SESSION_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Session : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Session();

  uint64_t getTxnCommits() const;
  Session& setTxnCommmits(uint64_t);

  uint32_t getTxnCount() const;
  Session& setTxnCount(uint32_t);

  uint64_t getTxnRejects() const;
  Session& setTxnRejects(uint64_t);

  uint64_t getTxnStarts() const;
  Session& setTxnStarts(uint64_t);

  bool isAttached() const;
  Session& setAttached(bool);

  uint16_t getChannelId() const;
  Session& setChannelId(uint16_t);

  uint32_t getClientCredit() const;
  Session& setClientCredit(uint32_t);

  uint64_t getConnectionEpoch() const;
  Session& setConnectionEpoch(uint64_t);

  const std::string& getConnectionName() const;
  Session& setConnectionName(const std::string&);

  uint32_t getDetachedLifespan() const;
  Session& setDetachedLifespan(uint32_t);

  uint32_t getFramesOutstanding() const;
  Session& setFramesOutstanding(uint32_t);

  const std::string& getFullName() const;
  Session& setFullName(const std::string&);

  const std::string& getName() const;
  Session& setName(const std::string&);

  uint64_t getUnackedMessages() const;
  Session& setUnackedMessages(uint64_t);

  const std::string& getVhostRef() const;
  Session& setVhostRef(const std::string&);

private:
  uint64_t txnCommits;
  uint32_t txnCount;
  uint64_t txnRejects;
  uint64_t txnStarts;
  bool attached;
  uint16_t channelId;
  uint32_t clientCredit;
  uint64_t connectionEpoch;
  std::string connectionName;
  uint32_t detachedLifespan;
  uint32_t framesOutstanding;
  std::string fullName;
  std::string name;
  uint64_t unackedMessages;
  std::string vhostRef;
};

}} // Namespaces

#endif //FOURC_FMF_SESSION_H
