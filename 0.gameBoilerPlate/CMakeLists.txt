cmake_minimum_required(VERSION 3.19)

project(GameName)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(./include)

file(GLOB DEFINITIONS_SOURCES ./src/definitions/*.cpp)

add_custom_target(run
    COMMAND ./${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)


add_executable(${PROJECT_NAME} ./src/main.cpp ${DEFINITIONS_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
