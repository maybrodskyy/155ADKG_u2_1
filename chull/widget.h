#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

    void on_QuickHall_clicked();

    void on_Incremental_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
