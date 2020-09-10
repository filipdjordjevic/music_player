#include "SongListItem.hpp"

namespace ui
{
    SongListItem::SongListItem(QListWidget *parent) : QListWidgetItem(parent)
    {
    }

    SongListItem::SongListItem(QString name, QString path, QListWidget *parent) : QListWidgetItem(parent)
    {
        name_ = name;
        path_ = path;
        this->setText(name_);
    }

    QString SongListItem::path()
    {
        return path_;
    }
}