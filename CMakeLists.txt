cmake_minimum_required(VERSION 3.24)
project(engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_executable(engine src/main.cpp )

target_include_directories(engine PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/myLibs")

target_link_libraries(engine PRIVATE Vulkan::Vulkan glfw glm::glm)

if (MSVC)
  target_compile_options(engine PRIVATE /W4 /permissive-)
endif()
