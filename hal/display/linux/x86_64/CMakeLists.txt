add_library(
    linux_x86_64_pivro_display_hal
    linux_x86_64_pivro_display_hal.c
)

find_package(SDL2 REQUIRED)

target_link_libraries(
    linux_x86_64_pivro_display_hal
    ${SDL2_LIBRARIES}
    pivro_display_hal
)