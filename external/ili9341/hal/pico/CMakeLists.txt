add_library(ili9341_hal pico.c)

target_link_libraries(
    ili9341_hal
    ili9341
    pico_stdlib
    hardware_spi
)