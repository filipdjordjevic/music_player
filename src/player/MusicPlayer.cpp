#include "MusicPlayer.hpp"

#include <windows.h>
#include <sstream>

namespace player
{

    void mciSendStringShort(const char *command);

    MusicPlayer::MusicPlayer() {}

    MusicPlayer &MusicPlayer::instance()
    {
        static MusicPlayer instance;

        return instance;
    }

    void MusicPlayer::open(Song *song)
    {
        mciSendStringShort("close curr_song");
        this->song_ = song;
        std::stringstream command;
        command << "open \"" << song_->path() << "\" type mpegvideo alias curr_song";
        mciSendStringShort(command.str().c_str());
    }

    void MusicPlayer::play() const
    {
        mciSendStringShort("play curr_song");
    }

    void MusicPlayer::pause() const
    {
        mciSendStringShort("pause curr_song");
    }

    void MusicPlayer::seek(const long &ms) const
    {
        std::stringstream command;
        command << "seek curr_song to " << ms;
        mciSendStringShort(command.str().c_str());
    }

    void MusicPlayer::setVolume(const long &value) const
    {
        std::stringstream command;
        command << "setaudio curr_song volume to " << value;
        mciSendStringShort(command.str().c_str());
    }

    long MusicPlayer::position() const
    {
        char res[128];
        mciSendStringA("status curr_song position", res, 128, NULL);
        return atoi(res);
    }

    long MusicPlayer::songLength() const
    {
        char res[128];
        mciSendStringA("status curr_song length", res, 128, NULL);
        return atoi(res);
    }

    Song *MusicPlayer::currentSong() const
    {
        return this->song_;
    }

    MusicPlayer::~MusicPlayer()
    {
        mciSendStringShort("close curr_song");
        this->song_ = nullptr;
    }

    void mciSendStringShort(const char *command)
    {
        mciSendStringA(command, NULL, 0, NULL);
    }

} // namespace player