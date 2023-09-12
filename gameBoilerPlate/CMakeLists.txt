cmake_minimum_required(VERSION 3.19)

project(FirstGame)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(./include)

file(GLOB DEFINITIONS_SOURCES ./src/definitions/*.cpp)

add_executable(firstGame ./src/main.cpp ${DEFINITIONS_SOURCES})

target_link_libraries(firstGame PRIVATE sfml-graphics sfml-window sfml-system)
