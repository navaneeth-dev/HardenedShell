cmake_minimum_required(VERSION 3.19)
project( HardenedShell CXX )

set( PROJECT_NAME HardenedShell )
set( CMAKE_EXPORT_COMPILE_COMMANDS on )

#target_include_directories( HardenedShell PUBLIC )

set( FILES
    src/main.cc
    src/sandbox.cc
    src/target.cc
)

# preprocessor flags
add_compile_definitions( DEBUG )

# add compiled demons
add_executable( HardenedShell ${FILES} )
