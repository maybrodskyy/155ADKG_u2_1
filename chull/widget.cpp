#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include "QDebug"
#include <QElapsedTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_Random_clicked()
{
int input_numberd=ui->num_rand->text().toInt();
if(input_numberd<1000 || input_numberd>1000000){
    QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of points has to be in interval between 1000 and 1000000"));
close();
}

// zkousel jsem generaci
std::vector<QPoint> random_points;
int x,y;

for(int i = 0; i < input_numberd; i++)
{
    x = qrand() % 600 + 10;
    y = qrand() % 200 + 10;
    QPoint point(x, y);

    random_points.push_back(point);
}


}


void Widget::on_Grid_clicked()
{
    int input_numberd=ui->num_rand->text().toInt();
    if(input_numberd<1000 || input_numberd>1000000){
        QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of points has to be in interval between 1000 and 1000000"));
    close();
    }
}

void Widget::on_Cluster_clicked()
{
    int input_numberd=ui->num_rand->text().toInt();
    if(input_numberd<1000 || input_numberd>1000000){
        QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of points has to be in interval between 1000 and 1000000"));
    close();
    }

    int input_num_clu=ui->num_cluster->text().toInt();
    // nezaznamenal jsem limity rozmery ctvercu
    if(input_num_clu<9 || input_num_clu>1001){
        QMessageBox::information(this,tr("WRONG NUMBER"),tr("the number of clusters has to be in interval between 10 and 1000"));
    close();
    }
}

void Widget::on_Jarvis_clicked()
{
    ui->Canvas->repaint();

    QElapsedTimer time_bitch;
    time_bitch.start();
}

void Widget::on_QuickHall_clicked()
{
    ui->Canvas->repaint();

    QElapsedTimer time_bitch;
    time_bitch.start();

}

void Widget::on_Incremental_clicked()
{
    ui->Canvas->repaint();

    QElapsedTimer time_bitch;
    time_bitch.start();
}
