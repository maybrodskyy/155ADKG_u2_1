#ifndef GRAPHMODE_H
#define GRAPHMODE_H

#include "widget.h"

class graphMode : public Widget
{
    Q_OBJECT
public:
    explicit graphMode(Widget *parent = nullptr);
    void Process(int p, int a, QSize window_size);

signals:

public slots:
};

#endif // GRAPHMODE_H
