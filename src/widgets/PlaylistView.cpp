#include "PlaylistView.hpp"

#include "player/MusicPlayer.hpp"

namespace ui
{
    PlaylistView::PlaylistView(QWidget *parent) : QListWidget(parent)
    {
        playlist_ = new player::Playlist;
        this->populate();
        QObject::connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(handleItemDoubleClick(QListWidgetItem *)));
    }

    void PlaylistView::populate()
    {
        std::vector<player::Song *> list = playlist_->getAll();
        for (player::Song *song : list)
        {
            this->addItem(this->mapSongToListItem(song));
        }
    }

    void PlaylistView::add(player::Song *song)
    {
        this->addItem(this->mapSongToListItem(song));
        playlist_->add(song);
    }

    void PlaylistView::deleteItem(SongListItem *item)
    {
        playlist_->deleteItem(mapListItemToSong(item));
        delete item;
    }

    SongListItem *PlaylistView::mapSongToListItem(player::Song *song)
    {
        return new SongListItem(
            QString::fromStdString(song->name()),
            QString::fromStdString(song->path()));
    }

    player::Song *PlaylistView::mapListItemToSong(SongListItem *item)
    {
        return new player::Song(
            item->path().toStdString());
    }

    void PlaylistView::handleItemDoubleClick(QListWidgetItem *item)
    {
        player::MusicPlayer::instance().open(this->mapListItemToSong(static_cast<SongListItem *>(item)));
        emit this->songDoubleClicked();
    }

} // namespace ui