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
#include <fourc/fmf/Binding.h>

using namespace fourc::fmf;

TEST(BindingTests, ctor) {
  std::string exchange;
  std::string queue;
  std::string key;
  auto instance = new Binding();

  EXPECT_NE(nullptr, instance);

  delete instance;
}

TEST(BindingTests, ctorSetsDefaultDurableFalse) {
  Binding binding;

  EXPECT_FALSE(binding.isDurable());
}

TEST(BindingTests, ctorSetsDurableFalse) {
  Binding binding;

  EXPECT_FALSE(binding.isDurable());
}

TEST(BindingTests, testSetDurableFalse) {
  Binding binding;
  binding.setDurable(true);
  binding.setDurable(false);

  EXPECT_FALSE(binding.isDurable());
}

TEST(BindingTests, testSetDurableTrue) {
  Binding binding;
  binding.setDurable(true);

  EXPECT_TRUE(binding.isDurable());
}