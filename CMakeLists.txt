cmake_minimum_required(VERSION 3.14)
project(Simulador)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.4
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG        1.0.1
        SOURCE_SUBDIR  nao-existe
)
FetchContent_MakeAvailable(glm)

add_executable(Simulador
        main.cpp
        libs/glad/src/glad.c
)

target_link_libraries(Simulador PRIVATE glfw)
target_include_directories(Simulador PRIVATE
        ${glm_SOURCE_DIR}
        libs/glad/include
)