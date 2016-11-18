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

INSTALL(TARGETS ${PROJECT_NAME}
        EXPORT ${APPLICATION_NAME}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        )
INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/include/fourc DESTINATION include)

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
set(INSTALL_CMAKE_DIR lib/cmake/${APPLICATION_NAME} CACHE PATH "Installation directory for CMake files")

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
export(PACKAGE ${APPLICATION_NAME})

# Create the <Project>Config.cmake and <Project>ConfigVersion.cmake files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}")
configure_file(${CMAKE_SOURCE_DIR}/cmake/ProjectConfig.cmake.in "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}Config.cmake" @ONLY)

# ... for the install tree
set(CONF_INCLUDE_DIRS "\${${APP_NAME_UPPER}_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(${CMAKE_SOURCE_DIR}/cmake/ProjectConfig.cmake.in "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${APPLICATION_NAME}Config.cmake" @ONLY)

# ... for both
configure_file(${CMAKE_SOURCE_DIR}/cmake/ProjectConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}ConfigVersion.cmake" @ONLY)

# Install the <Project>Config.cmake and <Project>ConfigVersion.cmake
install(FILES
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/${APPLICATION_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${APPLICATION_NAME}ConfigVersion.cmake"
        DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT ${APPLICATION_NAME}Targets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
