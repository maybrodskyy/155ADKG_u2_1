#include <ctime>

#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <functional>

#include "graphmode.h"
//#include "draw.h"
#include "ptgenerator.h"
#include "algorithms.h"
#include "draw.h"


graphMode::graphMode(Widget *parent) : Widget(parent)
{
}

void graphMode::Process(int &p, int &a, QSize &window_size){ //point-generator and algorythm type selected
    int k = 1000; //for the sake of readable code
    n_points = {1*k,5*k,10*k,25*k,50*k,100*k,250*k,500*k,750*k,1000*k}; //how many points were there
    //initialize a function pointer
    //determine which point-generator to use
    std::function<std::vector<QPoint>(int&, QSize&)> point_generator = NULL;
    switch(p){
        case 1 : point_generator = ptgenerator::generateRandom;
        case 2 : point_generator = ptgenerator::generateGrid;
        case 3 : point_generator = ptgenerator::generateCluster;
    }
    //qDebug()<<"p"<<p;

    //initialize a function pointer
    std::function<std::vector<QPoint>(std::vector<QPoint>&)> algorithm = NULL;
    //determine which algorithm to use
    switch(a){
        case 1 : algorithm = algorithms::jarvisCH;
        case 2 : algorithm = algorithms::qhull;
        case 3 : algorithm = algorithms::incr;
#ifdef GRAHAM
        case 4 : algorithm = algorithms::grscan;
#endif
    }
    //qDebug()<<"a"<<a;

    //measure the time it takes to complete the selected algorithm (avg of 10)
    for(int n : n_points){ //for every n in n points
        //qDebug()<<"n"<<n;
        double sum_time = 0;
        for(int i = 0; i < 10; i++){
            std::vector<QPoint> points = point_generator(n,window_size);
            std::clock_t start_time = std::clock();
            algorithm(points);
            std::clock_t end_time = std::clock();
            sum_time += (double)(end_time-start_time)/CLOCKS_PER_SEC;
        }

        times.push_back(sum_time/10.0);
    }
}

QtCharts::QChartView* graphMode::Graph()
{
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    for(unsigned int i=0; i < n_points.size(); i++){
        series->append(n_points[i],times[i]);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart ->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setAttribute(Qt::WA_DeleteOnClose);

    QtCharts::QChartView *view = new QtCharts::QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    view->setAttribute(Qt::WA_DeleteOnClose);

    return view;
}
