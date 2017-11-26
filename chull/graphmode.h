#ifndef GRAPHMODE_H
#define GRAPHMODE_H

#include <QtCharts/QChartView>
#include <QtWidgets/QMainWindow>

#include "widget.h"

class graphMode : public Widget
{
    Q_OBJECT
public:
    explicit graphMode(Widget *parent = nullptr);
    void Process(int p, int a, QSize window_size);
    QtCharts::QChartView* Graph();

private:
std::vector<int> n_points;
std::vector<double> times;

signals:

public slots:
};

#endif // GRAPHMODE_H
