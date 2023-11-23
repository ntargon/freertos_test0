cmake_minimum_required(VERSION 3.20)
project(freertos_test0)


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
  GIT_TAG        main #Note: Best practice to use specific git-hash or tagged version
  GIT_PROGRESS TRUE
  GIT_SHALLOW 1
)

set( FREERTOS_HEAP "4" CACHE STRING "" FORCE)
set( FREERTOS_PORT "GCC_POSIX" CACHE STRING "" FORCE)
FetchContent_MakeAvailable(freertos_kernel)
# target_include_directories(freertos_kernel PUBLIC include)
# add_dependencies(freertos_kernel freertos_config)

add_executable(freertos_test0 src/main.cpp)
# add_dependencies(freertos_test0 freertos_kernel freertos_config)
target_link_libraries(freertos_test0 freertos_kernel freertos_config)
# target_include_directories(freertos_test0 PUBLIC ${freertos_kernel_SOURCE_DIR}/include)
# FetchContent_GetProperties(freertos_kernel)
# message("a: ${freertos_kernel_SOURCE_DIR}")
