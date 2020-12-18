/********************************************************************************
** Form generated from reading UI file 'systemcheck.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMCHECK_H
#define UI_SYSTEMCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemCheck
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SystemCheck)
    {
        if (SystemCheck->objectName().isEmpty())
            SystemCheck->setObjectName(QStringLiteral("SystemCheck"));
        SystemCheck->resize(800, 600);
        centralwidget = new QWidget(SystemCheck);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SystemCheck->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SystemCheck);
        menubar->setObjectName(QStringLiteral("menubar"));
        SystemCheck->setMenuBar(menubar);
        statusbar = new QStatusBar(SystemCheck);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SystemCheck->setStatusBar(statusbar);

        retranslateUi(SystemCheck);

        QMetaObject::connectSlotsByName(SystemCheck);
    } // setupUi

    void retranslateUi(QMainWindow *SystemCheck)
    {
        SystemCheck->setWindowTitle(QApplication::translate("SystemCheck", "SystemCheck", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemCheck: public Ui_SystemCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMCHECK_H
