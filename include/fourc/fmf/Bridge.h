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

#ifndef FOURC_QPID_MANAGER_BRIDGE_H
#define FOURC_QPID_MANAGER_BRIDGE_H

#include "BrokerObject.h"
#include "MethodResult.h"

#include <boost/format.hpp>

#include <memory>

namespace fourc {
namespace fmf {

class Bridge : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Bridge();
  virtual ~Bridge() = default;

  std::string getLinkRef() const;
  Bridge& setLinkRef(const std::string&);

  std::string getName() const;
  Bridge& setName(const std::string&);

  uint16_t getChannelId() const;
  Bridge& setChannelId(const uint16_t );

  bool isDurable() const;
  Bridge& setDurable(bool);

  std::string getSrc() const;
  Bridge& setSrc(const std::string&);

  std::string getDest() const;
  Bridge& setDest(const std::string&);

  std::string getKey() const;
  Bridge& setKey(const std::string&);

  bool isSrcQueue() const;
  Bridge& setSrcQueue(bool);

  bool isSrcLocal() const;
  Bridge& setSrcLocal(bool);

  std::string getTag() const;
  Bridge& setTag(const std::string&);

  std::string getExcludes() const;
  Bridge& setExcludes(const std::string&);

  bool isDynamic() const;
  Bridge& setDynamic(bool);

  uint16_t getSync() const;
  Bridge& setSync(uint16_t);

  uint32_t getCredit() const;
  Bridge& setCredit(uint32_t);

  template <typename BrokerAgentT>
  std::shared_ptr<MethodResult> closeOn(BrokerAgentT& brokerAgent) const {
    const std::string method_name("close");
    typename BrokerAgentT::VariantType::Map args;

    const auto& address = getObjectId().getName();

    return brokerAgent.template method<MethodResult, typename BrokerAgentT::VariantType::Map>(method_name, args, address);
  }

private:
  std::string linkRef;
  std::string name;
  uint16_t channelId;
  bool durable;
  std::string src;
  std::string dest;
  std::string key;
  bool srcIsQueue;
  bool srcIsLocal;
  std::string tag;
  std::string excludes;
  bool dynamic;
  uint16_t sync;
  uint32_t credit;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_BRIDGE_H
