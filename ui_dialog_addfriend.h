/********************************************************************************
** Form generated from reading UI file 'dialog_addfriend.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDFRIEND_H
#define UI_DIALOG_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dialog_addfriend
{
public:
    QLineEdit *lineEdit_friend_name;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_yes;
    QLineEdit *lineEdit_friend_id;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *dialog_addfriend)
    {
        if (dialog_addfriend->objectName().isEmpty())
            dialog_addfriend->setObjectName(QString::fromUtf8("dialog_addfriend"));
        dialog_addfriend->resize(496, 269);
        dialog_addfriend->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        lineEdit_friend_name = new QLineEdit(dialog_addfriend);
        lineEdit_friend_name->setObjectName(QString::fromUtf8("lineEdit_friend_name"));
        lineEdit_friend_name->setGeometry(QRect(180, 50, 211, 31));
        lineEdit_friend_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_cancel = new QPushButton(dialog_addfriend);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(280, 190, 91, 41));
        pushButton_yes = new QPushButton(dialog_addfriend);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(150, 190, 101, 41));
        pushButton_yes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        lineEdit_friend_id = new QLineEdit(dialog_addfriend);
        lineEdit_friend_id->setObjectName(QString::fromUtf8("lineEdit_friend_id"));
        lineEdit_friend_id->setGeometry(QRect(180, 110, 211, 31));
        lineEdit_friend_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(dialog_addfriend);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 121, 31));
        label->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\256\213\344\275\223\";"));
        label_2 = new QLabel(dialog_addfriend);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 110, 131, 31));
        label_2->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 75 12pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(dialog_addfriend);

        QMetaObject::connectSlotsByName(dialog_addfriend);
    } // setupUi

    void retranslateUi(QDialog *dialog_addfriend)
    {
        dialog_addfriend->setWindowTitle(QApplication::translate("dialog_addfriend", "\346\227\240\350\201\212\346\235\245\346\211\276\346\234\213\345\217\213", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("dialog_addfriend", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        pushButton_yes->setText(QApplication::translate("dialog_addfriend", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialog_addfriend", " \346\214\211\346\230\265\347\247\260\346\237\245\346\211\276\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialog_addfriend", "  \346\214\211id\346\237\245\346\211\276\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_addfriend: public Ui_dialog_addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDFRIEND_H
