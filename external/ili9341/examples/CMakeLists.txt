add_executable(
    circle_ili9341_example
    circle_ili9341_example.c
)

target_link_libraries(
    circle_ili9341_example
    pico_ili9341
)