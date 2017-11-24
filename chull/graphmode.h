#ifndef GRAPHMODE_H
#define GRAPHMODE_H

#include "widget.h"

class graphMode : public Widget
{
    Q_OBJECT
public:
    explicit graphMode(Widget *parent = nullptr);
    void Process(std::vector<QPoint>(*f)(std::vector<QPoint>));

signals:

public slots:
};

#endif // GRAPHMODE_H
