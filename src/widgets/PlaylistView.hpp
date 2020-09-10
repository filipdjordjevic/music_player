#pragma once

#include <QtWidgets>

#include "player/Playlist.hpp"
#include "SongListItem.hpp"

namespace ui
{
    class PlaylistView : public QListWidget
    {
        Q_OBJECT

    public:
        PlaylistView(QWidget *parent = NULL);
        void add(player::Song *song);
        void deleteItem(SongListItem *item);

    private:
        player::Playlist *playlist_;
        void populate();
        SongListItem *mapSongToListItem(player::Song *song);
        player::Song *mapListItemToSong(SongListItem *item);

    public slots:
        void handleItemDoubleClick(QListWidgetItem *item);
    signals:
        void songDoubleClicked();
    };

} // namespace ui