cmake_minimum_required(VERSION 3.16)
project(ScreenDraw LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

add_executable(ScreenDraw
    main.cpp
    MainWindow.h
    MainWindow.cpp
    Toolbar.h
    Toolbar.cpp
)

target_link_libraries(ScreenDraw PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)
