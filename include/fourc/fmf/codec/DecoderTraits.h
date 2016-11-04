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

#ifndef FOURC_FMF_DECODERTRAITS_H
#define FOURC_FMF_DECODERTRAITS_H

#include "AclDecoder.h"
#include "AclLookupDecoder.h"
#include "BindingDecoder.h"
#include "BrokerDecoder.h"
#include "ClusterDecoder.h"
#include "ConnectionDecoder.h"
#include "EchoDecoder.h"
#include "ExchangeDecoder.h"
#include "HaBrokerDecoder.h"
#include "LinkDecoder.h"
#include "MemoryDecoder.h"
#include "QueueDecoder.h"
#include "SessionDecoder.h"
#include "SubscriptionDecoder.h"
#include "TrivialDecoder.h"

namespace fourc {
namespace fmf {
namespace codec {

template<typename ObjectT, typename VariantT>
class decoder_traits {
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Acl, VariantT> {
public:
  typedef AclDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::AclLookupType, VariantT> {
public:
  typedef AclLookupDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Binding, VariantT> {
public:
  typedef BindingDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Broker, VariantT> {
public:
  typedef BrokerDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Cluster, VariantT> {
public:
  typedef ClusterDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Connection, VariantT> {
public:
  typedef ConnectionDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::EchoType, VariantT> {
public:
  typedef EchoDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Exchange, VariantT> {
public:
  typedef ExchangeDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::HaBroker, VariantT> {
public:
  typedef HaBrokerDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Link, VariantT> {
public:
  typedef LinkDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Memory, VariantT> {
public:
  typedef MemoryDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<Queue, VariantT> {
public:
  typedef QueueDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Session, VariantT> {
public:
  typedef SessionDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::Subscription, VariantT> {
public:
  typedef SubscriptionDecoder<VariantT> DecoderType;
};

template<typename VariantT>
class decoder_traits<fourc::fmf::TrivialResponseType, VariantT> {
public:
  typedef TrivialDecoder<VariantT> DecoderType;
};

}}} // Namespaces

#endif //FOURC_FMF_DECODERTRAITS_H
