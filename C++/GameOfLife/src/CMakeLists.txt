# CMakeList.txt : CMake project for GameOfLife, include source and define
# project specific logic here.
#

# if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET GameOfLife PROPERTY CXX_STANDARD 20)
# endif()

# TODO: Add tests and install targets if needed.
set(LIBRARY_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} ${CONAN_INCLUDE_DIRS})

find_package(nlohmann_json CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(opengl_system CONFIG REQUIRED)

set(LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/GameOfLife.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/engine/Cell.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/engine/Loop.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/engine/Orchestrator.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/rendering/Renderer.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/utils/"
)

set(LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/GameOfLife.h"
    #"${CMAKE_CURRENT_SOURCE_DIR}/engine/Cell.h"
    #"${CMAKE_CURRENT_SOURCE_DIR}/engine/Loop.h"
    # "${CMAKE_CURRENT_SOURCE_DIR}/engine/Orchestrator.h"
    #"${CMAKE_CURRENT_SOURCE_DIR}/rendering/Renderer.h"
    #"${CMAKE_CURRENT_SOURCE_DIR}/utils/"
)

add_library(${LIB_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCES})

target_include_directories(
    ${LIB_NAME} PUBLIC 
    ${LIBRARY_INCLUDES}
    # "${CMAKE_BINARY_DIR}/configured_files/include"
)

target_link_libraries(
    ${LIB_NAME}
    PUBLIC OpenMP::OpenMP_CXX opengl::opengl nlohmann_json::nlohmann_json GLEW::GLEW)

# if(CMAKE_HOST_SYSTEM MATCHES Windows)
#    target_compile_options(${LIB_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CUDA>: -Xcompiler -openmp -lgomp -gencode arch=compute_80,code=sm_80>)
# elseif(CMAKE_HOST_SYSTEM MATCHES Linux)
#    target_compile_options(${LIB_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CUDA>: -Xcompiler -fopenmp -lgomp -gencode arch=compute_80,code=sm_80>)
# endif()