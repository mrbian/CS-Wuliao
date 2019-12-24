/********************************************************************************
** Form generated from reading UI file 'dialog_deal.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_DEAL_H
#define UI_DIALOG_DEAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_dialog_deal
{
public:
    QLabel *label;

    void setupUi(QDialog *dialog_deal)
    {
        if (dialog_deal->objectName().isEmpty())
            dialog_deal->setObjectName(QString::fromUtf8("dialog_deal"));
        dialog_deal->resize(406, 332);
        label = new QLabel(dialog_deal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 110, 141, 81));

        retranslateUi(dialog_deal);

        QMetaObject::connectSlotsByName(dialog_deal);
    } // setupUi

    void retranslateUi(QDialog *dialog_deal)
    {
        dialog_deal->setWindowTitle(QApplication::translate("dialog_deal", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialog_deal", "\344\270\212\344\274\240\346\225\260\346\215\256\344\270\255...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_deal: public Ui_dialog_deal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_DEAL_H
