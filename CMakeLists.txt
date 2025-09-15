cmake_minimum_required(VERSION 3.5)
project(patchwork-generator)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5 REQUIRED COMPONENTS Widgets Gui PrintSupport)
set(CMAKE_AUTOMOC ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/patchworkview.cpp
)

set(HEADERS
    include/mainwindow.h
    include/patchworkview.h
)

add_executable(patchwork-generator ${SOURCES} ${HEADERS})

target_link_libraries(patchwork-generator Qt5::Widgets Qt5::Gui Qt5::PrintSupport)