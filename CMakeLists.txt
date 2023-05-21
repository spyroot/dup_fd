cmake_minimum_required(VERSION 2.9)
project(dup_finder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_SYSTEM_PROCESSOR "aarch64")

include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)
include(CheckIncludeFileCXX)
include(CheckIncludeFile)

set(OPENSSL_ROOT_DIR /opt/homebrew/opt/openssl/)

find_package(Boost  REQUIRED)
find_package(Boost  REQUIRED COMPONENTS filesystem)
find_package(OpenSSL REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

set(CODE_SIGN_IDENTITY "spyroot")

message(STATUS "BOOST_ROOT: ${BOOST_ROOT}")

if(Boost_FOUND AND OPENSSL_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set(SOURCE_FILES main.cpp file_comparer.cpp file_comparer.h)
    add_executable(dup_finder ${SOURCE_FILES})
    target_link_libraries(dup_finder ${Boost_LIBRARIES} OpenSSL::Crypto)

#    target_link_libraries(dup_finder
#            ${Boost_LIBRARIES}
#            "-static"
#            OpenSSL::Crypto
#            )

    message(STATUS "OpenSSL Found: ${OPENSSL_VERSION}")
    message(STATUS "OpenSSL Include: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OpenSSL Libraries: ${OPENSSL_LIBRARIES}")
endif()

