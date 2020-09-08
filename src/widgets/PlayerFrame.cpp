#include "PlayerFrame.hpp"

#include "player/MusicPlayer.hpp"
#include "util/TimeConverter.hpp"

using namespace player;

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
        playing_ = false;
        timer_ = new QTimer;

        playBtn_->setObjectName("play");
        soundBtn_->setObjectName("speaker");

        this->connectWidgetsToActions();

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

    void PlayerFrame::loadSongData()
    {
        MusicPlayer *player = &MusicPlayer::instance();
        QString name = QString::fromStdString(player->currentSong()->name());
        this->songLbl_->setText(name);
        this->seekBar_->setMaximum(player->songLength());
    }

    void PlayerFrame::connectWidgetsToActions()
    {
        MusicPlayer *player = &MusicPlayer::instance();
        QObject::connect(playBtn_, &CircleButton::clicked,
                         [this, player] {
                             if (this->playing_)
                             {
                                 this->playBtn_->setStyleSheet("qproperty-icon: url(\":/icon/play.svg\");");
                                 player->pause();
                             }
                             else
                             {
                                 this->playBtn_->setStyleSheet("qproperty-icon: url(\":/icon/pause.svg\");");
                                 player->play();
                             }
                             this->playing_ = !this->playing_;
                         });

        QObject::connect(soundBtn_, &CircleButton::clicked,
                         [this, player] {
                             if (this->volumeSlider_->value() == 0)
                             {
                                 this->soundBtn_->setStyleSheet("qproperty-icon: url(\":/icon/speaker.svg\");");
                                 player->setVolume(500);
                                 this->volumeSlider_->setValue(500);
                                 return;
                             }
                             this->soundBtn_->setStyleSheet("qproperty-icon: url(\":/icon/speaker_mute.svg\");");
                             player->setVolume(0);
                             this->volumeSlider_->setValue(0);
                         });

        QObject::connect(volumeSlider_, &VolumeSlider::sliderReleased,
                         [this, player] {
                             player->setVolume(this->volumeSlider_->value());
                             if (this->volumeSlider_->value() == 0)
                             {
                                 this->soundBtn_->setStyleSheet("qproperty-icon: url(\":/icon/speaker_mute.svg\");");
                                 return;
                             }
                             this->soundBtn_->setStyleSheet("qproperty-icon: url(\":/icon/speaker.svg\");");
                         });

        QObject::connect(seekBar_, &SeekBar::sliderReleased,
                         [this, player] {
                             player->seek(this->seekBar_->value());
                             player->play();
                         });

        QObject::connect(timer_, &QTimer::timeout,
                         [this, player] {
                             long position = player->position();
                             this->durationLbl_->setText(QString::fromStdString(util::TimeConverter::msToMinSec(position)));
                             this->seekBar_->setValue(position);
                         });

        timer_->start(1000);
    }
} // namespace ui