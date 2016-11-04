/*
 * Copyright (C) 2016 FourC AS, http://www.fourc.eu/
 * All Rights Reserved.
 */

#ifndef FOURC_FMF_BROKER_H
#define FOURC_FMF_BROKER_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Broker : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;
};

}} // Namespaces

#endif //FOURC_FMF_BROKER_H
