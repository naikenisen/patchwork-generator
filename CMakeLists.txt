cmake_minimum_required(VERSION 3.10)
project(MonProjetQt)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(UI_FILES mainwindow.ui)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})

add_executable(monappli main.cpp ${UI_HEADERS})
target_link_libraries(monappli Qt5::Widgets)
