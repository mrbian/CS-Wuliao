#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QTextCodec>
#include "mainwindow.h"
#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));
    QTextCodec::setCodecForTr( QTextCodec::codecForName( "GB2312"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QDesktopWidget *deskdop = QApplication::desktop();
    MainWindow w;
    w.setFixedSize(475,350);
    w.move((deskdop->width()-w.width())/2,(deskdop->height()-w.height())/2);
    w.show();

    return a.exec();
}
