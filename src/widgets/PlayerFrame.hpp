#pragma once

#include <QtWidgets>

#include "VolumeSlider.hpp"
#include "SeekBar.hpp"
#include "LcdLabel.hpp"
#include "CircleButton.hpp"

namespace ui
{
    class PlayerFrame : public QFrame
    {
        Q_OBJECT

    private:
        CircleButton *playBtn_;
        CircleButton *soundBtn_;
        VolumeSlider *volumeSlider_;
        SeekBar *seekBar_;
        LcdLabel *durationLbl_;
        LcdLabel *songLbl_;
        bool playing_;
        QTimer *timer_;

        void connectWidgetsToActions();

    public:
        PlayerFrame(QWidget *parent = NULL);
        void loadSongData();
    };
} // namespace ui