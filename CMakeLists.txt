cmake_minimum_required(VERSION 3.19)
project(DataSortVisualP)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(DataSortVisualP main.cpp classes/button.cpp classes/button.h classes/textObj.cpp classes/textObj.h classes/SliderObj.cpp classes/SliderObj.h sorting_algorithms/bubble_sort.cpp sorting_algorithms/bubble_sort.h globals/globals.cpp globals/globals.h)
target_link_libraries(DataSortVisualP sfml-system sfml-window sfml-graphics -static)