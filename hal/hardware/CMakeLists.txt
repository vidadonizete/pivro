cmake_minimum_required(VERSION 3.12)

project("hardware" LANGUAGES C CXX ASM)

add_library(hardware INTERFACE)

target_include_directories(
    hardware INTERFACE include
)

add_subdirectory(pico)