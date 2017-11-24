#include <ctime>
#include <QMessageBox>

#include "graphmode.h"
#include "draw.h"


graphMode::graphMode(Widget *parent) : Widget(parent)
{
}

void graphMode::Process(std::vector<QPoint>(*f)(std::vector<QPoint>)){
    std::vector<double> times; //the time it took to complete the hull
    int k = 1000; //for the sake of readable code
    std::vector<int> n_points = {1*k,5*k,10*k,25*k,50*k,100*k,250*k,500*k,750*k,1000*k}; //how many points were there
    for(int n : n_points){ //for every n in n points
        for(int i = 0;i<=10;i++){ //do this 10 times
            std::clock_t start_time = std::clock();
            //std::vector<QPoint> funct = (*f)();
            std::clock_t end_time = std::clock();
        }
    }


}
