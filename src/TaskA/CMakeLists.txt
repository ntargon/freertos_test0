
add_library(TaskA src/TaskA.c)
target_link_libraries(TaskA freertos_kernel freertos_config)
target_include_directories(TaskA PUBLIC include)