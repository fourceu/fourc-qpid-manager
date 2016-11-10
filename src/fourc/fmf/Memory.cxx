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

#include <fourc/fmf/Memory.h>

namespace fourc {
namespace fmf {

const std::string Memory::OBJECT_TYPE_NAME = "memory";

Memory::Memory() :
    malloc_arena(0),
    malloc_fordblks(0),
    malloc_hblkhd(0),
    malloc_hblks(0),
    malloc_keepcost(0),
    malloc_ordblks(0),
    malloc_uordblks(0) {}

uint64_t Memory::getMallocArena() const {
  return malloc_arena;
}

Memory& Memory::setMallocArena(uint64_t value) {
  malloc_arena = value;
  
  return *this;
}

uint64_t Memory::getMallocFordblks() const {
  return malloc_fordblks;
}

Memory& Memory::setMallocFordblks(uint64_t value) {
  malloc_fordblks = value;

  return *this;
}

uint64_t Memory::getMallocHblkhd() const {
  return malloc_hblkhd;
}

Memory& Memory::setMallocHblkhd(uint64_t value) {
  malloc_hblkhd = value;

  return *this;
}

uint64_t Memory::getMallocHblks() const {
  return malloc_hblks;
}

Memory& Memory::setMallocHblks(uint64_t value) {
  malloc_hblks = value;

  return *this;
}

uint64_t Memory::getMallocKeepcost() const {
  return malloc_keepcost;
}

Memory& Memory::setMallocKeepcost(uint64_t value) {
  malloc_keepcost = value;

  return *this;
}

uint64_t Memory::getMallocOrdblks() const {
  return malloc_ordblks;
}

Memory& Memory::setMallocOrdblks(uint64_t value) {
  malloc_ordblks = value;

  return *this;
}

uint64_t Memory::getMallocUordblks() const {
  return malloc_uordblks;
}

Memory& Memory::setMallocUordblks(uint64_t value) {
  malloc_uordblks = value;

  return *this;
}

const std::string& Memory::getName() const {
  return name;
}

Memory& Memory::setName(const std::string& value) {
  name = value;

  return *this;
}

}} // Namespaces
