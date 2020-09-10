#pragma once

#include <QtWidgets>

namespace ui
{
    class SeekBar : public QSlider
    {
        Q_OBJECT

    public:
        SeekBar(QWidget *parent = NULL);
    };
} // namespace ui