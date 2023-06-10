add_executable(pivro_linux_86_64 main.c)

target_link_libraries(
    pivro_linux_86_64
    linux_x86_64_pivro_display_hal
    pivro_display_hal
)