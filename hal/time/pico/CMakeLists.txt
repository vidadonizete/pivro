add_library(
    pico_pivro_time_hal
    pico_pivro_time_hal.c
)

target_link_libraries(
    pico_pivro_time_hal
    pico_stdlib
    pivro_time_hal
)