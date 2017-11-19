/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    draw *Canvas;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *num_rand;
    QLabel *label_2;
    QLineEdit *num_cluster;
    QPushButton *Random;
    QPushButton *Grid;
    QPushButton *Cluster;
    QSpacerItem *verticalSpacer;
    QPushButton *Jarvis;
    QPushButton *QuickHall;
    QPushButton *Incremental;
    QLabel *time;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(709, 472);
        Canvas = new draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->setGeometry(QRect(10, 10, 481, 441));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(530, 10, 165, 379));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        num_rand = new QLineEdit(widget);
        num_rand->setObjectName(QStringLiteral("num_rand"));

        verticalLayout->addWidget(num_rand);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        num_cluster = new QLineEdit(widget);
        num_cluster->setObjectName(QStringLiteral("num_cluster"));

        verticalLayout->addWidget(num_cluster);

        Random = new QPushButton(widget);
        Random->setObjectName(QStringLiteral("Random"));

        verticalLayout->addWidget(Random);

        Grid = new QPushButton(widget);
        Grid->setObjectName(QStringLiteral("Grid"));

        verticalLayout->addWidget(Grid);

        Cluster = new QPushButton(widget);
        Cluster->setObjectName(QStringLiteral("Cluster"));

        verticalLayout->addWidget(Cluster);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Jarvis = new QPushButton(widget);
        Jarvis->setObjectName(QStringLiteral("Jarvis"));

        verticalLayout->addWidget(Jarvis);

        QuickHall = new QPushButton(widget);
        QuickHall->setObjectName(QStringLiteral("QuickHall"));

        verticalLayout->addWidget(QuickHall);

        Incremental = new QPushButton(widget);
        Incremental->setObjectName(QStringLiteral("Incremental"));

        verticalLayout->addWidget(Incremental);

        time = new QLabel(widget);
        time->setObjectName(QStringLiteral("time"));

        verticalLayout->addWidget(time);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "Number of points", 0));
        label_2->setText(QApplication::translate("Widget", "Number of clusters", 0));
        Random->setText(QApplication::translate("Widget", "Random", 0));
        Grid->setText(QApplication::translate("Widget", "Grid", 0));
        Cluster->setText(QApplication::translate("Widget", "Cluster", 0));
        Jarvis->setText(QApplication::translate("Widget", "Jarvis", 0));
        QuickHall->setText(QApplication::translate("Widget", "Quick Hall", 0));
        Incremental->setText(QApplication::translate("Widget", "Incremental", 0));
        time->setText(QApplication::translate("Widget", "Time [sec]", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
