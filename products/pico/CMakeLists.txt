add_executable(
    pivro_pico
    ${PIVRO_MAIN}
)

target_link_libraries(
    pivro_pico
    pico_stdlib
)

target_link_libraries(
    pivro_pico

    pivro_display_hal
    pico_ili9341_pivro_display_hal

    pivro_time_hal
    pico_pivro_time_hal
)