#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
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
    delete ui;;
}


void Widget::on_Random_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->pointLabel->setText("Random");
        point_type = 1;
    }
    else{
        int input_numberd=ui->num_rand->text().toInt();
        if(input_numberd<=0){
            error_flag = true;
            QMessageBox *msg = new QMessageBox();
            msgSettings(msg);
            msg->show();
            return;
        }
        error_flag = false;
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        std::vector<QPoint> pts = ptgenerator::generateRandom(input_numberd,s);
        ui->Canvas->setPoints(pts);
        ui->Canvas->repaint();
    }
    ui->walkthroughLabel->setText("Now select the convex hull algorithm.");

// zkousel jsem generaci -nezkousej ve widgetu plz :D
}


void Widget::on_Grid_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->pointLabel->setText("Grid");
        point_type = 2;
    }
    else{
        int input_numberd=ui->num_rand->text().toInt();
        if(input_numberd<=0){
            error_flag = true;
            QMessageBox *msg = new QMessageBox();
            msgSettings(msg);
            msg->show();
            return;
        }
        error_flag = false;
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        std::vector<QPoint> pts = ptgenerator::generateGrid(input_numberd,s);
        ui->Canvas->setPoints(pts);
        ui->Canvas->repaint();
    }
    ui->walkthroughLabel->setText("Now select the convex hull algorithm.");
}

void Widget::on_Cluster_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->pointLabel->setText("Cluster");
        point_type = 3;
    }
    else{
        int input_numberd=ui->num_rand->text().toInt();
        if(input_numberd<=0){
            error_flag = true;
            QMessageBox *msg = new QMessageBox();
            msgSettings(msg);
            msg->show();
            return;
        }
        error_flag=0;
        ui->Canvas->clearHull();
        QSize s = ui->Canvas->size();
        std::vector<QPoint> pts = ptgenerator::generateCluster(input_numberd,s);
        ui->Canvas->setPoints(pts);
        ui->Canvas->repaint();
    }
    ui->walkthroughLabel->setText("Now select the convex hull algorithm.");
}

void Widget::on_Jarvis_clicked()
{
    if(ui->graphCheckBox->checkState()){
        ui->walkthroughLabel->setText("Click the Generate Graph button and save the results!");
        ui->hullLabel->setText("Jarvis");
        algorithm_type = 1;
    }
    else{
        if(error_flag) return;
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
        ui->hullLabel->setText("QuickHull");
        algorithm_type = 2;
    }
    else{
        if(error_flag) return;
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
        ui->hullLabel->setText("Incremental");
        algorithm_type = 3;
    }
    else{
        if(error_flag) return;
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
        ui->hullLabel->setText("Graham");
        algorithm_type = 4;
    }
    else{
        if(error_flag) return;
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
        ui->textLabel->setEnabled(ticked);
        ui->hullLabel->setEnabled(ticked);
        ui->pointLabel->setEnabled(ticked);
}

void Widget::on_clear_clicked()
{
    ui->Canvas->clearAll();
}

void Widget::on_generateGraph_clicked()
{
    QSize s = ui->Canvas->size(); //window size

    graphMode* generateGraph = new graphMode();
    generateGraph->Process(point_type, algorithm_type,s);
    QtCharts::QChartView *view = generateGraph->Graph();

    QMainWindow* window = new QMainWindow();
    window->setAttribute(Qt::WA_DeleteOnClose,true);
    window->setCentralWidget(view);
    window->resize(400,300);
    window->show();

    delete generateGraph;

    /*
    QString filename = QString::fromStdString("C:/Users/PMM/Documents/algoritmy/u2/155ADKG_u2_1/graph.pdf");
    QPdfWriter pdfWriter(filename);
    pdfWriter.setPageSizeMM(window.size());
    QPainter painter(&pdfWriter);
    view.render(&painter);
    painter.end();
    */
}
