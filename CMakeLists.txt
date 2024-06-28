cmake_minimum_required(VERSION 3.19)
project( HardenedShell CXX )

set( PROJECT_NAME HardenedShell )
set( CMAKE_EXPORT_COMPILE_COMMANDS on )

set( CMAKE_CXX_STANDARD 20 )

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_compile_definitions(_UNICODE=1 UNICODE=1)

set( FILES
    src/main.cc
    src/sandbox.cc
    src/target.cc
)

add_executable( HardenedShell ${FILES} )

target_link_libraries(HardenedShell wininet)
