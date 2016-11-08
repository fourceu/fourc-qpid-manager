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
SET (APPLICATION_COPYRIGHT_YEARS "2016")
SET (APPLICATION_VERSION_STRING "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")
SET (APPLICATION_VENDOR_ID "eu.fourc")
SET (APPLICATION_VENDOR_NAME "FourC AS")
SET (APPLICATION_VENDOR_URL "fourc.eu")
SET (APPLICATION_ID "${APPLICATION_VENDOR_ID}.${PROJECT_NAME}")

option(BUILD_UNIT_TESTS "Include unit tests" ON)
option(BUILD_SYSTEM_TESTS "Include system tests" OFF)
option(BUILD_DOCUMENTATION "Generate the project documentation" OFF)
option(BUILD_COVERAGE "Build with code coverage instrumentation and additional coverage target" OFF)
set(BUILD_BASHTEST_FILTER "" CACHE STRING "Filter bash test test names to be executed (regex)")
set(BUILD_GTEST_FILTER "" CACHE STRING "Filter GTest test names to be executed (glob expr)")

LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

IF (UNIX)
    set(CMAKE_CXX_FLAGS "-Wextra -Wall -Werror -Winit-self -Wold-style-cast -Woverloaded-virtual -Wuninitialized -Wmissing-declarations -ansi -pedantic -std=c++11 -DBOOST_LOG_DYN_LINK")
    if (BUILD_COVERAGE)
        STRING(TOUPPER ${CMAKE_BUILD_TYPE} U_BUILD_TYPE)
        if (U_BUILD_TYPE STREQUAL DEBUG)
            MESSAGE(STATUS "Building with code coverage instrumentation")
        else ()
            MESSAGE(FATAL_ERROR "Coverage requires DEBUG build type (currently ${CMAKE_BUILD_TYPE})")
        endif ()

        include(CodeCoverage)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(BUILD_UNIT_TESTS TRUE)
    endif (BUILD_COVERAGE)
ENDIF (UNIX)

# We need Boost >=1.54, when the logging library was introduced.
FIND_PACKAGE(Boost 1.54 COMPONENTS log REQUIRED)
FIND_PACKAGE(Qpid REQUIRED)

INCLUDE_DIRECTORIES(include ${PROJECT_BINARY_DIR} ${${APPLICATION_NAME}_INCLUDE_DIRS} SYSTEM ${Boost_INCLUDE_DIRS} ${Qpid_INCLUDE_DIRS})

SET(${PROJECT_NAME}_LIBS ${Boost_LIBRARIES} ${Qpid_LIBRARIES})

SET(${PROJECT_NAME}_SRCS
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

ADD_LIBRARY(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${${PROJECT_NAME}_LIBS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES
	VERSION "${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}"
	OUTPUT_NAME ${PROJECT_NAME}
	CLEAN_DIRECT_OUTPUT 1)
INSTALL(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    )
INSTALL(DIRECTORY include/fourc DESTINATION include)

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
set(INSTALL_CMAKE_DIR lib/cmake/${PROJECT_NAME} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# Add all targets to the build-tree export set
export(TARGETS ${PROJECT_NAME} FILE "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}Targets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE ${PROJECT_NAME})

# Create the MessengerConfig.cmake and MessengerConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}")
configure_file(cmake/ProjectConfig.cmake.in "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}Config.cmake" @ONLY)

# ... for the install tree
set(CONF_INCLUDE_DIRS "\${${APPLICATION_NAME}_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(cmake/ProjectConfig.cmake.in "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${APPLICATION_NAME}Config.cmake" @ONLY)

# ... for both
configure_file(cmake/ProjectConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}ConfigVersion.cmake" @ONLY)

# Install the <Project>Config.cmake and <Project>ConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${APPLICATION_NAME}Config.cmake"
  "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}ConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT ${PROJECT_NAME}Targets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

if (BUILD_DOCUMENTATION)
    ADD_SUBDIRECTORY(doc)
endif ()
ADD_SUBDIRECTORY(tests)
