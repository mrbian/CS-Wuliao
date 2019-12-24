/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_chatroom
{
public:
    QTextEdit *textEdit;
    QListWidget *listWidget_chat;
    QPushButton *pushButton;
    QLabel *label_2;
    QListWidget *listWidget_member;
    QLabel *label;

    void setupUi(QDialog *chatroom)
    {
        if (chatroom->objectName().isEmpty())
            chatroom->setObjectName(QString::fromUtf8("chatroom"));
        chatroom->resize(756, 648);
        chatroom->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        textEdit = new QTextEdit(chatroom);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 540, 521, 81));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        listWidget_chat = new QListWidget(chatroom);
        listWidget_chat->setObjectName(QString::fromUtf8("listWidget_chat"));
        listWidget_chat->setGeometry(QRect(30, 80, 521, 441));
        listWidget_chat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 18pt \"Adobe Arabic\";"));
        pushButton = new QPushButton(chatroom);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 540, 171, 81));
        pushButton->setStyleSheet(QString::fromUtf8("font: 16pt \"Adobe Arabic\";\n"
"background-color: rgb(255, 170, 0);"));
        label_2 = new QLabel(chatroom);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 20, 181, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 16pt \"Adobe Arabic\";"));
        listWidget_member = new QListWidget(chatroom);
        listWidget_member->setObjectName(QString::fromUtf8("listWidget_member"));
        listWidget_member->setGeometry(QRect(575, 80, 171, 441));
        listWidget_member->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(chatroom);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 10, 361, 51));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 16pt \"Adobe Arabic\";"));

        retranslateUi(chatroom);

        QMetaObject::connectSlotsByName(chatroom);
    } // setupUi

    void retranslateUi(QDialog *chatroom)
    {
        chatroom->setWindowTitle(QApplication::translate("chatroom", "\346\227\240\350\201\212", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("chatroom", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("chatroom", "\345\234\250\347\272\277\350\264\246\345\217\267\345\210\227\350\241\250\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("chatroom", "\346\211\200\346\234\211\344\275\277\347\224\250\350\200\205\347\232\204\350\201\212\345\244\251\345\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class chatroom: public Ui_chatroom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
