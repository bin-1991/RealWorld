
#INCLUDE(${QT_USE_FILE})
#ADD_DEFINITIONS(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)
#qt5_wrap_ui(ui_FILES mainwindow.ui)
#qt5_wrap_cpp()

source_group(ui REGULAR_EXPRESSION "\\.*\\.ui")
source_group(moc REGULAR_EXPRESSION "(mocs_.*)|(moc_.*)")

include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(ui_FILES mainwindow.ui)
#set(header_FILES mainwindow.h)
#qt5_wrap_ui(ui_FILES mainwindow.ui)
#qt5_wrap_cpp(moc_FILES ${header_FILES})
#qt5_add_resources(res_FILES realworld.qrc)

set(SRC  RealWorld.cpp)

add_executable(RealWorld WIN32 ${SRC} ${ui_FILES} )
qt5_use_modules(RealWorld Core Widgets Gui)

add_custom_command(TARGET RealWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:RealWorld>
    )