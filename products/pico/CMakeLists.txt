add_executable(pivro_pico main.c)

target_link_libraries(
    pivro_pico 
    ili9341_pico
    pico_stdlib
)