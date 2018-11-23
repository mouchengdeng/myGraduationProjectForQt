/********************************************************************************
** Form generated from reading UI file 'startshow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSHOW_H
#define UI_STARTSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startShow
{
public:
    QLabel *startShowLabel;

    void setupUi(QWidget *startShow)
    {
        if (startShow->objectName().isEmpty())
            startShow->setObjectName(QStringLiteral("startShow"));
        startShow->resize(400, 300);
        startShowLabel = new QLabel(startShow);
        startShowLabel->setObjectName(QStringLiteral("startShowLabel"));
        startShowLabel->setGeometry(QRect(60, 130, 231, 101));

        retranslateUi(startShow);

        QMetaObject::connectSlotsByName(startShow);
    } // setupUi

    void retranslateUi(QWidget *startShow)
    {
        startShow->setWindowTitle(QApplication::translate("startShow", "Form", Q_NULLPTR));
        startShowLabel->setText(QApplication::translate("startShow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class startShow: public Ui_startShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSHOW_H
