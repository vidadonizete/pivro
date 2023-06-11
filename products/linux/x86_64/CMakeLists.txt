add_executable(
    pivro_linux_86_64 
    ${PIVRO_MAIN}
)

target_link_libraries(
    pivro_linux_86_64
    m #math.h
)

target_link_libraries(
    pivro_linux_86_64

    pivro_display_hal
    linux_x86_64_pivro_display_hal
    
    pivro_time_hal
    linux_x86_64_pivro_time_hal
)