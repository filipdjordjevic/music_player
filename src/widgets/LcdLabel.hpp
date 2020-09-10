#pragma once

#include <QtWidgets>

namespace ui
{
    class LcdLabel : public QLabel
    {
        Q_OBJECT

    public:
        LcdLabel(const QString &text, QWidget *parent = NULL);
    };
} // namespace ui