set(CMAKE_SYSTEM_NAME Windows)

# set compiler settings
set( CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++ )
set( CMAKE_CXX_FLAGS "-municode -fno-exceptions -static-libgcc -static" )
