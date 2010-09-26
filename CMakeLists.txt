CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

PROJECT (statechart)

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(
		FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

IF (CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS (
		"-pedantic-errors -Wall -Wextra -Wconversion"
		"-Wfloat-equal -Wredundant-decls -Wstrict-null-sentinel -Winit-self"
		"-Woverloaded-virtual -Wnon-virtual-dtor"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
		"-Wno-long-long"
	)
ELSEIF (MSVC)
	ADD_DEFINITIONS ("/W4 /wd4996 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")
	#4996 - unsafe standard C++ functions
ENDIF ()

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/include)

SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

SET (Boost_ADDITIONAL_VERSIONS "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0")

IF(MSVC)
	SET(Boost_USE_STATIC_LIBS ON)
ENDIF()

FIND_PACKAGE(
	Boost 1.40.0 REQUIRED COMPONENTS
)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR})

LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

ADD_SUBDIRECTORY (examples)

INSTALL (
	DIRECTORY include/
	DESTINATION include
)
