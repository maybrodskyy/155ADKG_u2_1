#include "draw.h"


draw::draw(QWidget *parent) : QWidget(parent)
{
}


void draw::mousePressEvent(QMouseEvent *e)
{
    q.setX(e->pos().x());
    q.setY(e->pos().y());
    update();


}

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
    //painter.drawEllipse(q.x()-5, q.y()-5,15,15);


}

void draw::clear()
{
    points.clear();
    repaint();
}
