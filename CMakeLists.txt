cmake_minimum_required(VERSION 3.1.0)

project(satviewer VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS "gui/ui")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Sql REQUIRED)
find_package(Qt5 COMPONENTS Qml REQUIRED)

file(GLOB SOURCES
    "gui/*.cpp"
    "utils/*.cpp"
    "utils/ogl/*.cpp"
    "utils/ogl/globj/*.cpp"
    "utils/ogl/glsprite/*.cpp"
    "utils/models/sun/*.c"
    "utils/models/sgp4/*.cpp"
)
add_executable(satviewer
    main.cpp
    ${SOURCES}
    SatViewer.cpp
    gui/SatViewer.qrc
)

target_link_libraries(satviewer Qt5::Widgets)
target_link_libraries(satviewer Qt5::Core)
target_link_libraries(satviewer Qt5::Network)
target_link_libraries(satviewer Qt5::Sql)
target_link_libraries(satviewer Qt5::Qml)
