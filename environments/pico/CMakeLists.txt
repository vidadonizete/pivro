${before_project}
include(cmake/pico/pico_sdk_import.cmake)
include(cmake/pico/pico_extras_import_optional.cmake)
${before_subdirectories}
pico_sdk_init()
