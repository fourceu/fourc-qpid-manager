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

find_package(Doxygen)
if(DOXYGEN_FOUND)
	set(DOXYGEN_PROJECT_TITLE ${CMAKE_PROJECT_NAME})
	set(DOXYGEN_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/mainpage.doc ${CMAKE_CURRENT_SOURCE_DIR}/../include/fourc	${CMAKE_CURRENT_SOURCE_DIR}/../src/fourc")
	
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
