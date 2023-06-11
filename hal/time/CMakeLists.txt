add_library(pivro_time_hal INTERFACE)

target_include_directories(
    pivro_time_hal INTERFACE include
)

add_subdirectory(linux)
add_subdirectory(pico)