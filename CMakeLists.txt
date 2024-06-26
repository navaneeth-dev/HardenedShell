cmake_minimum_required(VERSION 3.19)
project( HardenedShell CXX )

set( PROJECT_NAME HardenedShell )
set( CMAKE_EXPORT_COMPILE_COMMANDS on )

# adding demon sources
include_directories( include )

# preprocessor flags
add_compile_definitions( DEBUG )

# add compiled demons
add_executable( HardenedShell src/main.cpp )
