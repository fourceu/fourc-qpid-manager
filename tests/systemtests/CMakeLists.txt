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

project(systemtests CXX)

include_directories(../../src "${CMAKE_CURRENT_SOURCE_DIR}" "${GTEST_BOTH_INCLUDE_DIRS}")

SET(test_SRCS
        main.cxx
        SystemTestConfiguration.cxx
        tests/AclTestsIT.cxx
        tests/BindingTestsIT.cxx
        tests/BrokerAgentTests.cxx
        tests/BrokerTestsIT.cxx
        tests/ClusterTestsIT.cxx
        tests/ConnectionTestsIT.cxx
        tests/ExchangeTestsIT.cxx
        tests/HaBrokerTestsIT.cxx
        tests/LinkTestsIT.cxx
        tests/MemoryTestsIT.cxx
        tests/QueueTestsIT.cxx
        tests/SessionTestsIT.cxx
        tests/SubscriptionTestsIT.cxx
)

ADD_EXECUTABLE(${PROJECT_NAME} ${test_SRCS})
ADD_DEPENDENCIES(${PROJECT_NAME} googlemock)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_PROJECT_NAME} ${GMOCK_LIBRARY} pthread)

if (BUILD_GTEST_FILTER)
    SET(GTEST_FILTER --gtest_filter=${BUILD_GTEST_FILTER})
endif ()

# Test parameters
set(QPID_BROKER_HOST $ENV{QPID_BROKER_HOST})
set(QPID_BROKER_PORT $ENV{QPID_BROKER_PORT})
set(ENV_BROKER_CONNECTION_OPTIONS $ENV{ENV_BROKER_CONNECTION_OPTIONS})

message(STATUS "Configured C++ system test parameters:")
message(STATUS "QPID_BROKER_HOST    : ${QPID_BROKER_HOST}")
message(STATUS "QPID_BROKER_PORT    : ${QPID_BROKER_PORT}")
message(STATUS "ENV_BROKER_CONNECTION_OPTIONS : ${ENV_BROKER_CONNECTION_OPTIONS}")

# Scripted tests
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/scripts/bash-system-tests "${CMAKE_CURRENT_BINARY_DIR}/scripts/bash-system-tests" @ONLY)

SET(ENV(BUILD_BASHTEST_FILTER) ${BUILD_BASHTEST_FILTER})

ADD_CUSTOM_TARGET(cxxsystemtest "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}" "--gtest_output=xml" ${GTEST_FILTER}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Executing cxx system tests..."
    VERBATIM SOURCES ${test_SRCS})
ADD_DEPENDENCIES(${PROJECT_NAME} googlemock)

ADD_CUSTOM_TARGET(bashsystemtest COMMAND ${CMAKE_CURRENT_BINARY_DIR}/scripts/bash-system-tests
	DEPENDS ${PROJECT_NAME} 
    COMMENT "Executing bash system tests...")

ADD_CUSTOM_TARGET(systemtest
	DEPENDS cxxsystemtest bashsystemtest
	COMMENT "Executing system tests...")
