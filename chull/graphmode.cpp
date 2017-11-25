#include <ctime>
#include <QMessageBox>

#include "graphmode.h"
//#include "draw.h"
#include "ptgenerator.h"
#include "algorithms.h"
#include "draw.h"


graphMode::graphMode(Widget *parent) : Widget(parent)
{
}

void graphMode::Process(int p, int a, QSize window_size){ //point-generator and algorythm type selected
    std::vector<double> times; //the time it took to complete the hull

    int k = 1000; //for the sake of readable code
    std::vector<int> n_points = {1*k,5*k,10*k,25*k,50*k,100*k,250*k,500*k,750*k,1000*k}; //how many points were there

    //initialize a function pointer
    std::vector<QPoint> (*point_generator)(int, QSize);
    //determine which point-generator to use
    switch(p){
        case 1 : point_generator = ptgenerator::generateRandom;
        case 2 : point_generator = ptgenerator::generateGrid;
        case 3 : point_generator = ptgenerator::generateCluster;
    }

    //initialize a function pointer
    std::vector<QPoint> (*algorithm)(std::vector<QPoint>);
    //determine which algorithm to use
    switch(a){
        case 1 : algorithm = algorithms::jarvisCH;
        case 2 : algorithm = algorithms::qhull;
        case 3 : algorithm = algorithms::incr;
        case 4 : algorithm = algorithms::grscan;
    }

    //now actually do the magic
    for(int n : n_points){ //for every n in n points
        std::vector<QPoint> points = point_generator(n,window_size);
        double sum_time;
        for(int i = 0;i<=10;i++){ //do this 10 times
            std::clock_t start_time = std::clock();
            algorithm(points);
            std::clock_t end_time = std::clock();
            sum_time += (end_time-start_time);
        }
        times.push_back(sum_time/10);
    }

    //now draw graphs for that magic

}
