#ifndef GRAPHMODE_H
#define GRAPHMODE_H

#include <QtCharts/QChartView>

#include "widget.h"

class graphMode : public Widget
{
    Q_OBJECT
public:
    explicit graphMode(Widget *parent = nullptr);
    void Process(int p, int a, QSize window_size);
    void Graph(std::vector<int> n_points, std::vector<double> times);

private:


signals:

public slots:
};

#endif // GRAPHMODE_H
