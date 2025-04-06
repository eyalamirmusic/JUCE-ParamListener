cmake_minimum_required(VERSION 3.16)

project(JUCE-ParamListener)

if (PROJECT_IS_TOP_LEVEL)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
    set(CMAKE_OSX_DEPLOYMENT_TARGET 11.0 CACHE STRING "Minimum OS X deployment version" FORCE)
    option(UniversalBinary "Build universal binary for mac" OFF)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

    find_package(juce REQUIRED)

    set(CMAKE_CXX_STANDARD 20)
endif ()

add_subdirectory(Modules)

if (PROJECT_IS_TOP_LEVEL)
    add_subdirectory(Example)
endif ()