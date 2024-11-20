cmake_minimum_required(VERSION 3.5)

project(algorithm)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT DEFINED CMAKE_C_STANDARD)
    message("Set CMAKE_C_STANDARD as 11")
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_STANDARD_REQUIRED ON)
endif()

if(NOT DEFINED CMAKE_CXX_STANDARD)
    message("Set CMAKE_C_STANDARD as 20")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
    message(STATUS "CMAKE_BUILD_TYPE is not set. Defaulting to Debug.")
endif()

include_directories(${PROJECT_SOURCE_DIR})

add_compile_options(-Wall -Wextra)

add_subdirectory(String)
