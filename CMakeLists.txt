cmake_minimum_required(VERSION 3.26)

set(PROJECTNAME "cvec")

project(${PROJECTNAME} VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(cvec source/cvec.c)
add_library(cvec::cvec ALIAS cvec)

target_include_directories(cvec PUBLIC source)

option(CVEC_BUILD_TESTS "Build test" ON)
if(CVEC_BUILD_TESTS)
    add_subdirectory(test)
endif()
