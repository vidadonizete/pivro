add_library(
    hardware_pico
    sleep.c
)

target_link_libraries(
    hardware_pico
    hardware
    pico_stdlib
)