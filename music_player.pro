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
    src/widgets/MainWindow.cpp \
    src/widgets/CircleButton.cpp \
    src/widgets/VolumeSlider.cpp \
    src/widgets/SeekBar.cpp \
    src/widgets/LcdLabel.cpp \
    src/widgets/PlayerFrame.cpp \
    src/data/sqlite/sqlite3.c \
    src/data/SongTable.cpp \

HEADERS += \
    src/player/Song.hpp \
    src/player/MusicPlayer.hpp \
    src/util/TimeConverter.hpp \
    src/widgets/MainWindow.hpp \
    src/widgets/CircleButton.hpp \
    src/widgets/VolumeSlider.hpp \
    src/widgets/SeekBar.hpp \
    src/widgets/LcdLabel.hpp \
    src/widgets/PlayerFrame.hpp \
    src/data/sqlite/sqlite3.h \
    src/data/SongTable.hpp \

RESOURCES += \
    resources/res.qrc \
