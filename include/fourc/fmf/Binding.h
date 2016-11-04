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

  const std::string& getExchange() const;
  const std::string& getQueue() const;
  const std::string& getBindingKey() const;
  bool isDurable() const;

  Binding& setExchange(const std::string&);
  Binding& setQueue(const std::string&);
  Binding& setBindingKey(const std::string&);
  Binding& setDurable(bool );

protected:
  std::string exchange;
  std::string queue;
  std::string bindingKey;
  bool durable;
};

}} // Namespaces

#endif //FOURC_FMF_BINDING_H
