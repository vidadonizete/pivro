add_library(ili9341_hal_pico pico.c)

target_link_libraries(
    ili9341_hal_pico
    ili9341_hal
    pico_stdlib
    hardware_spi
)

add_library(ili9341_pico)

target_link_libraries(ili9341_pico ili9341 ili9341_hal_pico)