#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "dialog.h"
#include "mainview.h"
#include "dialog_deal.h"
#include "session.h"
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
    dialog_deal * deal;
public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void check_user_login(QString data);
    void get_reg_data(int account,QString password,QString email,QString name);
    void check_add_user(QString data);
private slots:

    void on_pushButton_submit_clicked();

    void on_pushButton_login_clicked();
signals:
    void send_user_session(int user_account,QString user_password,QString user_name,QString user_friend,
                           QString user_own_group,QString user_join_group,QString user_email,int user_grant,QTcpSocket *client);
private:
    Ui::MainWindow *ui;
    Dialog f;
    MainView m;
 protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
