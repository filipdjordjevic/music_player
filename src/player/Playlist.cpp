#include "Playlist.hpp"

namespace player
{
    Playlist::Playlist()
    {
        repository_ = new data::SongTable;
        repository_->init();
        this->updateList();
    }

    void Playlist::add(Song *song)
    {
        list_.push_back(song);
        repository_->insert(song->name(), song->path());
    }

    void Playlist::deleteItem(const Song *song)
    {
        repository_->deleteRow(song->path());
    }

    std::vector<Song *> Playlist::getAll()
    {
        return list_;
    }

    Song *Playlist::mapTableToSong(const data::SongTable &table)
    {
        return new Song(table.path());
    }

    void Playlist::updateList()
    {
        std::vector<data::SongTable> iter = repository_->getAll();
        for (const data::SongTable &item : iter)
        {
            list_.push_back(mapTableToSong(item));
        }
    }
} // namespace player