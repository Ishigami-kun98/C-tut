/********************************************************************************
** Form generated from reading UI file 'third.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRD_H
#define UI_THIRD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Third
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_last_name;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_first_name;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Third)
    {
        if (Third->objectName().isEmpty())
            Third->setObjectName(QString::fromUtf8("Third"));
        Third->resize(540, 378);
        centralWidget = new QWidget(Third);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 344, 172));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_last_name = new QLabel(verticalLayoutWidget);
        label_last_name->setObjectName(QString::fromUtf8("label_last_name"));
        QFont font;
        font.setPointSize(12);
        label_last_name->setFont(font);

        horizontalLayout_2->addWidget(label_last_name);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_8->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_first_name = new QLabel(verticalLayoutWidget);
        label_first_name->setObjectName(QString::fromUtf8("label_first_name"));
        label_first_name->setFont(font);

        horizontalLayout_3->addWidget(label_first_name);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout_8->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_8);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_8->addWidget(label);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_7->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout_7->addLayout(horizontalLayout_7);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        Third->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Third);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 540, 20));
        Third->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Third);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Third->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Third);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Third->setStatusBar(statusBar);

        retranslateUi(Third);

        QMetaObject::connectSlotsByName(Third);
    } // setupUi

    void retranslateUi(QMainWindow *Third)
    {
        Third->setWindowTitle(QCoreApplication::translate("Third", "Third", nullptr));
        label_last_name->setText(QCoreApplication::translate("Third", "firstname", nullptr));
        label_first_name->setText(QCoreApplication::translate("Third", "LastName", nullptr));
        label->setText(QCoreApplication::translate("Third", "0/0", nullptr));
        pushButton->setText(QCoreApplication::translate("Third", "<", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Third", ">", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Third", "Edit", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Third", "Save", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Third", "Load", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Third", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Third: public Ui_Third {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRD_H
