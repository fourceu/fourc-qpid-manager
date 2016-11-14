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

#ifndef FOURC_FMF_BINDING_H
#define FOURC_FMF_BINDING_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Binding : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Binding();

  const std::string& getExchangeName() const;
  Binding& setExchangeName(const std::string&);

  const std::string& getQueueName() const;
  Binding& setQueueName(const std::string&);

  const std::string& getBindingKey() const;
  Binding& setBindingKey(const std::string&);

  uint64_t getExchangeEpoch() const;
  Binding& setExchangeEpoch(uint64_t);

  uint64_t getQueueEpoch() const;
  Binding& setQueueEpoch(uint64_t);

  uint64_t getMsgMatched() const;
  Binding& setMsgMatched(uint64_t);

private:
  std::string exchangeName;
  std::string queueName;
  std::string bindingKey;
  uint64_t exchangeEpoch;
  uint64_t queueEpoch;
  int msgMatched;
};

}} // Namespaces

#endif //FOURC_FMF_BINDING_H
