/********************************************************************************
** Form generated from reading UI file 'dialog_addgroup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ADDGROUP_H
#define UI_DIALOG_ADDGROUP_H

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

class Ui_dialog_addgroup
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_cancel;
    QLineEdit *lineEdit_group_name;
    QLineEdit *lineEdit_group_id;

    void setupUi(QDialog *dialog_addgroup)
    {
        if (dialog_addgroup->objectName().isEmpty())
            dialog_addgroup->setObjectName(QString::fromUtf8("dialog_addgroup"));
        dialog_addgroup->resize(400, 300);
        dialog_addgroup->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        label = new QLabel(dialog_addgroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 51, 41));
        label->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 75 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));
        label_2 = new QLabel(dialog_addgroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 130, 51, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";"));
        pushButton_yes = new QPushButton(dialog_addgroup);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(80, 220, 101, 31));
        pushButton_yes->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(255, 85, 0);"));
        pushButton_cancel = new QPushButton(dialog_addgroup);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(200, 220, 101, 31));
        pushButton_cancel->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        lineEdit_group_name = new QLineEdit(dialog_addgroup);
        lineEdit_group_name->setObjectName(QString::fromUtf8("lineEdit_group_name"));
        lineEdit_group_name->setGeometry(QRect(110, 60, 221, 31));
        lineEdit_group_name->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_group_id = new QLineEdit(dialog_addgroup);
        lineEdit_group_id->setObjectName(QString::fromUtf8("lineEdit_group_id"));
        lineEdit_group_id->setGeometry(QRect(110, 130, 221, 31));
        lineEdit_group_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(dialog_addgroup);

        QMetaObject::connectSlotsByName(dialog_addgroup);
    } // setupUi

    void retranslateUi(QDialog *dialog_addgroup)
    {
        dialog_addgroup->setWindowTitle(QApplication::translate("dialog_addgroup", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialog_addgroup", "\347\276\244\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialog_addgroup", "\347\276\244id\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_yes->setText(QApplication::translate("dialog_addgroup", "\346\237\245\346\211\276", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("dialog_addgroup", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_addgroup: public Ui_dialog_addgroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ADDGROUP_H
