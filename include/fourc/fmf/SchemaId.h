/*
 * Copyright (C) 2016 FourC AS, http://www.fourc.eu/
 * All Rights Reserved.
 */

#ifndef FOURC_QPID_MANAGER_SCHEMAID_H
#define FOURC_QPID_MANAGER_SCHEMAID_H

#include <string>

namespace fourc {
namespace fmf {

class SchemaId {
public:
  bool operator==(const SchemaId&) const;

  const std::string& getClassName() const;
  SchemaId& setClassName(const std::string&);

  const std::string& getHash() const;
  SchemaId& setHash(const std::string&);

  const std::string& getPackageName() const;
  SchemaId& setPackageName(const std::string&);

  const std::string& getType() const;
  SchemaId& setType(const std::string&);

private:
  std::string className;
  std::string hash;
  std::string packageName;
  std::string type;
};

}} // Namespaces

#endif //FOURC_QPID_MANAGER_SCHEMAID_H
