# This file is part of fourc-qpid-manager.
#
# fourc-qpid-manager is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# fourc-qpid-manager is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser Public License for more details.
#
# You should have received a copy of the GNU Lesser Public License
# along with fourc-qpid-manager.  If not, see <http://www.gnu.org/licenses/>.

# This file configures Google Mocks as an external project to the fourc-qpid-manager build,
# iff testing is enabled.

include(ExternalProject)

# Add gmock
ExternalProject_Add(
        googlemock
        GIT_REPOSITORY https://github.com/google/googletest.git
        TIMEOUT 30
        INSTALL_COMMAND ""
)

ExternalProject_Get_Property(googlemock source_dir binary_dir)

SET(GMOCK_INCLUDE_DIRS "${source_dir}/googlemock/include" CACHE STRING "GMock include directory")
SET(GTEST_INCLUDE_DIRS "${source_dir}/googletest/include" CACHE STRING "GTest include directory")

SET(GTEST_BOTH_INCLUDE_DIRS ${GMOCK_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS} CACHE STRING "GTest and GMock include directories")

SET(GMOCK_LIBRARY "${binary_dir}/googlemock/libgmock.a" CACHE STRING "GMock library")