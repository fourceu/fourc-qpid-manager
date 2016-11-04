/*
 * Copyright (C) 2016 FourC AS, http://www.fourc.eu/
 * All Rights Reserved.
 */

#ifndef FOURC_FMF_BROKERAGENT_H
#define FOURC_FMF_BROKERAGENT_H

#include <qpid/messaging/Address.h>
#include <qpid/messaging/Session.h>
#include <qpid/messaging/Sender.h>
#include <qpid/messaging/Receiver.h>
#include <qpid/messaging/Message.h>
#include <qpid/messaging/Duration.h>
#include <qpid/types/Variant.h>

#include "BrokerAgentTemplate.h"

namespace fourc {
namespace fmf {

typedef BrokerAgentTemplate<qpid::messaging::Address, qpid::messaging::Session, qpid::messaging::Receiver,
  qpid::messaging::Message, qpid::messaging::Duration, qpid::types::Variant> BrokerAgent;

}} // Namespaces

#endif //FOURC_FMF_BROKERAGENT_H
