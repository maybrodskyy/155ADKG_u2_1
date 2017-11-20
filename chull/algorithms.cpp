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
        int result = getPosition(points[i],points[s],points[e]);
        if (result ==0) {
            double dist = getPointLineDist(points[i],points[s],points[e]);
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

double algorithms::getPointLineDist(QPoint &a, QPoint &p1, QPoint &p2)
{
    double xa=a.x();
    double ya=a.y();

    double x1=p1.x();
    double y1=p1.y();

    double x2=p2.x();
    double y2=p2.y();

    double dist = algorithms::distance(p1,p2);
    double value = xa*(y1-y2)+x1*(y2-ya)+x2*(ya-y1);

    double distance = value/dist;

    return distance;
}


std::vector<QPoint> algorithms::incr(std::vector<QPoint> points)
{
    //Amount of  points
    int m = points.size();

    std::vector<QPoint> ch;

    //Lists of previous and next indices
    std::vector<int> p(m);
    std::vector<int> n(m);

    //Sort by x
    std::sort(points.begin(),points.end(),sortByXAsc());

    // initial approximation of CH
    p[0]=1;
    p[1]=0;
    n[0]=1;
    n[1]=0;

    //Position of q[2] according to q[0], q[1]
    int OurPointIsOnLeftSide = getPosition(points[2],points[0],points[1]);
    if( OurPointIsOnLeftSide )
    {
        n[1] = 2;
        n[2] = 0;
        p[2] = 1;
        p[0] = 2;

    }else{
        n[0] = 2;
        n[2] = 1;
        p[2] = 0;
        p[1] = 2 ;
    }

    for(int i = 3; i<m; i++){

        //Point q[i] in upper half-plane
        //Connect q[i] with its previous and next points
        if(points[i].y()>points[i-1].y())
        {
            p[i] = i-1;
            n[i] = n[i-1];

        }
        //Point q[i] in lower half-plane
        //Connect q[i] with its previous and next points
        else{
            p[i]=p[i-1];
            n[i]=i-1;
        }

        //Connect point next to q[i] with q[i]
        //Connect point previous to q[i] with q[i]
        n[p[i]]=i;
        p[n[i]]=i;

        //Find upper tangent
        while(getPosition(points[n[n[i]]], points[i], points[n[i]]) == 0)
        {
            n[i]=n[n[i]];
            p[n[n[i]]]=i;

        }

        //Find lower tangent
        while(getPosition(points[p[p[i]]], points[p[i]],points[i]) == 0)
        {
            p[i]=p[p[i]];
            n[p[p[i]]]=i;

        }
    }

    // add the left most point to ch
    ch.push_back(points[0]);

    // convert circular list to list of points
    int index = n[0];

    do{
        ch.push_back(points[index]);
        index = n[index];
    }while(index != 0);

    return ch;
}














