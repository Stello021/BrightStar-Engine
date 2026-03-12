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

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_SOURCE_DIR}/ui
    ${CMAKE_SOURCE_DIR}/ui/GameProject) # This is the path where CMake will look for .ui files

add_subdirectory(external/engine)

# Grouping sorces by subsystem

set(EDITOR_SOURCES
    src/main.cpp
    src/MainWindow.cpp
)

set(EDITOR_HEADERS
    include/MainWindow.h
)

set(GAMEPROJECT_SOURCES
    src/GameProject/QProjectBrowserDialog.cpp
)

set(GAMEPROJECT_HEADERS
    include/GameProject/QProjectBrowserDialog.h
)

set(GAMEPROJECT_UI
    ui/GameProject/QProjectBrowserDialog.ui
)

source_group(TREE ${CMAKE_SOURCE_DIR}/src    PREFIX "Source Files" FILES ${EDITOR_SOURCES} ${GAMEPROJECT_SOURCES})
source_group(TREE ${CMAKE_SOURCE_DIR}/include PREFIX "Header Files" FILES ${EDITOR_HEADERS} ${GAMEPROJECT_HEADERS})
source_group(TREE ${CMAKE_SOURCE_DIR}/ui      PREFIX "UI Files"     FILES ${GAMEPROJECT_UI})

#Executable for the application
add_executable(${PROJECT_NAME}
    ${EDITOR_SOURCES}
    ${EDITOR_HEADERS}
    ${GAMEPROJECT_SOURCES}
    ${GAMEPROJECT_HEADERS}
    ${GAMEPROJECT_UI}
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