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

#include <iostream>

#include <fourc/fmf/BrokerAgent.h>

#include <qpid/messaging/Connection.h>
#include <qpid/messaging/Session.h>

/**
 * \brief This example shows how to display a list of bindings on the broker.
 */

template <typename BindingListT>
void printBindings(BindingListT& bindings) {
  std::cout << "Bindings:" << std::endl;
  for (auto binding : bindings) {
    // This could be prettier but it illustrates the point
    std::cout << "Exchange: '" << binding->getExchangeName() << "'; Queue: '" << binding->getQueueName() <<
              "'; Binding key: '" << binding->getBindingKey() << "'" << std::endl;
  }
  if (bindings.empty()) {
    std::cout << "<None>" << std::endl;
  }
}

int main(int argc, char** argv) {
  qpid::messaging::Connection connection(argc > 1 ? argv[1] : "localhost", "{protocol:amqp1.0}");

  try {
    connection.open();
    auto session = connection.createSession();
    fourc::fmf::BrokerAgent agent(session);

    auto bindings = agent.getBindings();

    printBindings(bindings);

  } catch(const std::exception& error) {
    std::cout << "ERROR: " << error.what() << std::endl;
    connection.close();
    return 1;
  }
  connection.close();
  return 0;
}
