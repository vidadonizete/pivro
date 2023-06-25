${setup_project}
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
${setup_specific_sdk}
pico_sdk_init()
