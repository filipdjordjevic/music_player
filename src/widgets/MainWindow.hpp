#pragma once

#include <QWidget>

namespace ui
{
    class MainWindow : public QWidget
    {
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = NULL);
    };
} // namespace ui