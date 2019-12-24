/********************************************************************************
** Form generated from reading UI file 'single_chat_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLE_CHAT_WINDOW_H
#define UI_SINGLE_CHAT_WINDOW_H

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

class Ui_single_chat_window
{
public:
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QFrame *line;
    QComboBox *comboBox;
    QLabel *label;
    QComboBox *comboBox_2;
    QListWidget *listWidget_2;

    void setupUi(QDialog *single_chat_window)
    {
        if (single_chat_window->objectName().isEmpty())
            single_chat_window->setObjectName(QString::fromUtf8("single_chat_window"));
        single_chat_window->resize(739, 643);
        single_chat_window->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));
        listWidget = new QListWidget(single_chat_window);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 511, 411));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        textEdit = new QTextEdit(single_chat_window);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 460, 511, 111));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(single_chat_window);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 590, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);\n"
"color: rgb(255, 170, 0);"));
        line = new QFrame(single_chat_window);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 440, 531, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        comboBox = new QComboBox(single_chat_window);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(180, 600, 101, 22));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 0);"));
        label = new QLabel(single_chat_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 0, 121, 41));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        comboBox_2 = new QComboBox(single_chat_window);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(300, 600, 74, 22));
        listWidget_2 = new QListWidget(single_chat_window);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(570, 40, 151, 251));
        listWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(single_chat_window);

        QMetaObject::connectSlotsByName(single_chat_window);
    } // setupUi

    void retranslateUi(QDialog *single_chat_window)
    {
        single_chat_window->setWindowTitle(QApplication::translate("single_chat_window", "\345\215\225\344\272\272\350\201\212\345\244\251", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("single_chat_window", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("single_chat_window", "Enter\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("single_chat_window", "ctrl+Enter\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("single_chat_window", "\345\257\271\346\226\271\350\265\204\346\226\231", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("single_chat_window", "14pt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("single_chat_window", "16pt", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("single_chat_window", "20pt", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class single_chat_window: public Ui_single_chat_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLE_CHAT_WINDOW_H
