#pragma once

#include <string>

#include "Song.hpp"

namespace player
{

    class MusicPlayer
    {
        Song *song_;

    public:
        MusicPlayer();
        ~MusicPlayer();
        void open(Song *song);
        void play() const;
        void pause() const;
        void seek(const long &ms) const;
        void setVolume(const long &value) const;
        long position() const;
        Song *currentSong() const;
    };

} // namespace player