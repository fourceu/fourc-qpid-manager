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

CMAKE_MINIMUM_REQUIRED (VERSION 2.8.7)

PROJECT (fourc-qpid-manager CXX)

include (version.cmake)
SET (APPLICATION_NAME "FourcQpidManager")
SET (APPLICATION_CODENAME "${PROJECT_NAME}")
SET (APPLICATION_COPYRIGHT_YEARS "2017")
SET (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")
SET (APPLICATION_VENDOR_ID "eu.fourc")
SET (APPLICATION_VENDOR_NAME "FourC AS")
SET (APPLICATION_VENDOR_URL "fourc.eu")
SET (APPLICATION_ID "${APPLICATION_VENDOR_ID}.${PROJECT_NAME}")

# Get an upper case version of the application name (for use in build variables)
string(TOUPPER ${APPLICATION_NAME} APP_NAME_UPPER)

option(BUILD_EXAMPLES "Build example programs" OFF)
option(BUILD_UNIT_TESTS "Include unit tests" ON)
option(BUILD_SYSTEM_TESTS "Include system tests" OFF)
option(BUILD_DOCUMENTATION "Generate the project documentation" OFF)
option(BUILD_COVERAGE "Build with code coverage instrumentation and additional coverage target" OFF)
option(BUILD_QA_COMPILER_FLAGS "Build with strict compiler options" ON)
set(BUILD_BASHTEST_FILTER "" CACHE STRING "Filter bash test test names to be executed (regex)")
set(BUILD_GTEST_FILTER "" CACHE STRING "Filter GTest test names to be executed (glob expr)")

LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

IF (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Wextra -Winit-self -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -Wold-style-cast -DBOOST_ALL_DYN_LINK")
    if (CMAKE_COMPILER_IS_GNUCC AND BUILD_QA_COMPILER_FLAGS)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
    endif()
    if (BUILD_COVERAGE)
        STRING(TOUPPER "${CMAKE_BUILD_TYPE}" U_BUILD_TYPE)
        if (U_BUILD_TYPE STREQUAL DEBUG)
            MESSAGE(STATUS "Building with code coverage instrumentation")
        else ()
            MESSAGE(STATUS "Coverage requires DEBUG build type (currently '${CMAKE_BUILD_TYPE}'). Updating to DEBUG")
            SET(CMAKE_BUILD_TYPE Debug)
        endif ()

        FIND_PACKAGE(PythonInterp)
        INCLUDE(CodeCoverage)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(BUILD_UNIT_TESTS TRUE)
    endif (BUILD_COVERAGE)
ENDIF (UNIX)

# We need Boost >=1.54, when the logging library was introduced.
FIND_PACKAGE(Boost 1.54 COMPONENTS log REQUIRED)
FIND_PACKAGE(Qpid REQUIRED)

INCLUDE_DIRECTORIES(include ${PROJECT_BINARY_DIR} SYSTEM ${Boost_INCLUDE_DIRS} ${Qpid_INCLUDE_DIRS})

SET(${APP_NAME_UPPER}_LIBS ${Boost_LIBRARIES} ${Qpid_LIBRARIES})

SET(${APP_NAME_UPPER}_SRCS
        src/fourc/fmf/codec/DecodeException.cxx
        src/fourc/fmf/codec/ResponsePropertyNames.cxx
        src/fourc/fmf/Acl.cxx
        src/fourc/fmf/Broker.cxx
        src/fourc/fmf/Binding.cxx
        src/fourc/fmf/BrokerAgentException.cxx
        src/fourc/fmf/BrokerObject.cxx
        src/fourc/fmf/Cluster.cxx
        src/fourc/fmf/Connection.cxx
        src/fourc/fmf/Exchange.cxx
        src/fourc/fmf/ExchangeTypeDesc.cxx
        src/fourc/fmf/HaBroker.cxx
        src/fourc/fmf/Link.cxx
        src/fourc/fmf/Memory.cxx
        src/fourc/fmf/ObjectId.cxx
        src/fourc/fmf/Queue.cxx
        src/fourc/fmf/RPCException.cxx
        src/fourc/fmf/SchemaId.cxx
        src/fourc/fmf/Session.cxx
        src/fourc/fmf/Subscription.cxx
)

ADD_LIBRARY(${PROJECT_NAME} SHARED ${${APP_NAME_UPPER}_SRCS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${${APP_NAME_UPPER}_LIBS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES
	VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}"
	OUTPUT_NAME ${PROJECT_NAME}
	CLEAN_DIRECT_OUTPUT 1)

include(cmake/install_targets.cmake)

if (BUILD_DOCUMENTATION)
    ADD_SUBDIRECTORY(doc)
endif ()
if (BUILD_EXAMPLES)
    ADD_SUBDIRECTORY(examples)
endif()
ADD_SUBDIRECTORY(tests)
