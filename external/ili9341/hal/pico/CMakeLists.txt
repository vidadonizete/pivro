cmake_minimum_required(VERSION 3.12)

project("ili9341_pico" LANGUAGES C CXX ASM)

add_library(ili9341_pico pico.c)

target_link_libraries(ili9341_pico ili9341)