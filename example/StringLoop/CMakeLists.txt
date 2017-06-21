#
# Copyright (c) 2016 Food Tiny Project. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
# Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

cmake_minimum_required(VERSION 2.8)
project(App C CXX)

# Force Linux and Darwin use GCC
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# Check C++ compiler version
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-std=c++11" COMPILER_SUPPORTS_CXX11)
check_cxx_compiler_flag("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

set(SOURCE_FILES Main.cpp)
add_executable(App ${SOURCE_FILES})

if (COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif (COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else ()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif ()

add_definitions(-D_GNU_SOURCE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wimplicit-function-declaration")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wformat-extra-args")

# Detect platform and include path for OpenSSL
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(OPENSSL_ROOT_DIR "/usr/include/openssl")
else ()
    set(OPENSSL_ROOT_DIR "C:/Program Files (x86)/GnuWin32/include")
endif ()

# Set root directory for OpenSSL
set(OPENSSL_ROOT_DIR "${OPENSSL_ROOT_DIR}")

# Detect installed components
find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

if (OPENSSL_FOUND)
    include_directories("${OPENSSL_INCLUDE_DIR}")
endif ()

# Dynamic linked library for OSX
set(DYLD_LIBRARY_PATH ${DYLD_LIBRARY_PATH})

# Link library for OSX and other platform
# Darwin platform no need to link realtime library (-lrt)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lnative -lcrypto -lm)
else ()
    target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} ${ZLIB_LIBRARIES} ${OPENSSL_LIBRARIES} -lnative -lcrypto -lm -lrt)
endif ()