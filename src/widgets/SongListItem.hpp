#pragma once

#include <QtWidgets>

namespace ui
{
    class SongListItem : public QListWidgetItem
    {
        QString name_;
        QString path_;

    public:
        SongListItem(QListWidget *parent = NULL);
        SongListItem(QString name_, QString path_, QListWidget *parent = NULL);
        QString path();
    };
} // namespace ui