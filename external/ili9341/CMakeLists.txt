cmake_minimum_required(VERSION 3.12)

project("ili9341" LANGUAGES C CXX ASM)

add_library(ili9341 ili9341.c)

target_include_directories(
    ili9341 PRIVATE include/private
    ili9341 PUBLIC include/public
)

add_library(ili9341_hal INTERFACE)

target_include_directories(
    ili9341_hal INTERFACE include/public
    ili9341_hal INTERFACE include/private
)

add_subdirectory(hal)
add_subdirectory(examples)