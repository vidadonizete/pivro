add_library(
    linux_x86_64_pivro_display_hal
    linux_x86_64_pivro_display_hal.c
)

target_link_libraries(
    linux_x86_64_pivro_display_hal
    pivro_display_hal
)