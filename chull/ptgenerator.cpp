#include "ptgenerator.h"

ptgenerator::ptgenerator()
{

}

std::vector<QPoint> ptgenerator::generateCluster(int n, QSize size){
    int num_clusters = n/100;
    int w = size.width();
    int h = size.height(); //window size
    std::vector<QPoint> pts;
    //generate the starting point in each cluster
    for (int i = 0; i<num_clusters;i++){
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
std::vector<QPoint> ptgenerator::generateRandom(int n,QSize size){
    //QSize window_size = Widget::size(); //TODO figure out how to do sizing
    int w = size.width();
    int h = size.height(); //window size
    std::vector<QPoint> pts;
    for (int i = 0; i<n;i++){
        pts.push_back({rand()%w,rand()%h});
    }
    return pts;

}

//i tried to implement a diamond-square algorithm but it proved to be too much of a hassle
//so i decided to go with prime factors instead. go me!
std::vector<QPoint> ptgenerator::generateGrid(int n, QSize size){
    //int w = size.width();
    int h = size.height(); //window size //window size

    //double ideal_ratio = w/h;
    std::vector<QPoint> pts;
    double gap = h/ceil(std::sqrt(n));

    for(double x=0;x<h;x+=gap){
        for(double y=0;y<h;y+=gap){
            pts.push_back(QPoint(x,y));
        }
    }

    return pts;
}
