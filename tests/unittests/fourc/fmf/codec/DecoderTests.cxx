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

#include <fourc/fmf/codec/Decoder.h>
#include <fourc/fmf/BrokerObject.h>

#include <qpid/types/Variant.h>

using namespace fourc::fmf::codec;

using ::testing::A;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnRef;

using BrokerObject = fourc::fmf::BrokerObject;

class TestDecoder : public Decoder<BrokerObject, qpid::types::Variant> {
public:
  /**
   * \brief Implements this abstract method to allow instantiation of the class
   * @return
   */
  virtual std::shared_ptr<BrokerObject> decode(const qpid::types::Variant::Map& ) const {
    throw std::runtime_error("This method doesn't need testing (it's a test method)");
  }

  void decodeTimestamps(std::shared_ptr<BrokerObject>& object, const MapT& objectProperties) const {
    return Decoder<BrokerObject, qpid::types::Variant>::decodeTimestamps(object, objectProperties);
  }
};

TEST(DecoderTests, ctor) {
  auto instance = new TestDecoder();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(DecoderTests, decodeTimestamps) {
  // This test is written with a heavy heart as it's the first one I wrote after Trump got elected. We are doomed indeed!
  auto timestamp_ns = 1478676600001000001; // Approximate time the dreadful news broke in nanoseconds since Unix epoch

  qpid::types::Variant::Map objectProperties = {
      { RPNs::CREATED, timestamp_ns }
  };

  TestDecoder decoder;
  auto brokerObject = std::make_shared<BrokerObject>();
  decoder.decodeTimestamps(brokerObject, objectProperties);

  //std::cout << "Nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(brokerObject->getTimeCreated() - std::chrono::system_clock::from_time_t(0)).count() << std::endl;

  EXPECT_EQ(timestamp_ns,
            std::chrono::duration_cast<std::chrono::nanoseconds>(
                brokerObject->getTimeCreated() - std::chrono::system_clock::from_time_t(0)).count()); // We want our ns back!
}
