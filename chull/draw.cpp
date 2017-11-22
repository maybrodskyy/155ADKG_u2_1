#include "draw.h"


draw::draw(QWidget *parent) : QWidget(parent)
{
}

/*
void draw::mousePressEvent(QMouseEvent *e)
{
    q.setX(e->pos().x());
    q.setY(e->pos().y());
    update();


}
*/

void draw::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter.setPen(pen);
    for(unsigned int i=0; i<points.size();i++){
        painter.drawPoint(points[i]);
    }
    QPolygon hull_polygon;
    QPen hull_pen;
    hull_pen.setColor(Qt::red);
    painter.setPen(hull_pen);
    for(unsigned int j = 0; j<hull.size();j++){
        hull_polygon.push_back(hull[j]);
    }
    painter.drawPolygon(hull_polygon);
    //painter.drawEllipse(q.x()-5, q.y()-5,15,15);


}

void draw::clearAll()
{
    points.clear();
    hull.clear();
    repaint();
}

void draw::clearHull()
{
    hull.clear();
    repaint();
}
