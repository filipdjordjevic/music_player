QT += widgets core 

TEMPLATE = app
TARGET = music_player
INCLUDEPATH += src/

include(lib/winmm.pri)

# Input
SOURCES += \
    src/main.cpp \
    src/player/Song.cpp \
    src/player/MusicPlayer.cpp \
    src/util/TimeConverter.cpp \

HEADERS += \
    src/player/Song.hpp \
    src/player/MusicPlayer.hpp \
    src/util/TimeConverter.hpp \



