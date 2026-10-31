
cmake_minimum_required(VERSION 3.16)

project(VEX
    VERSION 1.0.0
    DESCRIPTION "VEX System Inspector - A developer oriented system diagnostic tool."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(vex
    src/main.cpp
    src/core/banner.cpp
    src/core/terminal.cpp
    src/system/system.cpp
    src/system/cpu.cpp
    src/system/memory.cpp
    src/system/storage.cpp
    src/system/network.cpp
    src/developer/developer.cpp
    src/diagnostics/diagnostics.cpp
    platform/windows/windows_info.cpp
)

target_include_directories(vex PRIVATE include)

if(WIN32)
    target_compile_definitions(vex PRIVATE VEX_WINDOWS)
    target_link_libraries(vex PRIVATE Advapi32)
    target_link_libraries(vex PRIVATE Advapi32 Iphlpapi)
endif()