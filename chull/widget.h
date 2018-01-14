#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_Random_clicked();

    void on_Grid_clicked();

    void on_Cluster_clicked();

    void on_Jarvis_clicked();

    void on_QuickHull_clicked();

    void on_Incremental_clicked();

    void on_clear_clicked();

    void on_Graham_clicked();

  //  void on_graphCheckBox_clicked(bool ticked);


private:
    Ui::Widget *ui;
    int point_type=0; //1 for random, 2 for grid, 3 for cluster
    int algorithm_type=0; //1 for jarvis, 2 for quickhull, 3 for incremental, 4 for graham
    int error_flag = true;
    void msgSettings(QMessageBox *msg){
        msg->setAttribute(Qt::WA_DeleteOnClose, true);
        msg->setWindowTitle("Invalid input");
        msg->setText("Please insert a number greater than 0");
    }
};

#endif // WIDGET_H
