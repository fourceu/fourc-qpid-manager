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

project(unittests CXX)

# Set the target name policy to allow the reserved target name "test" to be used
if (POLICY CMP0037)
    message(STATUS "Setting target name policy to OLD (allowing use of reserved target names)")
    cmake_policy(SET CMP0037 OLD)
endif ()

include_directories(../../src ${CMAKE_CURRENT_SOURCE_DIR} ${GTEST_BOTH_INCLUDE_DIRS})

set(test_SRCS
        main.cxx
        fourc/fmf/codec/AclDecoderTests.cxx
        fourc/fmf/codec/BindingDecoderTests.cxx
        fourc/fmf/codec/BrokerDecoderTests.cxx
        fourc/fmf/codec/ConnectionDecoderTests.cxx
        fourc/fmf/codec/DecodeExceptionTests.cxx
        fourc/fmf/codec/DecoderTests.cxx
        fourc/fmf/codec/ExchangeDecoderTests.cxx
        fourc/fmf/codec/LinkDecoderTests.cxx
        fourc/fmf/codec/MemoryDecoderTests.cxx
        fourc/fmf/codec/QueueDecoderTests.cxx
        fourc/fmf/codec/ResponseDecoderTests.cxx
        fourc/fmf/codec/SessionDecoderTests.cxx
        fourc/fmf/codec/SubscriptionDecoderTests.cxx
        fourc/fmf/AclTests.cxx
        fourc/fmf/BrokerObjectTests.cxx
        fourc/fmf/BrokerTests.cxx
        fourc/fmf/BindingTests.cxx
        fourc/fmf/BrokerAgentExceptionTests.cxx
        fourc/fmf/BrokerAgentTests.cxx
        fourc/fmf/ClusterTests.cxx
        fourc/fmf/ConnectionTests.cxx
        fourc/fmf/ExchangeTests.cxx
        fourc/fmf/ExchangeTypeDescTests.cxx
        fourc/fmf/HaBrokerTests.cxx
        fourc/fmf/LinkTests.cxx
        fourc/fmf/MemoryTests.cxx
        fourc/fmf/ObjectIdTests.cxx
        fourc/fmf/QueueTests.cxx
        fourc/fmf/RPCExceptionTests.cxx
        fourc/fmf/SchemaIdTests.cxx
        fourc/fmf/SessionTests.cxx
        fourc/fmf/SubscriptionTests.cxx
)

ADD_EXECUTABLE(${PROJECT_NAME} ${test_SRCS})
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_PROJECT_NAME} ${CLI_LIBS} ${FOURCFRAMEWORK_LIBRARIES} ${Boost_LIBRARIES} ${GMOCK_LIBRARY} pthread)

if (BUILD_GTEST_FILTER)
    SET(GTEST_FILTER --gtest_filter=${BUILD_GTEST_FILTER}) 
endif ()

SET(UNIT_TEST_BINARY "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}${CMAKE_EXECUTABLE_SUFFIX}")

ADD_CUSTOM_TARGET(test "${UNIT_TEST_BINARY}" 
    --gtest_output=xml
    ${GTEST_FILTER}
    DEPENDS ${PROJECT_NAME}
    COMMENT "Executing unit tests..."
    VERBATIM SOURCES ${test_SRCS})

ADD_DEPENDENCIES(${PROJECT_NAME} googlemock)

if (BUILD_COVERAGE)
    SETUP_TARGET_FOR_COVERAGE(
	    coverage                        # Name for custom target.
        "${UNIT_TEST_BINARY}"           # Name of the test driver executable that runs the tests.
                                        # NOTE! This should always have a ZERO as exit code
                                        # otherwise the coverage generation will not complete.
        unit_test_coverage              # Name of output directory.
    )   
    SETUP_TARGET_FOR_COVERAGE_COBERTURA(
	    coverage_cobertura              # Name for custom target.
        "${UNIT_TEST_BINARY}"           # Name of the test driver executable that runs the tests.
                                        # NOTE! This should always have a ZERO as exit code
                                        # otherwise the coverage generation will not complete.
        unit_test_coverage_cobertura    # cobertura output is generated as _outputname.xml
    )
endif ()