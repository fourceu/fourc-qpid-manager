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

IF (NOT CMAKE_CROSSCOMPILING)
	if (${BUILD_UNIT_TESTS} OR ${BUILD_SYSTEM_TESTS})
		enable_testing()
    	add_subdirectory(gmock)
	endif ()
ENDIF ()

if (${BUILD_UNIT_TESTS})
    add_subdirectory(unittests)
endif ()

if (${BUILD_SYSTEM_TESTS})
    add_subdirectory(systemtests)
endif ()
