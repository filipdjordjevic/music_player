#pragma once

#include <QWidget>

#include "PlayerFrame.hpp"
#include "PlaylistView.hpp"

namespace ui
{
    class MainWindow : public QWidget
    {
        Q_OBJECT

    private:
        PlayerFrame *player_;
        PlaylistView *playlistView_;
        QHBoxLayout *titleBtns_;
        QPoint dragPosition_;

    public:
        MainWindow(QWidget *parent = NULL);
        void initTitlebar();

    protected:
        void mouseMoveEvent(QMouseEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;
        void paintEvent(QPaintEvent *event) override;
    };
} // namespace ui