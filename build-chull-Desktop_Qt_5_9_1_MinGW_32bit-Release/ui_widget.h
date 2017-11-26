/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
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
    QHBoxLayout *horizontalLayout;
    draw *Canvas;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *num_rand;
    QCheckBox *graphCheckBox;
    QLabel *walkthroughLabel;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Random;
    QPushButton *Grid;
    QPushButton *Cluster;
    QSpacerItem *verticalSpacer;
    QPushButton *Jarvis;
    QPushButton *QuickHull;
    QPushButton *Incremental;
    QPushButton *Graham;
    QSpacerItem *verticalSpacer_3;
    QLabel *textLabel;
    QLabel *pointLabel;
    QLabel *hullLabel;
    QPushButton *generateGraph;
    QPushButton *clear;
    QLabel *time;
    QLabel *time_output;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1030, 557);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Canvas = new draw(Widget);
        Canvas->setObjectName(QStringLiteral("Canvas"));
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(311, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
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

        graphCheckBox = new QCheckBox(widget);
        graphCheckBox->setObjectName(QStringLiteral("graphCheckBox"));

        verticalLayout->addWidget(graphCheckBox);

        walkthroughLabel = new QLabel(widget);
        walkthroughLabel->setObjectName(QStringLiteral("walkthroughLabel"));

        verticalLayout->addWidget(walkthroughLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

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

        QuickHull = new QPushButton(widget);
        QuickHull->setObjectName(QStringLiteral("QuickHull"));

        verticalLayout->addWidget(QuickHull);

        Incremental = new QPushButton(widget);
        Incremental->setObjectName(QStringLiteral("Incremental"));

        verticalLayout->addWidget(Incremental);

        Graham = new QPushButton(widget);
        Graham->setObjectName(QStringLiteral("Graham"));

        verticalLayout->addWidget(Graham);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        textLabel = new QLabel(widget);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        textLabel->setEnabled(false);

        verticalLayout->addWidget(textLabel);

        pointLabel = new QLabel(widget);
        pointLabel->setObjectName(QStringLiteral("pointLabel"));
        pointLabel->setEnabled(false);

        verticalLayout->addWidget(pointLabel);

        hullLabel = new QLabel(widget);
        hullLabel->setObjectName(QStringLiteral("hullLabel"));
        hullLabel->setEnabled(false);

        verticalLayout->addWidget(hullLabel);

        generateGraph = new QPushButton(widget);
        generateGraph->setObjectName(QStringLiteral("generateGraph"));
        generateGraph->setEnabled(false);

        verticalLayout->addWidget(generateGraph);

        clear = new QPushButton(widget);
        clear->setObjectName(QStringLiteral("clear"));

        verticalLayout->addWidget(clear);

        time = new QLabel(widget);
        time->setObjectName(QStringLiteral("time"));

        verticalLayout->addWidget(time);

        time_output = new QLabel(widget);
        time_output->setObjectName(QStringLiteral("time_output"));

        verticalLayout->addWidget(time_output);


        horizontalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "Number of points:", Q_NULLPTR));
        graphCheckBox->setText(QApplication::translate("Widget", "Graph mode", Q_NULLPTR));
        walkthroughLabel->setText(QApplication::translate("Widget", "Select point generation method.", Q_NULLPTR));
        Random->setText(QApplication::translate("Widget", "Random", Q_NULLPTR));
        Grid->setText(QApplication::translate("Widget", "Grid", Q_NULLPTR));
        Cluster->setText(QApplication::translate("Widget", "Cluster", Q_NULLPTR));
        Jarvis->setText(QApplication::translate("Widget", "Jarvis", Q_NULLPTR));
        QuickHull->setText(QApplication::translate("Widget", "Quick Hull", Q_NULLPTR));
        Incremental->setText(QApplication::translate("Widget", "Incremental", Q_NULLPTR));
        Graham->setText(QApplication::translate("Widget", "Graham Scan", Q_NULLPTR));
        textLabel->setText(QApplication::translate("Widget", "You have selected:", Q_NULLPTR));
        pointLabel->setText(QString());
        hullLabel->setText(QString());
        generateGraph->setText(QApplication::translate("Widget", "Generate graph", Q_NULLPTR));
        clear->setText(QApplication::translate("Widget", "Clear All", Q_NULLPTR));
        time->setText(QApplication::translate("Widget", "Time [sec]:", Q_NULLPTR));
        time_output->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
