#include "algorithms.h"
#include "sortbyxasc.h"
#include "sortbyyasc.h"
#include <qmath.h>

algorithms::algorithms()
{

}

int algorithms::getPosition(QPoint &q,QPoint &a, QPoint &b)
{
    double eps = 1.0e-8;
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

    return fabs(acos(s/(normU * normV)))*(180/M_PI);
}

std::vector<QPoint> algorithms::jarvisCH(std::vector<QPoint> &points)
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
    QPoint pj_1(s.x()-1,q.y()); //p(j-1)


    do{
        int imax = -1 ;
        double dmax = 0.0;
        double amax = 0.0;

        //Find max angle
        for(unsigned int i=0;i<points.size();i++)
        {

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

    //strict convetional chull

     ch.push_back(ch[0]);
     ch.push_back(ch[1]);

     for(uint i = 0 ; i < ch.size() - 1 ; i++ )
     {   // try to find points on the same line
         if( getPointLineDist( ch[i] , ch[i+1] , ch[i+2] ) ==-1 ){
             ch.erase(ch.begin()+(i+1));
             i=i-1;   // if point is finded go back to the previous point
     }
     }
     return ch;
}

std::vector<QPoint> algorithms::qhull(std::vector<QPoint> &points)
{
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

    for(unsigned int i=0; i < points.size(); ++i)
    {
        int pos = getPosition(points[i],q1,q3);

        //Add to UH
        if(pos==0) //1
        {
           uh.push_back(points[i]);
        }

        //Add to LH
        else if(pos==1) //0
        {
           lh.push_back(points[i]);
        }
    }

    //Process upper hull
    ch.push_back(q3);
    qh(uh, ch, 1, 0);

    //Process lower hull
    ch.push_back(q1);
    qh(lh, ch, 0, 1);


    //strict convetional chull

     ch.push_back(ch[0]);
     ch.push_back(ch[1]);

     for(uint i = 0 ; i < ch.size() - 1 ; i++ )
     {   // try to find points on the same line
         if( getPointLineDist( ch[i] , ch[i+1] , ch[i+2] ) ==-1 ){
             ch.erase(ch.begin()+(i+1));
             i=i-1;   // if point is finded go back to the previous point
     }
     }

   return ch;
}

void algorithms::qh(std::vector<QPoint> &points, std::vector<QPoint> &ch, int s, int e)
{

    double dmax = -1;
    int imax = -1;

    for(unsigned  int i = 0 ; i < points.size() ; i++)
    {
        int result = getPosition(points[i],points[s],points[e]);
        if (result ==1) {
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


std::vector<QPoint> algorithms::incr(std::vector<QPoint> &points)
{
   // elimination of all duplcite points

    double eps = 1e-12;
    int j=0;
    bool k= true;
    QPoint p_0(0, 0);

    if(k==true){

        std::sort(points.begin(), points.end(), sortByXAsc());
        j=0;
        k=false;
        for(unsigned int i = 0; i < points.size()-1; i++)
        {
            if((abs(points[i].x() - points[i+1].x()) < eps) && (abs(points[i].y() - points[i+1].y()) < eps))
            {
                points[i] = p_0;
                k = true;
                j++;
            }

    }


        std::sort(points.begin(), points.end(), sortByXAsc());
        points.erase(points.begin(),points.begin()+j);
    }
    //Amount of  points
    int m = points.size();

    std::vector<QPoint> ch;

    //Lists of previous and next indices
    std::vector<int> p(m);
    std::vector<int> n(m);

    //Sort by x
    std::sort(points.begin(),points.end(),sortByXAsc());

    //Initial approximation of CH
    p[0]=1;
    p[1]=0;
    n[0]=1;
    n[1]=0;

    //Position of q[2] according to q[0], q[1]
    if( getPosition(points[2],points[0],points[1]) == 1 ) //==1
    {
        n[1] = 2;
        n[2] = 0;
        p[2] = 1;
        p[0] = 2;

    }

    else
    {
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
        else
        {
            p[i]=p[i-1];
            n[i]=i-1;
        }

        //Connect point next to q[i] with q[i]
        //Connect point previous to q[i] with q[i]
        n[p[i]]=i;
        p[n[i]]=i;

        //Find upper tangent
        while(getPosition(points[n[n[i]]], points[i], points[n[i]]) == 0) //0
        {
            p[n[n[i]]]=i;
            n[i]=n[n[i]];
        }

        //Find lower tangent
        while(getPosition(points[p[p[i]]], points[p[i]],points[i]) == 0)//0
        {
            n[p[p[i]]]=i;
            p[i]=p[p[i]];
        }
    }

    //Add the left most point to ch
    ch.push_back(points[0]);

    //Convert circular list to list of points
    int index = n[0];

    do
    {
        ch.push_back(points[index]);
        index = n[index];
    }while(index != 0);



    //strict convex chull

     ch.push_back(ch[0]);
     ch.push_back(ch[1]);

     for(unsigned int i = 0 ; i < ch.size() - 1 ; i++ )
     {   // try to find points on the same line
         if( getPointLineDist( ch[i] , ch[i+1] , ch[i+2] ) ==-1 ){
             ch.erase(ch.begin()+(i+1));
             i=i-1;   // if point is finded go back to the previous point
     }
     }


    return ch;

}


QPoint algorithms::pvt;
QPoint algorithms::pvt_orient;

std::vector<QPoint> algorithms::grscan(std::vector<QPoint> &points)
{
     double eps = 1e-12;
     int j=0;
     bool k= true;
     QPoint p_0(0, 0);
     std::vector<QPoint> ch;
     std::vector<QPoint> sec_ch;

     // elimination of all duplcite points

     if(k==true){

         std::sort(points.begin(), points.end(), sortByXAsc());
         j=0;
         k=false;
         for(unsigned int i = 0; i < points.size()-1; i++)
         {
             if((abs(points[i].x() - points[i+1].x()) < eps) && (abs(points[i].y() - points[i+1].y()) < eps))
             {
                 points[i] = p_0;
                 k = true;
                 j++;
             }
     }
         std::sort(points.begin(), points.end(), sortByXAsc());
         points.erase(points.begin(),points.begin()+j);
     }

    // sort all points by Y
    std::sort(points.begin(), points.end(), sortByYAsc());
    // put pivot to the second slot
     ch.push_back(points[0]);
    sec_ch.push_back(points[0]);
    // create pivot
    pvt=points[0];
    //orientation of pivot
    pvt_orient.setX(-1000);
    pvt_orient.setY(pvt.y());

    std::sort(points.begin(), points.end(), compareAngle);

    // delete points on the same line
    for(unsigned int i=0; i<=points.size()-1;i++){

        while (getPosition(points[i],points[0],points[i+1])==-1)
        {
            i++;
        }
             ch.push_back(points[i]);
    }
    // the second minimum point to the last slot
    sec_ch.push_back(ch[1]);

  //Find convextible points

    for(unsigned int i = 2; i <= ch.size()-1; i++)
    {
       QPoint t1=sec_ch[sec_ch.size()-1];
       sec_ch.pop_back();
        QPoint t2 = sec_ch[sec_ch.size()-1];
        sec_ch.push_back(t1);

        while(getPosition(ch[i], t2, sec_ch[sec_ch.size()-1])!=1){
            sec_ch.pop_back();
            t1=sec_ch[sec_ch.size()-1];
            sec_ch.pop_back();
            t2 = sec_ch[sec_ch.size()-1];
            sec_ch.push_back(t1);
        }
        sec_ch.push_back(ch[i]);
    }

  for(unsigned int i = 0 ; i < sec_ch.size() - 1 ; i++ )
     {   // try to find points on the same line
         if( getPointLineDist( sec_ch[i] , sec_ch[i+1] , sec_ch[i+2] ) ==-1 ){
             sec_ch.erase(sec_ch.begin()+(i+1));
             i=i-1;   // if point is finded go back to the previous point
     }
     }
    return  sec_ch;
    }

    bool algorithms::compareAngle(QPoint &a, QPoint &b)
    {
        //function compare angles between 2 points
    const double eps = 1.0e-20;
    double anga = getAngle(pvt, pvt_orient, pvt, a);
    double angb = getAngle(pvt, pvt_orient, pvt, b);

    if(std::abs(anga - angb)>=eps){
    return anga>angb;
    }
    else{
        bool c = compareDistance(a,b);
        return c;
    }
    }

    bool algorithms::compareDistance(QPoint &a, QPoint &b)
    {
        //function compare distances between 2 points
    double d1 = distance(pvt, a);
    double d2 = distance(pvt, b);

    return d1<d2;
    }

