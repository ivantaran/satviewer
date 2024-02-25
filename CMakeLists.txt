cmake_minimum_required(VERSION 3.1.0)

project(satviewer VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

set(CMAKE_AUTOUIC_SEARCH_PATHS "src/gui/ui")

file(GLOB SOURCES
    "src/*.cpp"
    "src/gui/*.cpp"
    "src/gui/SatViewer.qrc"
    "src/ogl/*.cpp"
    "src/ogl/globj/*.cpp"
    "src/ogl/glsprite/*.cpp"
    "src/models/sun/*.c"
    "src/models/sgp4/*.cpp"
)
add_executable(satviewer
    ${SOURCES}
)

target_link_libraries(satviewer Qt5::Widgets)
target_link_libraries(satviewer Qt5::Core)
target_link_libraries(satviewer Qt5::Network)
target_link_libraries(satviewer Qt5::Sql)
target_link_libraries(satviewer Qt5::Qml)
