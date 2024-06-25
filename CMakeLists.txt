cmake_minimum_required(VERSION 3.19)
project( HardenedShell CXX )

set( PROJECT_NAME HardenedShell )

# set compiler settings
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++ )
set( CMAKE_CXX_FLAGS "-Wl,--pic-executable,-e,main -Wl,-Bstatic -s -w -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libg++ -Wl,-Bstatic " )

# adding demon sources
include_directories( include )

# preprocessor flags
add_compile_definitions( DEBUG )

# linking library
link_libraries( netapi32 ws2_32 wsock32 wtsapi32 iphlpapi mscoree mscorlib )

# add compiled demons
add_executable( HardenedShell src/main.cpp )
