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

  int getAgentEpoch() const;
  ObjectId& setAgentEpoch(int);

  bool operator==(const ObjectId&) const;
private:
  std::string name;
  int agentEpoch;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_OBJECTID_H
