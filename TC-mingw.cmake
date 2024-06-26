set(CMAKE_SYSTEM_NAME Windows)

# set compiler settings
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++ )
set( CMAKE_CXX_FLAGS "-Wl,--pic-executable,-e,main -Wl,-Bstatic -s -w -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libgcc -Wl,-Bstatic " )

# linking library
link_libraries( netapi32 ws2_32 wsock32 wtsapi32 iphlpapi )
