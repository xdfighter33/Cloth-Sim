cmake_minimum_required(VERSION 3.16)
project(Cloth LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Cloth src/main.cpp src/Application.cpp src/renderer.cpp src/physics/Physics.hpp src/point.cpp src/cloth.cpp src/stick.cpp)

target_link_libraries(Cloth PRIVATE sfml-graphics)

target_compile_features(Cloth PRIVATE cxx_std_17)


install(TARGETS Cloth)