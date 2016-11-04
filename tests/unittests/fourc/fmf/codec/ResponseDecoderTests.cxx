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

#include <gmock/gmock.h>
#include <fourc/fmf/codec/ResponseDecoder.h>

#include <subsystem/mocks/Address.h>
#include <subsystem/mocks/Connection.h>
#include <subsystem/mocks/Duration.h>
#include <subsystem/mocks/Message.h>
#include <subsystem/mocks/Receiver.h>
#include <subsystem/mocks/Sender.h>
#include <subsystem/mocks/Session.h>
#include <subsystem/mocks/Variant.h>

using namespace fourc::fmf::codec;

TEST(ResponseDecoderTests, ctor) {
  auto instance = new ResponseDecoder<subsystem::mocks::Message, fourc::fmf::Exchange, subsystem::mocks::Variant>();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

