#
# Copyright (C) 2014-2018 FourC AS, http://www.fourc.eu/
# All rights reserved.
#

if (NOT CMAKE_CROSSCOMPILING)
  if (BUILD_UNIT_TESTS OR BUILD_SYSTEM_TESTS)
    enable_testing()
    add_subdirectory(googletest)
  endif ()
ENDIF (NOT CMAKE_CROSSCOMPILING)

if (BUILD_UNIT_TESTS)
  add_subdirectory(unittests)
endif ()

if (BUILD_SYSTEM_TESTS)
  add_subdirectory(systemtests)
endif ()
