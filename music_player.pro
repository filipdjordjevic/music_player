QT += widgets core 

TEMPLATE = app
TARGET = music_player
INCLUDEPATH += src/


# Input
SOURCES += \
    src/main.cpp \
    src/widgets/MainWindow.cpp \
    src/widgets/CircleButton.cpp \
    src/widgets/VolumeSlider.cpp \
    src/widgets/SeekBar.cpp \
    src/widgets/LcdLabel.cpp \

HEADERS += \
    src/widgets/MainWindow.hpp \
    src/widgets/CircleButton.hpp \
    src/widgets/VolumeSlider.hpp \
    src/widgets/SeekBar.hpp \
    src/widgets/LcdLabel.hpp \

RESOURCES += \
    resources/res.qrc \
    