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

#ifndef FOURC_FMF_SUBSCRIPTION_H
#define FOURC_FMF_SUBSCRIPTION_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Subscription : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Subscription();

  bool isAcknowledged() const;
  Subscription& setAcknowledged(bool);

  bool isBrowsing() const;
  Subscription& setBrowsing(bool);
  
  const std::string& getCreditMode() const;
  Subscription& setCreditMode(const std::string&);
  
  uint64_t getDelivered() const;
  Subscription& setDelivered(uint64_t);

  bool isExclusive() const;
  Subscription& setExclusive(bool);
  
  const std::string& getName() const;
  Subscription& setName(const std::string&);

  uint64_t getQueueEpoch() const;
  Subscription& setQueueEpoch(uint64_t);

  const std::string& getQueueName() const;
  Subscription& setQueueName(const std::string&);

  uint64_t getSessionEpoch() const;
  Subscription& setSessionEpoch(uint64_t);

  const std::string& getSessionName() const;
  Subscription& setSessionName(const std::string&);
  
private:
  bool acknowledged;
  bool browsing;
  std::string creditMode;
  uint64_t delivered;
  bool exclusive;
  std::string name;
  uint64_t queueEpoch;
  std::string queueName;
  uint64_t sessionEpoch;
  std::string sessionName;
};

}} // Namespaces

#endif //FOURC_FMF_SUBSCRIPTION_H
