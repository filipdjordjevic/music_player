#pragma once

#include <string>

#include "Song.hpp"

namespace player
{

    class MusicPlayer
    {
        Song *song_;
        MusicPlayer();

    public:
        static MusicPlayer &instance();
        MusicPlayer(const MusicPlayer &) = delete;
        void operator=(const MusicPlayer &) = delete;
        ~MusicPlayer();
        void open(Song *song);
        void play() const;
        void pause() const;
        void seek(const long &ms) const;
        void setVolume(const long &value) const;
        long position() const;
        long songLength() const;
        Song *currentSong() const;
    };

} // namespace player