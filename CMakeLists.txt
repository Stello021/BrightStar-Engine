cmake_minimum_required(VERSION 3.28)
project(brightstar_engine_application VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(external/engine)

#Executable for the application
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} brightstar_engine)