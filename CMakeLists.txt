cmake_minimum_required(VERSION 3.10)
project(PatchworkGenerator)

set(CMAKE_CXX_STANDARD 17)

# Trouve Qt5 Widgets
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# UI
set(UI_FILES mainwindow.ui)
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# Sources
set(SOURCES
    main.cpp
    mainwindow.cpp
    ${UI_HEADERS}
)

# Création de l’exécutable
add_executable(patchwork-generator ${SOURCES})

# Lien avec Qt5
target_link_libraries(patchwork-generator Qt5::Widgets)
