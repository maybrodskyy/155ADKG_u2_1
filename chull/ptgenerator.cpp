#include "ptgenerator.h"

ptgenerator::ptgenerator()
{

}

std::vector<QPoint> ptgenerator::generateCluster(int n){
    int num_clusters = n/10;
    int w = 600;
    int h = 600; //window size
    std::vector<QPoint> pts;
    //generate the starting point in each cluster
    for (unsigned i = 0; i<num_clusters;i++){
        QPoint master_pt(rand()%w,rand()%h);
        pts.push_back(master_pt);
        //generate points around the starting point
        for (unsigned j=0; j<(10-1);j++){
            double new_x = master_pt.x()+rand()%(w/20);
            double new_y = master_pt.y()+rand()%(h/20);
            pts.push_back(QPoint(new_x,new_y));

        }
    }
    return pts;
}
std::vector<QPoint> ptgenerator::generateRandom(int n){
    //QSize window_size = Widget::size(); //TODO figure out how to do sizing
    int w = 600;
    int h = 600; //window size
    std::vector<QPoint> pts;
    for (unsigned i = 0; i<n;i++){
        pts.push_back({rand()%w,rand()%h});
    }
    return pts;

}

//i tried to implement a diamond-square algorithm but it proved to be too much of a hassle
//so i decided to go with prime factors instead. go me!
std::vector<QPoint> ptgenerator::generateGrid(int n){
    int w = 600;
    int h = 600; //window size

    double ideal_ratio = w/h;
    std::vector<QPoint> pts;
    double magic = h;
    double gap = h/std::sqrt(n);
    //double x = 0;
    //double y = 0;

    for(double x=0;x<magic;x+=gap){
        for(double y=0;y<magic;y+=gap){
            pts.push_back(QPoint(x,y));
        }
    }

    return pts;
}
