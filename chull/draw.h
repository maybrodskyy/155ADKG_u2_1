#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QPoint>
#include <QtGui>
#include<QString>
#include<fstream>
#include<vector>

class draw : public QWidget
{
    Q_OBJECT
private:
    QPoint q;
    std::vector<QPoint> points;

public:
    explicit draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void clear();
    std::vector<QPoint> getPoints(){return points;} //access to private points
    void setPoints(std::vector<QPoint> pts){points = pts;}
signals:

public slots:
};

#endif // DRAW_H
