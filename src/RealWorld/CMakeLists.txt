
#INCLUDE(${QT_USE_FILE})
#ADD_DEFINITIONS(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

#source_group(ui REGULAR_EXPRESSION "\\.*\\.ui")
#source_group(moc REGULAR_EXPRESSION "(mocs_.*)|(moc_.*)")

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
    hexedit/hexeditor_global.h
    hexedit/hexeditorservice.h
    hexedit/hexedit.cpp
    hexedit/hexedit.h
    hexedit/markup.cpp
    hexedit/markup.h
    )

add_executable(RealWorld WIN32 ${SRC} ${ui_FILES} ${res_FILES} ${hexedit_SRC})
qt5_use_modules(RealWorld Core Widgets Gui)

add_custom_command(TARGET RealWorld POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Gui> $<TARGET_FILE_DIR:RealWorld>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Widgets> $<TARGET_FILE_DIR:RealWorld>
    )