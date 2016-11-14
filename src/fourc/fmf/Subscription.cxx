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

#include <fourc/fmf/Subscription.h>

namespace fourc {
namespace fmf {

const std::string Subscription::OBJECT_TYPE_NAME = "subscription";

Subscription::Subscription() :
  acknowledged(false),
  browsing(false),
  delivered(0),
  exclusive(false),
  queueEpoch(0),
  sessionEpoch(0) {
}

bool Subscription::isAcknowledged() const {
  return acknowledged;
}

Subscription& Subscription::setAcknowledged(bool value) {
  acknowledged = value;

  return *this;
}

bool Subscription::isBrowsing() const {
  return browsing;
}

Subscription& Subscription::setBrowsing(bool value) {
  browsing = value;

  return *this;
}

const std::string& Subscription::getCreditMode() const {
  return creditMode;
}

Subscription& Subscription::setCreditMode(const std::string& value) {
  creditMode = value;

  return *this;
}

uint64_t Subscription::getDelivered() const {
  return delivered;
}

Subscription& Subscription::setDelivered(uint64_t value) {
  delivered = value;

  return *this;
}

bool Subscription::isExclusive() const {
  return exclusive;
}

Subscription& Subscription::setExclusive(bool value) {
  exclusive = value;

  return *this;
}

const std::string& Subscription::getName() const {
  return name;
}

Subscription& Subscription::setName(const std::string& value) {
  name = value;

  return *this;
}

uint64_t Subscription::getQueueEpoch() const {
  return queueEpoch;
}

Subscription& Subscription::setQueueEpoch(uint64_t value) {
  queueEpoch = value;

  return *this;
}

const std::string& Subscription::getQueueName() const {
  return queueName;
}

Subscription& Subscription::setQueueName(const std::string& value) {
  queueName = value;

  return *this;
}

uint64_t Subscription::getSessionEpoch() const {
  return sessionEpoch;
}

Subscription& Subscription::setSessionEpoch(uint64_t value) {
  sessionEpoch = value;

  return *this;
}

const std::string& Subscription::getSessionName() const {
  return sessionName;
}

Subscription& Subscription::setSessionName(const std::string& value) {
  sessionName = value;

  return *this;
}

}} // Namespaces
