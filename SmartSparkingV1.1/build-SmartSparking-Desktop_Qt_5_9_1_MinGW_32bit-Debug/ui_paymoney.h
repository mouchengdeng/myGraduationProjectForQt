/********************************************************************************
** Form generated from reading UI file 'paymoney.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMONEY_H
#define UI_PAYMONEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_payMoney
{
public:
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *stopTimelineEdit;
    QLabel *label_2;
    QLineEdit *unitPricelineEdit;
    QLabel *label_3;
    QLineEdit *payMoneyLineEdit;

    void setupUi(QWidget *payMoney)
    {
        if (payMoney->objectName().isEmpty())
            payMoney->setObjectName(QStringLiteral("payMoney"));
        payMoney->resize(400, 294);
        okPushButton = new QPushButton(payMoney);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));
        okPushButton->setGeometry(QRect(90, 170, 75, 23));
        cancelPushButton = new QPushButton(payMoney);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(190, 170, 81, 23));
        widget = new QWidget(payMoney);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 70, 201, 74));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        stopTimelineEdit = new QLineEdit(widget);
        stopTimelineEdit->setObjectName(QStringLiteral("stopTimelineEdit"));

        gridLayout->addWidget(stopTimelineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        unitPricelineEdit = new QLineEdit(widget);
        unitPricelineEdit->setObjectName(QStringLiteral("unitPricelineEdit"));

        gridLayout->addWidget(unitPricelineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        payMoneyLineEdit = new QLineEdit(widget);
        payMoneyLineEdit->setObjectName(QStringLiteral("payMoneyLineEdit"));

        gridLayout->addWidget(payMoneyLineEdit, 2, 1, 1, 1);


        retranslateUi(payMoney);

        QMetaObject::connectSlotsByName(payMoney);
    } // setupUi

    void retranslateUi(QWidget *payMoney)
    {
        payMoney->setWindowTitle(QApplication::translate("payMoney", "Form", Q_NULLPTR));
        okPushButton->setText(QApplication::translate("payMoney", "\347\241\256\350\256\244\346\224\257\344\273\230", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("payMoney", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("payMoney", "\345\201\234\350\275\246\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("payMoney", "\345\215\225\344\273\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("payMoney", "\345\272\224\346\224\257\344\273\230\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class payMoney: public Ui_payMoney {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMONEY_H
