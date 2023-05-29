cmake_minimum_required(VERSION 3.12)

project("ili9341" LANGUAGES C CXX ASM)

subdirs(
    hal/pico
)

add_library(ili9341 ili9341.c)

target_include_directories(ili9341 PUBLIC include)
