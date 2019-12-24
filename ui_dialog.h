/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_Dialog
{
public:
    QPushButton *pushButton_reg;
    QLineEdit *lineEdit_account;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_email;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_name;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(438, 322);
        Dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        pushButton_reg = new QPushButton(Dialog);
        pushButton_reg->setObjectName(QString::fromUtf8("pushButton_reg"));
        pushButton_reg->setGeometry(QRect(140, 250, 91, 31));
        pushButton_reg->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));
        lineEdit_account = new QLineEdit(Dialog);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(150, 40, 201, 31));
        lineEdit_account->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_password = new QLineEdit(Dialog);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(150, 90, 201, 31));
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_email = new QLineEdit(Dialog);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(150, 140, 201, 31));
        lineEdit_email->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 250, 91, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        lineEdit_name = new QLineEdit(Dialog);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(150, 190, 201, 31));
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 61, 21));
        label->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"text-align:center;\n"
""));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 90, 54, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"text-align:center;"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 140, 61, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"text-align:center;"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 200, 61, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"text-align:center"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton_reg->setText(QApplication::translate("Dialog", "\346\217\220\344\272\244\346\263\250\345\206\214", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "\350\264\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "\351\202\256\347\256\261\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "\346\230\265\347\247\260\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
