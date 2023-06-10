${setup_project}
include(cmake/pico/pico_sdk_import.cmake)
include(cmake/pico/pico_extras_import_optional.cmake)
${setup_specific_sdk}
pico_sdk_init()
