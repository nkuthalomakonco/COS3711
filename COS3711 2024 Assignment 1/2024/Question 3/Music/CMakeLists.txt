cmake_minimum_required(VERSION 3.14)

project(Music LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Music
  main.cpp
  cd.h cd.cpp
  window.h window.cpp
  progressbardelegate.h progressbardelegate.cpp
)
target_link_libraries(Music Qt${QT_VERSION_MAJOR}::Core Qt6::Widgets)
#target_link_libraries(Music PRIVATE Qt6::Widgets)

include(GNUInstallDirs)
install(TARGETS Music
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
