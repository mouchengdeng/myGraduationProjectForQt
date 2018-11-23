/********************************************************************************
** Form generated from reading UI file 'startload.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTLOAD_H
#define UI_STARTLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startLoad
{
public:
    QLabel *startLoadLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *startLoadProgressLabel;
    QProgressBar *progressBar;

    void setupUi(QWidget *startLoad)
    {
        if (startLoad->objectName().isEmpty())
            startLoad->setObjectName(QStringLiteral("startLoad"));
        startLoad->resize(642, 374);
        startLoadLabel = new QLabel(startLoad);
        startLoadLabel->setObjectName(QStringLiteral("startLoadLabel"));
        startLoadLabel->setGeometry(QRect(100, 50, 411, 61));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        startLoadLabel->setFont(font);
        startLoadLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(startLoad);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 260, 521, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startLoadProgressLabel = new QLabel(widget);
        startLoadProgressLabel->setObjectName(QStringLiteral("startLoadProgressLabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        startLoadProgressLabel->setFont(font1);

        horizontalLayout->addWidget(startLoadProgressLabel);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);


        retranslateUi(startLoad);

        QMetaObject::connectSlotsByName(startLoad);
    } // setupUi

    void retranslateUi(QWidget *startLoad)
    {
        startLoad->setWindowTitle(QApplication::translate("startLoad", "Form", 0));
        startLoadLabel->setText(QApplication::translate("startLoad", "\346\231\272\350\203\275\350\275\246\344\275\215\347\263\273\347\273\237\346\255\243\345\234\250\345\220\257\345\212\250...", 0));
        startLoadProgressLabel->setText(QApplication::translate("startLoad", "\345\220\257\345\212\250\350\277\233\345\272\246\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class startLoad: public Ui_startLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTLOAD_H
