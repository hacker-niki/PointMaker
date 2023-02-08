cmake_minimum_required(VERSION 3.24)
project(PointMaker)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(PointMaker main.cpp)

add_library(Lib MainWindow.cpp Board.cpp Shapes/Shape.cpp Shapes/Square.cpp Shapes/Rectangular.cpp Shapes/Circle.cpp)


target_link_libraries(Lib
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )


target_link_libraries(PointMaker
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Lib
        )

