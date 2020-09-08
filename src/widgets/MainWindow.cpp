#include "MainWindow.hpp"

namespace ui
{
    MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
    {
        player_ = new PlayerFrame;

        QVBoxLayout *mainLayout = new QVBoxLayout;

        mainLayout->addWidget(player_);

        setLayout(mainLayout);
        this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    }
} // namespace ui