
add_library(TaskB src/TaskB.c)
target_link_libraries(TaskB freertos_kernel freertos_config)
target_include_directories(TaskB PUBLIC include)