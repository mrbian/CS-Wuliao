/********************************************************************************
** Form generated from reading UI file 'dialog_addgroup_check.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDGROUP_CHECK_H
#define UI_DIALOG_ADDGROUP_CHECK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_addgroup_check
{
public:
    QTableWidget *tableWidget_add_group;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_yes;

    void setupUi(QDialog *dialog_addgroup_check)
    {
        if (dialog_addgroup_check->objectName().isEmpty())
            dialog_addgroup_check->setObjectName(QString::fromUtf8("dialog_addgroup_check"));
        dialog_addgroup_check->resize(400, 300);
        dialog_addgroup_check->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"QTableWidget {\n"
"         selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                     stop: 0 #FF92BB, stop: 1 white);\n"
"     }\n"
"QTableWidget QTableCornerButton::section { \n"
"         background: red;\n"
"         border: 2px outset red;\n"
"     }"));
        tableWidget_add_group = new QTableWidget(dialog_addgroup_check);
        if (tableWidget_add_group->columnCount() < 2)
            tableWidget_add_group->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_add_group->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_add_group->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_add_group->setObjectName(QString::fromUtf8("tableWidget_add_group"));
        tableWidget_add_group->setGeometry(QRect(80, 40, 231, 181));
        tableWidget_add_group->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_cancel = new QPushButton(dialog_addgroup_check);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(190, 230, 101, 41));
        pushButton_yes = new QPushButton(dialog_addgroup_check);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(80, 230, 101, 41));
        pushButton_yes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));

        retranslateUi(dialog_addgroup_check);

        QMetaObject::connectSlotsByName(dialog_addgroup_check);
    } // setupUi

    void retranslateUi(QDialog *dialog_addgroup_check)
    {
        dialog_addgroup_check->setWindowTitle(QApplication::translate("dialog_addgroup_check", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_add_group->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dialog_addgroup_check", "\347\276\244\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_add_group->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dialog_addgroup_check", "id", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("dialog_addgroup_check", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_yes->setText(QApplication::translate("dialog_addgroup_check", "\345\212\240\345\205\245\347\276\244\347\273\204", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_addgroup_check: public Ui_dialog_addgroup_check {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDGROUP_CHECK_H
