#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QPoint>

class algorithms
{
public:
    algorithms();
    static int getPosition(QPoint &p,QPoint &a,QPoint &b);
    static double getAngle(QPoint &,QPoint &,QPoint &, QPoint &);
    static double getPointLineDist(QPoint &a, QPoint &p1, QPoint &p2);
    static bool compareAngle(QPoint &a, QPoint &b);
    static bool compareDistance(QPoint &a, QPoint &b);

    static double distance(QPoint a, QPoint b){
        double dx = b.x() - a.x();
        double dy = b.y() - a.y();
        return sqrt(dx*dx + dy*dy);
    }

    static std::vector<QPoint> jarvisCH(std::vector<QPoint> &);
    static std::vector<QPoint> qhull(std::vector<QPoint> &points);
    static std::vector<QPoint> incr(std::vector<QPoint> &points);
    static void qh(std::vector<QPoint> &points, std::vector<QPoint> &ch, int s, int e);
    static std::vector<QPoint> grscan(std::vector<QPoint> &points);
    static QPoint pvt;
    static QPoint pvt_orient;
};

#endif // ALGORITHMS_H
