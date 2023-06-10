add_library(pivro_display_hal INTERFACE)

target_include_directories(
    pivro_display_hal INTERFACE include
)

add_subdirectory(pico)
add_subdirectory(linux)