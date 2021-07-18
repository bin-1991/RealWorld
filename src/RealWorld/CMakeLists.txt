

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_HOME "C:/Qt/6.0.4/msvc2019_64")
set(CMAKE_PREFIX_PATH ${QT_HOME})
set(CMAKE_MODULE_PATH ${QT_HOME})

find_package(Qt6 COMPONENTS Core Widgets LinguistTools REQUIRED PATHS ${QT_HOME})

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}
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
    
source_group(QHexEdit FILES ${hexedit_SRC})
#source_group(src FILES ${SRC})
source_group(qt REGULAR_EXPRESSION "(mocs_.*)|(qrc_.*)")

set(TS_SRC lang/zh-cn.ts)
add_executable(RealWorld WIN32 ${SRC} ${ui_FILES} ${res_FILES} ${TS_SRC} realworld.rc)
target_link_libraries(RealWorld Qt6::Widgets Qt6::Core Qt6::Gui)

add_custom_command(TARGET RealWorld PRE_BUILD
    COMMAND Qt6::lupdate -pro ${CMAKE_CURRENT_SOURCE_DIR}/realworld.pro
    COMMAND Qt6::lrelease ${TS_SRC}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

add_custom_command(TARGET RealWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Core> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Gui> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt6::Widgets> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:RealWorld>/platforms
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${QT_HOME}/plugins/platforms $<TARGET_FILE_DIR:RealWorld>/platforms
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:RealWorld>/styles
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${QT_HOME}/plugins/styles $<TARGET_FILE_DIR:RealWorld>/styles

    COMMAND ${CMAKE_COMMAND} -E remove_directory $<TARGET_FILE_DIR:RealWorld>/lang
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:RealWorld>/lang
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/lang $<TARGET_FILE_DIR:RealWorld>/lang
    )