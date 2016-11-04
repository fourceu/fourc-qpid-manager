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

#ifndef GETLOCALHOSTADDRESS_H_
#define GETLOCALHOSTADDRESS_H_

#include <stdexcept>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

class LocalHostAddress {
public:
  static std::string getLocalHostAddress() {
    struct addrinfo hints, *info, *p;
    int gai_result;

    char host[1024];
    host[1023] = '\0';
    gethostname(host, 1023);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; /*either IPV4 or IPV6*/
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if ((gai_result = getaddrinfo(host, "http", &hints, &info)) != 0) {
      freeaddrinfo(info);
      throw std::runtime_error(gai_strerror(gai_result));
    }

    std::string hostAddress;
    for(p = info; p != NULL; p = p->ai_next) {
      hostAddress = p->ai_canonname;
    }

    freeaddrinfo(info);

    return hostAddress;
  }
};
#endif /* GETLOCALHOSTADDRESS_H_ */
