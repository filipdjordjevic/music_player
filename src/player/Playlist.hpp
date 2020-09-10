#pragma once

#include <vector>

#include "Song.hpp"
#include "data/SongTable.hpp"

namespace player
{
    class Playlist
    {
        std::vector<Song *> list_;
        data::SongTable *repository_;

    public:
        Playlist();
        void add(Song *song);
        void deleteItem(const Song *song);
        std::vector<Song *> getAll();

    private:
        Song *mapTableToSong(const data::SongTable &table);
        void updateList();
    };
} // namespace player