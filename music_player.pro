QT += widgets core 

TEMPLATE = app
TARGET = music_player
INCLUDEPATH += src/


# Input
SOURCES += \
    src/main.cpp \
    src/widgets/MainWindow.cpp

HEADERS += \
    src/widgets/MainWindow.hpp

RESOURCES += \
    resources/res.qrc \
    