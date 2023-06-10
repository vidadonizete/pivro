add_library(
    pico_ili9341_hal_display 
    pico_ili9341_hal_display.c
)

target_link_libraries(
    pico_ili9341_hal_display
    ili9341_hal
    pico_stdlib
    hardware_spi
)

add_library(
    pico_ili9341_hal_sleep 
    pico_ili9341_hal_sleep.c
)

target_link_libraries(
    pico_ili9341_hal_sleep
    ili9341_hal
    pico_stdlib
)

add_library(pico_ili9341)

target_link_libraries(
    pico_ili9341
    ili9341
    pico_ili9341_hal_display
    pico_ili9341_hal_sleep
)