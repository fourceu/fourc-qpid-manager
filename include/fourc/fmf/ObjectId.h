/*
 * Copyright (C) 2016 FourC AS, http://www.fourc.eu/
 * All Rights Reserved.
 */

#ifndef FOURC_QPID_MANAGER_OBJECTID_H
#define FOURC_QPID_MANAGER_OBJECTID_H

#include <string>

namespace fourc {
namespace fmf {

class ObjectId {
public:
  ObjectId();

  const std::string& getName() const;
  ObjectId& setName(const std::string&);

  uint64_t getAgentEpoch() const;
  ObjectId& setAgentEpoch(uint64_t);

  bool operator==(const ObjectId&) const;

  operator std::string() const;

  friend std::ostream& operator <<(std::ostream& stream, const ObjectId& object) {
    stream << object.operator std::string();
    return stream;
  }

private:
  std::string name;
  uint64_t agentEpoch;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_OBJECTID_H
