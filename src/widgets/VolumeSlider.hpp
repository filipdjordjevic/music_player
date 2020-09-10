#pragma once

#include <QtWidgets>

namespace ui
{
    class VolumeSlider : public QSlider
    {
        Q_OBJECT

    public:
        VolumeSlider(QWidget *parent = NULL);
    };
} // namespace ui
