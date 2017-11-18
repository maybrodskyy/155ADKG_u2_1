#include "algorithms.h"
#include "sortbyxasc.h"
#include "sortbyyasc.h"

algorithms::algorithms()
{

}


int algorithms::getPosition(QPoint &q,QPoint &a, QPoint &b)
{
    double eps = 1.0e-6;
    double ux = b.x() - a.x();
    double uy = b.y() - a.y();
    double vx = q.x() - a.x();
    double vy = q.y() - a.y();

    double det = (ux * vy - uy * vx);
    if(det>eps)
        return 1;

    if(det<-eps)
        return 0;

    return -1;
}

double algorithms::getAngle(QPoint &p1,QPoint &p2,QPoint &p3, QPoint &p4)
{
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    double s = ux * vx + uy * vy;
    double normU = sqrt(ux * ux + uy * uy);
    double normV = sqrt(vx * vx + vy * vy);

    double test =  (acos(s/(normU * normV)))*(180/M_PI);
    return fabs(acos(s/(normU * normV)))*(180/M_PI);
}

std::vector<QPoint> algorithms::jarvisCH(std::vector<QPoint>points)
{
    const double AEPS = 1.0e-5;
    std::vector<QPoint> ch;

    // Sort points by Y
    std::sort (points.begin(),points.end(),sortByYAsc ());

    //Find pivot
    QPoint q = points[0];

    //Ad pivot to ca
    ch.push_back(q);

    //Find left-most point
    std::sort(points.begin(),points.end(),sortByXAsc());
    QPoint s = points[0];

    //Assign initial points
    QPoint pj = q;
    QPoint pj_1(s.x(),q.y()); //p(j-1)


    do{
        int imax = -1 ;
        double dmax = 0;
        double amax = 0;

        //Find max angle
        for(int i=0;i<points.size();i++){

            double angle=getAngle(pj,points[i],pj,pj_1);

            //Common point
            if(angle > amax)
            {
                amax = angle;
                imax = i;
            }

            //Singular point
            else if (std::fabs(angle - amax) <AEPS )
            {
                double dist = distance(points[i],pj);
                if (dist > dmax)
                {
                    dmax = dist;
                    imax = i;
                }
            }
        }

        //Add point to ch
        ch.push_back(points[imax]);

        //Assign points
        pj_1 = pj;
        pj = points[imax];


    }
    while(pj != q);
}

std::vector<QPoint> algorithms::qhull(std::vector<QPoint> points){
    std::vector<QPoint> ch;
    std::vector<QPoint> uh;
    std::vector<QPoint> lh;

    //Find left-most and right-most points
    std::sort(points.begin(), points.end(),sortByXAsc());
    QPoint q1 = points[0];
    QPoint q3 = points[points.size()-1];

    uh.push_back(q1);
    uh.push_back(q3);

    lh.push_back(q1);
    lh.push_back(q3);

    for(int i=0; i < points.size(); ++i)
    {
        int pos = getPosition(points[i],q1,q3);

        //Add to UH
        if(pos==1)
        {
           uh.push_back(points[i]);
        }

        //Add to LH
        else if(pos==0)
        {
           lh.push_back(points[i]);
        }
    }
}

void algorithms::qh(std::vector<QPoint> &points, std::vector<QPoint> &ch, int s, int e)
{

    double dmax = -1;
    int imax = -1;

    for(int i = 0 ; i < points.size() ; i++)
    {
        int result = algorithms::getPosition(points[i],points[s],points[e]);
        if (result ==0) {
            double dist = 0; //todo
            if (dist > dmax){
                imax = i;
                dmax = dist;
            }
        }
    }

    //Point found in the right halfplane
    if(imax != -1){
        //First segment
        qh(points, ch, s, imax);

        //Add point to ch
        ch.push_back(points[imax]);

        //Second segment
        qh(points, ch, imax, e);


    }





}


















