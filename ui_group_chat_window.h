/********************************************************************************
** Form generated from reading UI file 'group_chat_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_CHAT_WINDOW_H
#define UI_GROUP_CHAT_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_group_chat_window
{
public:
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label;
    QTextEdit *textEdit_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QDialog *group_chat_window)
    {
        if (group_chat_window->objectName().isEmpty())
            group_chat_window->setObjectName(QString::fromUtf8("group_chat_window"));
        group_chat_window->resize(768, 655);
        listWidget = new QListWidget(group_chat_window);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 30, 541, 421));
        textEdit = new QTextEdit(group_chat_window);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 470, 541, 111));
        pushButton = new QPushButton(group_chat_window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 600, 141, 41));
        line = new QFrame(group_chat_window);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 450, 541, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(group_chat_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(590, 10, 131, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        textEdit_2 = new QTextEdit(group_chat_window);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setEnabled(false);
        textEdit_2->setGeometry(QRect(570, 50, 181, 401));
        comboBox = new QComboBox(group_chat_window);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(180, 610, 111, 21));
        comboBox_2 = new QComboBox(group_chat_window);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(310, 610, 111, 22));

        retranslateUi(group_chat_window);

        QMetaObject::connectSlotsByName(group_chat_window);
    } // setupUi

    void retranslateUi(QDialog *group_chat_window)
    {
        group_chat_window->setWindowTitle(QApplication::translate("group_chat_window", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("group_chat_window", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("group_chat_window", "\347\276\244\347\273\204\346\210\220\345\221\230\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("group_chat_window", "Enter\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("group_chat_window", "ctrl+Enter\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("group_chat_window", "14pt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("group_chat_window", "16pt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("group_chat_window", "20pt", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class group_chat_window: public Ui_group_chat_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_CHAT_WINDOW_H
