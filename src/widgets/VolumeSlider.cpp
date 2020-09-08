#include "VolumeSlider.hpp"

namespace ui
{
    VolumeSlider::VolumeSlider(QWidget *parent) : QSlider(Qt::Horizontal, parent)
    {
        this->setMaximum(1000);
        this->setValue(this->maximum());
    }
} // namespace ui