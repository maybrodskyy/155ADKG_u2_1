#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QPoint>

class algorithms
{
public:
    algorithms();
    static int getPosition(QPoint &p,QPoint &a,QPoint &b);
    static double getAngle(QPoint &,QPoint &,QPoint &, QPoint &);
    static std::vector<QPoint> jarvisCH(std::vector<QPoint>points);

    static double distance(QPoint a, QPoint b){
        double dx = b.x() - a.x();
        double dy = b.y() - a.y();
        return sqrt(dx*dx + dy*dy);
    }
    static std::vector<QPoint> qhull(std::vector<QPoint> points);

    void qh(std::vector<QPoint> &points, std::vector<QPoint> &ch, int s, int e);
};

#endif // ALGORITHMS_H
