#pragma once

#include <QtWidgets>

namespace ui
{
    class PlaylistView : public QListWidget
    {
        Q_OBJECT

    public:
        PlaylistView(QWidget *parent = NULL);
    };
} // namespace ui