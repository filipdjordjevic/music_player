#pragma once

#include <QWidget>

#include "PlayerFrame.hpp"

namespace ui
{
    class MainWindow : public QWidget
    {
        Q_OBJECT

    private:
        PlayerFrame *player_;

    public:
        MainWindow(QWidget *parent = NULL);
    };
} // namespace ui