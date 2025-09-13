cmake_minimum_required(VERSION 3.10)
project(PatchworkGenerator)

set(CMAKE_CXX_STANDARD 17)

# Active la génération automatique des fichiers UI
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Qt5 Widgets et PrintSupport
find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED)

# Sources

set(SOURCES
    main.cpp
    mainwindow.cpp
    patchworkview.cpp
    mainwindow.ui
)

# Création de l’exécutable

add_executable(patchwork-generator ${SOURCES} patchworkview.h mainwindow.ui)

# Lien avec Qt5 Widgets et PrintSupport
target_link_libraries(patchwork-generator Qt5::Widgets Qt5::PrintSupport)