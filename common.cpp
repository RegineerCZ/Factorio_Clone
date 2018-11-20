#include "common.h"

common::common()
{
    _tim = new QTimer();
    connect(_tim, &QTimer::timeout, this, &common::timerTick);
}

void common::bindRenderer(renderProvider *provider)
{
    _renderer = provider;
}

void common::mousePosChanged(int x, int y)
{
    _renderer->mousePosChanges (x, y);
}

void common::regenerateMap()
{
    _renderer->regenerateMap ();
    if (!_tim->isActive ())
        _tim->start (500);
}

void common::timerTick()
{
    //_renderer->generateImage ();
}
