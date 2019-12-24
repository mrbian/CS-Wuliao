/********************************************************************************
** Form generated from reading UI file 'dialog_creategroup.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CREATEGROUP_H
#define UI_DIALOG_CREATEGROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_dialog_creategroup
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_group_name;
    QTextEdit *textEdit_describe;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_account;

    void setupUi(QDialog *dialog_creategroup)
    {
        if (dialog_creategroup->objectName().isEmpty())
            dialog_creategroup->setObjectName(QString::fromUtf8("dialog_creategroup"));
        dialog_creategroup->resize(689, 313);
        pushButton = new QPushButton(dialog_creategroup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 250, 101, 41));
        pushButton_2 = new QPushButton(dialog_creategroup);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 250, 101, 41));
        lineEdit_group_name = new QLineEdit(dialog_creategroup);
        lineEdit_group_name->setObjectName(QString::fromUtf8("lineEdit_group_name"));
        lineEdit_group_name->setGeometry(QRect(90, 80, 201, 41));
        textEdit_describe = new QTextEdit(dialog_creategroup);
        textEdit_describe->setObjectName(QString::fromUtf8("textEdit_describe"));
        textEdit_describe->setGeometry(QRect(380, 50, 271, 211));
        label = new QLabel(dialog_creategroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 61, 31));
        label_2 = new QLabel(dialog_creategroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 170, 54, 31));
        label_3 = new QLabel(dialog_creategroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 20, 91, 21));
        lineEdit_account = new QLineEdit(dialog_creategroup);
        lineEdit_account->setObjectName(QString::fromUtf8("lineEdit_account"));
        lineEdit_account->setGeometry(QRect(90, 170, 201, 41));

        retranslateUi(dialog_creategroup);

        QMetaObject::connectSlotsByName(dialog_creategroup);
    } // setupUi

    void retranslateUi(QDialog *dialog_creategroup)
    {
        dialog_creategroup->setWindowTitle(QApplication::translate("dialog_creategroup", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dialog_creategroup", "\345\210\233\345\273\272", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("dialog_creategroup", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dialog_creategroup", "\347\276\244\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dialog_creategroup", "\347\276\244id\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dialog_creategroup", "\344\275\240\345\257\271\346\255\244\347\276\244\347\232\204\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_creategroup: public Ui_dialog_creategroup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CREATEGROUP_H
