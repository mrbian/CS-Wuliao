/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QFrame *line;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_myfreind;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_friend;
    QPushButton *pushButton_mygroup;
    QTableWidget *tableWidget_group;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_addgroup;
    QPushButton *pushButton_creategroup;
    QPushButton *pushButton_settings;
    QPushButton *pushButton_chatroom;

    void setupUi(QDialog *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QString::fromUtf8("MainView"));
        MainView->setEnabled(true);
        MainView->resize(377, 587);
        MainView->setAcceptDrops(true);
        MainView->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"         selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                     stop: 0 #FF92BB, stop: 1 white);\n"
"     }\n"
"QTableWidget QTableCornerButton::section { \n"
"         background: red;\n"
"         border: 2px outset red;\n"
"     }"));
        line = new QFrame(MainView);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(160, 670, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(MainView);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 381, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
"background-color: rgb(0, 255, 255);"));

        verticalLayout->addWidget(label);

        verticalLayoutWidget_2 = new QWidget(MainView);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 50, 381, 43));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_myfreind = new QPushButton(verticalLayoutWidget_2);
        pushButton_myfreind->setObjectName(QString::fromUtf8("pushButton_myfreind"));
        pushButton_myfreind->setMinimumSize(QSize(181, 41));
        pushButton_myfreind->setStyleSheet(QString::fromUtf8("text-align:left;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));

        verticalLayout_2->addWidget(pushButton_myfreind);

        verticalLayoutWidget_4 = new QWidget(MainView);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 92, 381, 254));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableWidget_friend = new QTableWidget(verticalLayoutWidget_4);
        if (tableWidget_friend->columnCount() < 2)
            tableWidget_friend->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_friend->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_friend->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_friend->setObjectName(QString::fromUtf8("tableWidget_friend"));
        tableWidget_friend->setStyleSheet(QString::fromUtf8(" QTableWidget {\n"
"         selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                     stop: 0 #FF92BB, stop: 1 white);\n"
"     }\n"
"QTableWidget QTableCornerButton::section { \n"
"         background: red;\n"
"         border: 2px outset red;\n"
"     }"));

        verticalLayout_4->addWidget(tableWidget_friend);

        pushButton_mygroup = new QPushButton(verticalLayoutWidget_4);
        pushButton_mygroup->setObjectName(QString::fromUtf8("pushButton_mygroup"));
        pushButton_mygroup->setMinimumSize(QSize(0, 41));
        pushButton_mygroup->setStyleSheet(QString::fromUtf8("text-align:left;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));

        verticalLayout_4->addWidget(pushButton_mygroup);

        tableWidget_group = new QTableWidget(verticalLayoutWidget_4);
        if (tableWidget_group->columnCount() < 2)
            tableWidget_group->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_group->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_group->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_group->setObjectName(QString::fromUtf8("tableWidget_group"));
        tableWidget_group->setStyleSheet(QString::fromUtf8(" QTableWidget {\n"
"         selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,\n"
"                                     stop: 0 #FF92BB, stop: 1 white);\n"
"     }\n"
"QTableWidget QTableCornerButton::section { \n"
"         background: red;\n"
"         border: 2px outset red;\n"
"     }"));

        verticalLayout_4->addWidget(tableWidget_group);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        pushButton = new QPushButton(MainView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 400, 181, 41));
        pushButton->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));
        pushButton_addgroup = new QPushButton(MainView);
        pushButton_addgroup->setObjectName(QString::fromUtf8("pushButton_addgroup"));
        pushButton_addgroup->setGeometry(QRect(180, 400, 201, 41));
        pushButton_addgroup->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));
        pushButton_creategroup = new QPushButton(MainView);
        pushButton_creategroup->setObjectName(QString::fromUtf8("pushButton_creategroup"));
        pushButton_creategroup->setGeometry(QRect(0, 440, 181, 41));
        pushButton_creategroup->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));
        pushButton_settings = new QPushButton(MainView);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));
        pushButton_settings->setGeometry(QRect(180, 440, 201, 41));
        pushButton_settings->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));
        pushButton_chatroom = new QPushButton(MainView);
        pushButton_chatroom->setObjectName(QString::fromUtf8("pushButton_chatroom"));
        pushButton_chatroom->setGeometry(QRect(0, 480, 181, 51));
        pushButton_chatroom->setStyleSheet(QString::fromUtf8("text-align:center;\n"
"font: 14pt \"\345\256\213\344\275\223\";\n"
"background-color: rgb(85, 170, 255);"));

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QDialog *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "\346\227\240\350\201\212\346\235\245\350\201\212\345\244\251", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainView", "\344\275\240\345\245\275\357\274\214\345\215\236\347\225\231\345\277\265", 0, QApplication::UnicodeUTF8));
        pushButton_myfreind->setText(QApplication::translate("MainView", "\346\210\221\347\232\204\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_friend->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainView", "\346\230\265\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_friend->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainView", "id", 0, QApplication::UnicodeUTF8));
        pushButton_mygroup->setText(QApplication::translate("MainView", "\346\210\221\347\232\204\347\276\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_group->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainView", "\347\273\204\345\220\215", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_group->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainView", "id", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainView", "\346\267\273\345\212\240\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        pushButton_addgroup->setText(QApplication::translate("MainView", "\345\212\240\345\205\245\347\276\244\347\273\204", 0, QApplication::UnicodeUTF8));
        pushButton_creategroup->setText(QApplication::translate("MainView", "\345\210\233\345\273\272\347\276\244\347\273\204", 0, QApplication::UnicodeUTF8));
        pushButton_settings->setText(QApplication::translate("MainView", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_chatroom->setText(QApplication::translate("MainView", "\350\201\212\345\244\251\345\256\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
