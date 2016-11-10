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

#ifndef FOURC_FMF_MEMORY_H
#define FOURC_FMF_MEMORY_H

#include "BrokerObject.h"

namespace fourc {
namespace fmf {

class Memory : public BrokerObject {
public:
  static const std::string OBJECT_TYPE_NAME;

  Memory();

  uint64_t getMallocArena() const;
  Memory& setMallocArena(uint64_t);

  uint64_t getMallocFordblks() const;
  Memory& setMallocFordblks(uint64_t);

  uint64_t getMallocHblkhd() const;
  Memory& setMallocHblkhd(uint64_t);

  uint64_t getMallocHblks() const;
  Memory& setMallocHblks(uint64_t);

  uint64_t getMallocKeepcost() const;
  Memory& setMallocKeepcost(uint64_t);

  uint64_t getMallocOrdblks() const;
  Memory& setMallocOrdblks(uint64_t);

  uint64_t getMallocUordblks() const;
  Memory& setMallocUordblks(uint64_t);

  const std::string& getName() const;
  Memory& setName(const std::string& );

private:
  uint64_t malloc_arena;
  uint64_t malloc_fordblks;
  uint64_t malloc_hblkhd;
  uint64_t malloc_hblks;
  uint64_t malloc_keepcost;
  uint64_t malloc_ordblks;
  uint64_t malloc_uordblks;
  std::string name;
};

}} // Namespaces

#endif //FOURC_FMF_MEMORY_H
