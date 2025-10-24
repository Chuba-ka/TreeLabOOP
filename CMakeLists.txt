cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка политики CMP0135 для FetchContent
cmake_policy(SET CMP0135 NEW)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Основная программа
add_executable(Figures
    main.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
)

# Настройка Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Тесты
add_executable(FiguresTests
    tests/test_figures.cpp
    src/Figure.cpp
    src/Triangle.cpp
    src/Hexagon.cpp
    src/Octagon.cpp
)

target_link_libraries(FiguresTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(FiguresTests)