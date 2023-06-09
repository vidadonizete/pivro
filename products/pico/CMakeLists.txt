add_executable(pivro_pico main.c)

target_link_libraries(
    pivro_pico
    pico_stdlib
)

target_link_libraries(
    pivro_pico

    pico_ili9341_pivro_display_hal
    pivro_display_hal
)