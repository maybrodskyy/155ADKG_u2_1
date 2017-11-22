#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include "QDebug"
#include <QElapsedTimer>
#include <ptgenerator.h>
#include <algorithms.h>
#include <ctime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::srand(std::time(0));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Random_clicked()
{
ui->Canvas->clearHull();
int input_numberd=ui->num_rand->text().toInt();
//comment out for testing
/*
if(input_numberd<1000 || input_numberd>1000000){
    QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of points has to be in interval between 1000 and 1000000"));
}
*/

std::vector<QPoint> pts = ptgenerator::generateRandom(input_numberd);
ui->Canvas->setPoints(pts);
ui->Canvas->repaint();

// zkousel jsem generaci -nezkousej ve widgetu plz :D


}


void Widget::on_Grid_clicked()
{
    ui->Canvas->clearHull();
    int input_numberd=ui->num_rand->text().toInt();
   /*
    if(input_numberd<1000 || input_numberd>1000000){
        QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of points has to be in interval between 1000 and 1000000"));
    }
    */
    std::vector<QPoint> pts = ptgenerator::generateGrid(input_numberd);
    ui->Canvas->setPoints(pts);
    ui->Canvas->repaint();
}

void Widget::on_Cluster_clicked()
{
    ui->Canvas->clearHull();
    int input_numberd=ui->num_rand->text().toInt();
    /*
    if(input_numberd<1000 || input_numberd>1000000){
        QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of points has to be in interval between 1000 and 1000000"));
    //close();
    }
    */

    std::vector<QPoint> pts = ptgenerator::generateCluster(input_numberd);
    ui->Canvas->setPoints(pts);
    ui->Canvas->repaint();
}

void Widget::on_Jarvis_clicked()
{
    ui->Canvas->clearHull();
    std::vector<QPoint> pts = ui->Canvas->getPoints();
    QElapsedTimer timer;
    timer.start();
    std::vector<QPoint> hull = algorithms::jarvisCH(pts);
    int time_elapsed = timer.elapsed();
    ui->Canvas->setHull(hull);
    ui->Canvas->repaint();
    ui->time_output->setText(QString::number(time_elapsed));


    //QElapsedTimer time_bitch;
    //time_bitch.start();
}

void Widget::on_QuickHull_clicked()
{
    ui->Canvas->clearHull();
    std::vector<QPoint> pts = ui->Canvas->getPoints();
    QElapsedTimer timer;
    timer.start();
    std::vector<QPoint> hull = algorithms::qhull(pts);
    int time_elapsed = timer.elapsed();
    ui->Canvas->setHull(hull);
    ui->Canvas->repaint();
    ui->time_output->setText(QString::number(time_elapsed));

    //QElapsedTimer time_bitch;
    //time_bitch.start();

}

void Widget::on_Incremental_clicked()
{
    ui->Canvas->clearHull();
    std::vector<QPoint> pts = ui->Canvas->getPoints();
    QElapsedTimer timer;
    timer.start();
    std::vector<QPoint> hull = algorithms::incr(pts);
    int time_elapsed = timer.elapsed();
    ui->Canvas->setHull(hull);
    ui->Canvas->repaint();
    ui->time_output->setText(QString::number(time_elapsed));

    //QElapsedTimer time_bitch;
    //time_bitch.start();
}

void Widget::on_clear_clicked()
{
    ui->Canvas->clearAll();
}
