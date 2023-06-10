macro(ili9341_example NAME)
add_executable(
    ${NAME}_ili9341_example
    ${NAME}_ili9341_example.c
)

target_link_libraries(
    ${NAME}_ili9341_example
    pico_ili9341
)
endmacro()

ili9341_example(circle)
ili9341_example(squares)