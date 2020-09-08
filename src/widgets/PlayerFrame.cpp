#include "PlayerFrame.hpp"

namespace ui
{
    PlayerFrame::PlayerFrame(QWidget *parent) : QFrame(parent)
    {
        playBtn_ = new CircleButton;
        soundBtn_ = new CircleButton;
        volumeSlider_ = new VolumeSlider;
        seekBar_ = new SeekBar;
        durationLbl_ = new LcdLabel("0:00");
        songLbl_ = new LcdLabel("Unknown.mp3");

        playBtn_->setObjectName("play");
        soundBtn_->setObjectName("speaker");

        QVBoxLayout *mainLayout = new QVBoxLayout;
        QHBoxLayout *bLayout = new QHBoxLayout;
        QHBoxLayout *tLayout = new QHBoxLayout;

        bLayout->addWidget(playBtn_);
        bLayout->addWidget(soundBtn_);
        bLayout->addWidget(volumeSlider_);

        tLayout->addWidget(durationLbl_);
        tLayout->addWidget(songLbl_);

        mainLayout->addLayout(tLayout);
        mainLayout->addWidget(seekBar_);
        mainLayout->addLayout(bLayout);

        setLayout(mainLayout);
    }
} // namespace ui