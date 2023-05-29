cmake_minimum_required(VERSION 3.12)

project("ili9341" LANGUAGES C CXX ASM)

add_library(ili9341 common/ili9341.c)

target_include_directories(
    ili9341 PUBLIC include/public
    #TODO(learn it later)
    ili9341 PUBLIC include/private
)

add_subdirectory(hal)

target_link_libraries(
    ili9341
    ili9341_hal
)