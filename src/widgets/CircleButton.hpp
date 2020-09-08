#pragma once

#include <QtWidgets>

namespace ui
{
    class CircleButton : public QPushButton
    {
        Q_OBJECT
    public:
        CircleButton(const QString &text = "", QWidget *parent = NULL);
    };
} // namespace ui