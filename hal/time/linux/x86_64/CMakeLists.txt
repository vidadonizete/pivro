add_library(
    linux_x86_64_pivro_time_hal
    linux_x86_64_pivro_time_hal.c
)

target_link_libraries(
    linux_x86_64_pivro_time_hal
    pivro_time_hal
)