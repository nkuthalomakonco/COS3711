cmake_minimum_required(VERSION 3.14)

project(ConferenceRegistration LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

find_package(Qt6 REQUIRED COMPONENTS Xml)

add_executable(ConferenceRegistration
  main.cpp
  mainwindow.h mainwindow.cpp
  person.h person.cpp
  registration.h registration.cpp
  studentregistration.h studentregistration.cpp
  guestsregistration.h guestsregistration.cpp
  registrationlist.h registrationlist.cpp
  tablemodel.h tablemodel.cpp
  registrationlistwriter.h registrationlistwriter.cpp
  filewriter.h filewriter.cpp

  filereader.h filereader.cpp
  registrationlistreader.h registrationlistreader.cpp
  registrationfactory.h registrationfactory.cpp
  resource.qrc

)
#target_link_libraries(ConferenceRegistration Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(ConferenceRegistration PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
target_link_libraries(ConferenceRegistration PRIVATE Qt6::Xml)

include(GNUInstallDirs)
install(TARGETS ConferenceRegistration
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
