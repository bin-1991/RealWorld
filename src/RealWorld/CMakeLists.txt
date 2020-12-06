
#INCLUDE(${QT_USE_FILE})
#ADD_DEFINITIONS(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)


include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/hexeditor
                    )


set(SRC RealWorld.h
        RealWorld.cpp
        mainwindow.h
        mainwindow.cpp
        )

set(ui_FILES mainwindow.ui)
set(res_FILES realworld.qrc)

set(hexedit_SRC 
    QHexEdit/ArrayCommand.h
    QHexEdit/ArrayCommand.cpp
    QHexEdit/QHexEdit.cpp
    QHexEdit/QHexEdit.h
    QHexEdit/QHexEditPrivate.cpp
    QHexEdit/QHexEditPrivate.h
    QHexEdit/XByteArray.cpp
    QHexEdit/XByteArray.h
    )
    
source_group(qt REGULAR_EXPRESSION "(mocs_.*)|(qrc_.*)")

add_executable(RealWorld WIN32 ${SRC} ${ui_FILES} ${res_FILES} ${hexedit_SRC})
qt5_use_modules(RealWorld Core Widgets Gui)

add_custom_command(TARGET RealWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:RealWorld>
    )