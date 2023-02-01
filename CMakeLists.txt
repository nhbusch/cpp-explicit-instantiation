cmake_minimum_required(VERSION 3.12...3.23) # (VERSION 3.16...3.23)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(extemp CXX)

add_library(core SHARED src/array.cpp)
target_compile_features(core PRIVATE cxx_std_17)
# look up  modern cmake
# only for shared library support
target_include_directories(core PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# clang/msvc shared library support
include(GenerateExportHeader)
generate_export_header(core)

add_executable(extemp src/main.cpp)
target_compile_features(extemp PRIVATE cxx_std_17)

target_link_libraries(extemp
  PRIVATE
  core
)