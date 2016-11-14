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

#include <fourc/fmf/Session.h>

namespace fourc {
namespace fmf {

const std::string Session::OBJECT_TYPE_NAME = "session";

Session::Session() :
    txnCommits(0),
    txnCount(0),
    txnRejects(0),
    txnStarts(0),
    attached(false),
    channelId(0),
    clientCredit(0),
    connectionEpoch(0),
    detachedLifespan(0),
    framesOutstanding(0),
    unackedMessages(0) {

}

uint64_t Session::getTxnCommits() const {
  return txnCommits;
}

Session& Session::setTxnCommmits(uint64_t value) {
  txnCommits = value;

  return *this;
}

uint32_t Session::getTxnCount() const {
  return txnCount;
}

Session& Session::setTxnCount(uint32_t value) {
  txnCount = value;

  return *this;
}

uint64_t Session::getTxnRejects() const {
  return txnRejects;
}

Session& Session::setTxnRejects(uint64_t value) {
  txnRejects = value;

  return *this;
}

uint64_t Session::getTxnStarts() const {
  return txnStarts;
}

Session& Session::setTxnStarts(uint64_t value) {
  txnStarts = value;

  return *this;
}

bool Session::isAttached() const {
  return attached;
}

Session& Session::setAttached(bool value) {
  attached = value;

  return *this;
}

uint16_t Session::getChannelId() const {
  return channelId;
}

Session& Session::setChannelId(uint16_t value) {
  channelId = value;

  return *this;
}

uint32_t Session::getClientCredit() const {
  return clientCredit;
}

Session& Session::setClientCredit(uint32_t value) {
  clientCredit = value;

  return *this;
}

uint64_t Session::getConnectionEpoch() const {
  return connectionEpoch;
}

Session& Session::setConnectionEpoch(uint64_t value) {
  connectionEpoch = value;

  return *this;
}

const std::string& Session::getConnectionName() const {
  return connectionName;
}

Session& Session::setConnectionName(const std::string& value) {
  connectionName = value;

  return *this;
}

uint32_t Session::getDetachedLifespan() const {
  return detachedLifespan;
}

Session& Session::setDetachedLifespan(uint32_t value) {
  detachedLifespan = value;

  return *this;
}

uint32_t Session::getFramesOutstanding() const {
  return framesOutstanding;
}

Session& Session::setFramesOutstanding(uint32_t value) {
  framesOutstanding = value;

  return *this;
}

const std::string& Session::getFullName() const {
  return fullName;
}

Session& Session::setFullName(const std::string& value) {
  fullName = value;

  return *this;
}

const std::string& Session::getName() const {
  return name;
}

Session& Session::setName(const std::string& value) {
  name = value;

  return *this;
}

uint64_t Session::getUnackedMessages() const {
  return unackedMessages;
}

Session& Session::setUnackedMessages(uint64_t value) {
  unackedMessages = value;

  return *this;
}

const std::string& Session::getVhostRef() const {
  return vhostRef;
}

Session& Session::setVhostRef(const std::string& value) {
  vhostRef = value;

  return *this;
}

}} // Namespaces
