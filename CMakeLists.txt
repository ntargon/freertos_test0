cmake_minimum_required(VERSION 3.20)
project(freertos_test0)

# FreeRTOS

add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM
INTERFACE
    include
)

target_compile_definitions(freertos_config
  INTERFACE
    projCOVERAGE_TEST=0
)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare( freertos_kernel
  GIT_REPOSITORY https://github.com/FreeRTOS/FreeRTOS-Kernel.git
  GIT_TAG        V10.6.1 #Note: Best practice to use specific git-hash or tagged version
  GIT_PROGRESS TRUE
  GIT_SHALLOW 1
)

set( FREERTOS_HEAP "4" CACHE STRING "" FORCE)
set( FREERTOS_PORT "GCC_POSIX" CACHE STRING "" FORCE)
FetchContent_MakeAvailable(freertos_kernel)

# Application

add_subdirectory(src/TaskA)
add_subdirectory(src/TaskB)

add_library(ApplicationEntry src/ApplicationEntry.c)
target_link_libraries(ApplicationEntry PUBLIC TaskA TaskB)

add_executable(freertos_test0 src/main.c)
target_link_libraries(freertos_test0
                      ApplicationEntry)
                      # TaskA TaskB)
