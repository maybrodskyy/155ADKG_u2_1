#include "widget.h"
#include "ui_widget.h"
//#include <QMessageBox>
//#include "QDebug"
#include "graphmode.h"

//#include <QElapsedTimer>
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
QSize s = ui->Canvas->size();
std::vector<QPoint> pts = ptgenerator::generateRandom(input_numberd,s);
ui->Canvas->setPoints(pts);
ui->Canvas->repaint();
ui->walkthroughLabel->setText("Now select the convex hull algorithm.");

// zkousel jsem generaci -nezkousej ve widgetu plz :D


}


void Widget::on_Grid_clicked()
{
    ui->Canvas->clearHull();
    int input_numberd=ui->num_rand->text().toInt();
    QSize s = ui->Canvas->size();
    std::vector<QPoint> pts = ptgenerator::generateGrid(input_numberd,s);
    ui->Canvas->setPoints(pts);
    ui->Canvas->repaint();
    ui->walkthroughLabel->setText("Now select the convex hull algorithm.");
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
    QSize s = ui->Canvas->size();
    std::vector<QPoint> pts = ptgenerator::generateCluster(input_numberd,s);
    ui->Canvas->setPoints(pts);
    ui->Canvas->repaint();
    ui->walkthroughLabel->setText("Now select the convex hull algorithm.");
}

void Widget::on_Jarvis_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->walkthroughLabel->setText("Click the Generate Graph button and save the results!");
    }
    else{
        ui->Canvas->clearHull();
        std::vector<QPoint> pts = ui->Canvas->getPoints();
        std::clock_t t_start = std::clock();
        std::vector<QPoint> hull = algorithms::jarvisCH(pts);
        std::clock_t t_end = std::clock();
        ui->Canvas->setHull(hull);
        ui->Canvas->repaint();
        ui->time_output->setText(QString::number(double(t_end-t_start)/CLOCKS_PER_SEC));
    }


    //QElapsedTimer time_bitch;
    //time_bitch.start();
}

void Widget::on_QuickHull_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->walkthroughLabel->setText("Click the Generate Graph button and save the results!");
    }
    else{
        ui->Canvas->clearHull();
        std::vector<QPoint> pts = ui->Canvas->getPoints();
        std::clock_t t_start = std::clock();
        std::vector<QPoint> hull = algorithms::qhull(pts);
        std::clock_t t_end = std::clock();
        ui->Canvas->setHull(hull);
        ui->Canvas->repaint();
        ui->time_output->setText(QString::number(double(t_end-t_start)/CLOCKS_PER_SEC));
    }

    //QElapsedTimer time_bitch;
    //time_bitch.start();

}

void Widget::on_Incremental_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->walkthroughLabel->setText("Click the Generate Graph button and save the results!");
    }
    else{
        ui->Canvas->clearHull();
        std::vector<QPoint> pts = ui->Canvas->getPoints();
        std::clock_t t_start = std::clock();
        std::vector<QPoint> hull = algorithms::incr(pts);
        std::clock_t t_end = std::clock();
        ui->Canvas->setHull(hull);
        ui->Canvas->repaint();
        ui->time_output->setText(QString::number(double(t_end-t_start)/CLOCKS_PER_SEC));
    }

    //QElapsedTimer time_bitch;
    //time_bitch.start();
}

void Widget::on_Graham_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->walkthroughLabel->setText("Click the Generate Graph button and save the results!");
    }
    else{
        ui->Canvas->clearHull();
        std::vector<QPoint> pts = ui->Canvas->getPoints();
        std::clock_t t_start = std::clock();
        std::vector<QPoint> hull = algorithms::grscan(pts);
        std::clock_t t_end = std::clock();
        ui->Canvas->setHull(hull);
        ui->Canvas->repaint();
        ui->time_output->setText(QString::number(double(t_end-t_start)/CLOCKS_PER_SEC));
    }

}

void Widget::on_graphCheckBox_clicked(bool ticked)
{
        ui->num_rand->setDisabled(ticked);
        ui->generateGraph->setEnabled(ticked);
}

void Widget::on_clear_clicked()
{
    ui->Canvas->clearAll();
}

void Widget::on_generateGraph_clicked()
{
//postupne budu generovat n bodu a merit cas a vynaset grafy a vsichni budem stastny
}
