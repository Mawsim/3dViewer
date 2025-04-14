cmake_minimum_required(VERSION 3.5)

project(3DViewer_v1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

find_package(Qt6 REQUIRED COMPONENTS Core OpenGL Gui Widgets OpenGLWidgets)

set(SOURCES
        gui/main.cc
        gui/mainwindow.cc
        gui/mainwindow.h
        gui/mainwindow.ui
        gui/ui_mainwindow.h
        gui/mywidget.cc
        gui/mywidget.h
        code/parser.c
        code/parser.h
        code/affine.c
        code/affine.h
)

add_executable(${PROJECT_NAME} ${SOURCES})
#add_executable(${PROJECT_NAME} ${SOURCES} ${UI_HEADERS})

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::OpenGL Qt6::Gui Qt6::Widgets Qt6::OpenGLWidgets)

#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/gui)
