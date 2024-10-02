# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.27)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# IMPORTANT: HERE WE DEFINE THE VARIABLES TO BE USED THROUGHOUT THE CMAKE FILE
set(PROJECT_NAME    GameOfLife)
set(EXECUTABLE_NAME Simulation)
set(LIB_NAME        gameLib)

project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        ON)

if(CMAKE_SYSTEM_NAME MATCHES Windows)
    set(CMAKE_GENERATOR "Visual Studio 17 2022")
endif()

# CMAKE OPTIONS
option(USE_CONAN "Whether to use Conan" ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/ext")

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif()

# Use Conan-generated build info
if(USE_CONAN)
message(STATUS "Using Conan")
include("${CMAKE_CURRENT_SOURCE_DIR}/ext/conan_toolchain.cmake")
endif()

# Find OpenMP library
find_package(OpenMP)

# Include sub-projects.
add_subdirectory (src)
add_subdirectory (app)