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

#include <fourc/fmf/Bridge.h>

namespace fourc {
namespace fmf {

const std::string Bridge::OBJECT_TYPE_NAME = "bridge";

Bridge::Bridge() : channelId(0u),
                   durable(false),
                   srcIsQueue(false),
                   srcIsLocal(false),
                   dynamic(false),
                   sync(0u),
                   credit(0u) {
}

std::string Bridge::getLinkRef() const {
  return linkRef;
}

Bridge& Bridge::setLinkRef(const std::string& value) {
  linkRef = value;
  return *this;
}

std::string Bridge::getName() const {
  return name;
}

Bridge& Bridge::setName(const std::string& value) {
  name = value;
  return *this;
}

uint16_t Bridge::getChannelId() const {
  return channelId;
}

Bridge& Bridge::setChannelId(const uint16_t value) {
  channelId = value;
  return *this;
}

bool Bridge::isDurable() const  {
  return durable;
}

Bridge& Bridge::setDurable(bool value) {
  durable = value;
  return *this;
}

std::string Bridge::getSrc() const {
  return src;
}

Bridge& Bridge::setSrc(const std::string& value) {
  src = value;
  return *this;
}

std::string Bridge::getDest() const {
  return dest;
}

Bridge& Bridge::setDest(const std::string& value) {
  dest = value;
  return *this;
}

std::string Bridge::getKey() const {
  return key;
}

Bridge& Bridge::setKey(const std::string& value) {
  key = value;
  return *this;
}

bool Bridge::isSrcQueue() const {
  return srcIsQueue;
}

Bridge& Bridge::setSrcQueue(bool value) {
  srcIsQueue = value;
  return *this;
}

bool Bridge::isSrcLocal() const {
  return srcIsLocal;
}

Bridge& Bridge::setSrcLocal(bool value) {
  srcIsLocal = value;
  return *this;
}

std::string Bridge::getTag() const {
  return tag;
}

Bridge& Bridge::setTag(const std::string& value) {
  tag = value;
  return *this;
}

std::string Bridge::getExcludes() const  {
  return excludes;
}

Bridge& Bridge::setExcludes(const std::string& value) {
  excludes = value;
  return *this;
}

bool Bridge::isDynamic() const {
  return dynamic;
}

Bridge& Bridge::setDynamic(bool value) {
  dynamic = value;
  return *this;
}

uint16_t Bridge::getSync() const {
  return sync;
}

Bridge& Bridge::setSync(uint16_t value) {
  sync = value;
  return *this;
}

uint32_t Bridge::getCredit() const {
  return credit;
}

Bridge& Bridge::setCredit(uint32_t value) {
  credit = value;
  return *this;
}

}} // Namespaces
