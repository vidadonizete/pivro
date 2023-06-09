add_library(pico_ili9341_hal pico_ili9341_hal.c)

target_link_libraries(
    pico_ili9341_hal
    ili9341_hal
    pico_stdlib
    hardware_spi
)

add_library(pico_ili9341)

target_link_libraries(
    pico_ili9341
    ili9341
    pico_ili9341_hal
    hardware_pico
)