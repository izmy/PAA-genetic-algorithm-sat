cmake_minimum_required(VERSION 3.6)
project(genetika)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CChromozom.cpp CChromozom.h CGenerace.cpp CGenerace.h CKlauzule.cpp CKlauzule.h)

add_executable(genetika ${SOURCE_FILES})