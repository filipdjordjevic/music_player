QT += widgets core 

TEMPLATE = app
TARGET = music_player
INCLUDEPATH += src/


# Input
SOURCES += \
    src/main.cpp \
    src/widgets/MainWindow.cpp \
    src/widgets/CircleButton.cpp \

HEADERS += \
    src/widgets/MainWindow.hpp \
    src/widgets/CircleButton.hpp \

RESOURCES += \
    resources/res.qrc \
    