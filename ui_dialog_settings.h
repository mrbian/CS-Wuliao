/********************************************************************************
** Form generated from reading UI file 'dialog_settings.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SETTINGS_H
#define UI_DIALOG_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_dialog_settings
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QFrame *line;

    void setupUi(QDialog *dialog_settings)
    {
        if (dialog_settings->objectName().isEmpty())
            dialog_settings->setObjectName(QString::fromUtf8("dialog_settings"));
        dialog_settings->resize(400, 559);
        pushButton = new QPushButton(dialog_settings);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 490, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        pushButton_2 = new QPushButton(dialog_settings);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 490, 121, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";"));
        groupBox = new QGroupBox(dialog_settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 130, 401, 291));
        groupBox->setFlat(true);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(60, 0, 251, 81));
        radioButton->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(60, 200, 261, 61));
        radioButton_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(60, 120, 261, 41));
        radioButton_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        line = new QFrame(dialog_settings);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 410, 401, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(dialog_settings);

        QMetaObject::connectSlotsByName(dialog_settings);
    } // setupUi

    void retranslateUi(QDialog *dialog_settings)
    {
        dialog_settings->setWindowTitle(QApplication::translate("dialog_settings", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dialog_settings", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("dialog_settings", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        radioButton->setText(QApplication::translate("dialog_settings", "\344\273\273\344\275\225\344\272\272\351\203\275\350\203\275\345\212\240\346\210\221\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("dialog_settings", "\345\212\240\346\210\221\345\245\275\345\217\213\351\234\200\350\246\201\351\252\214\350\257\201", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("dialog_settings", "\344\273\273\344\275\225\344\272\272\351\203\275\344\270\215\350\203\275\345\212\240\346\210\221\345\245\275\345\217\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dialog_settings: public Ui_dialog_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SETTINGS_H
