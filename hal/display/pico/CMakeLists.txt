add_library(
    pico_ili9341_pivro_display_hal
    pico_ili9341_pivro_display_hal.c
)

target_link_libraries(
    pico_ili9341_pivro_display_hal
    pico_ili9341
    pivro_display_hal
)