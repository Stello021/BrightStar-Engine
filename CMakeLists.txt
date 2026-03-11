cmake_minimum_required(VERSION 3.28)
project(brightstar_engine_application VERSION 0.0.1 LANGUAGES CXX)

# CMake will search Qt6 into the variable CMAKE_PREFIX_PATH
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Enable automatic preprocessing of Qt's MOC, UIC, and RCC files
#	Qt use a meta-objects system (MOC) to provide features like signals and slots,
#   in this way, CMake can automatically handle the generation of these files.
#   AUTOUIC and AUTORCC are used to handle .ui and .qrc files respectively.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(external/engine)

#Executable for the application
add_executable(${PROJECT_NAME}
src/main.cpp
src/MainWindow.cpp
include/MainWindow.h # Needs to be included for AUTOMOC. In this way,
                     # CMake can pass the header file to the MOC preprocessor to generate the necessary  code for Q_OBJECT macro.
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_include_directories(${PROJECT_NAME}
PRIVATE #this path is used only to compile the application, noone else can "consume"
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
PRIVATE
	brightstar_engine
	Qt6::Widgets)