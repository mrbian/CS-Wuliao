/********************************************************************************
** Form generated from reading UI file 'dialog_addfriend_check.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDFRIEND_CHECK_H
#define UI_DIALOG_ADDFRIEND_CHECK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_addfriend_check
{
public:
    QPushButton *pushButton_yes;
    QPushButton *pushButton_cancel;
    QTableWidget *tableWidget_add_friend;

    void setupUi(QDialog *dialog_addfriend_check)
    {
        if (dialog_addfriend_check->objectName().isEmpty())
            dialog_addfriend_check->setObjectName(QString::fromUtf8("dialog_addfriend_check"));
        dialog_addfriend_check->resize(440, 261);
        dialog_addfriend_check->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"QTableWidget {\n"
"         selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                     stop: 0 #FF92BB, stop: 1 white);\n"
"     }\n"
"QTableWidget QTableCornerButton::section { \n"
"         background: red;\n"
"         border: 2px outset red;\n"
"     }"));
        pushButton_yes = new QPushButton(dialog_addfriend_check);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(100, 200, 101, 41));
        pushButton_yes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        pushButton_cancel = new QPushButton(dialog_addfriend_check);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(210, 200, 101, 41));
        tableWidget_add_friend = new QTableWidget(dialog_addfriend_check);
        if (tableWidget_add_friend->columnCount() < 2)
            tableWidget_add_friend->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_add_friend->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_add_friend->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_add_friend->setObjectName(QString::fromUtf8("tableWidget_add_friend"));
        tableWidget_add_friend->setGeometry(QRect(100, 10, 231, 181));
        tableWidget_add_friend->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(dialog_addfriend_check);

        QMetaObject::connectSlotsByName(dialog_addfriend_check);
    } // setupUi

    void retranslateUi(QDialog *dialog_addfriend_check)
    {
        dialog_addfriend_check->setWindowTitle(QApplication::translate("dialog_addfriend_check", "\346\227\240\350\201\212\346\235\245\345\212\240\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        pushButton_yes->setText(QApplication::translate("dialog_addfriend_check", "\345\212\240\344\270\272\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("dialog_addfriend_check", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_add_friend->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dialog_addfriend_check", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_add_friend->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dialog_addfriend_check", "id", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_addfriend_check: public Ui_dialog_addfriend_check {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDFRIEND_CHECK_H
