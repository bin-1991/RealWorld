add_qtc_plugin(BinEditor
  PLUGIN_DEPENDS Core TextEditor
  SOURCES
    hexeditor_global.h
    hexeditorconstants.h
    hexeditorplugin.cpp hexeditorplugin.h
    hexeditorservice.h
    hexeditorwidget.cpp hexeditorwidget.h
    markup.cpp markup.h
)
