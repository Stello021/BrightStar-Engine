cmake_minimum_required(VERSION 3.28)
project(brightstar_engine VERSION 0.0.1 LANGUAGES CXX)

add_library(${PROJECT_NAME} src/engine.cpp)

# Apply C++20 standard only to the target, using PUBLIC standard is propagated to consumers of the library
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${PROJECT_NAME})