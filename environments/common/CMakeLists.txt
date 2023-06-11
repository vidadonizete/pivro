cmake_minimum_required(VERSION 3.12)

${setup_project}

project("Pivro" LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PIVRO_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

${setup_specific_sdk}

add_subdirectory(hal)
add_subdirectory(external)
add_subdirectory(products)
