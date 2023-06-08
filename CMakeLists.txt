cmake_minimum_required(VERSION 3.12)

include(cmake/pico_sdk_import.cmake)
include(cmake/pico_extras_import_optional.cmake)

project("Pivro" LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(external)
add_subdirectory(products)