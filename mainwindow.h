#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "dialog.h"
#include "mainview.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); 
    void CreateTrayMenu();
    void CreateTrayIcon();
    QSystemTrayIcon *myTrayIcon;
    QMenu *myMenu;
    QAction *miniSizeAction;
    QAction *maxSizeAction;
    QAction *restoreWinAction;
    QAction *quitAction;

public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
private slots:

    void on_pushButton_submit_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    Dialog f;
    MainView m;
 protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
