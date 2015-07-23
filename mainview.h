#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QToolButton>
#include <QPixmap>
#include <QStyle>
#include <QMessageBox>
#include "dialog_addfriend.h"
#include "dialog_addfriend_check.h"
namespace Ui {
    class MainView;
}

class MainView : public QDialog
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
    void CreateTrayMenu();
    void CreateTrayIcon();
    QSystemTrayIcon *myTrayIcon;
    QMenu *myMenu;
    QAction *miniSizeAction;
    QAction *maxSizeAction;
    QAction *restoreWinAction;
    QAction *quitAction;

    dialog_addfriend *_find;
    dialog_addfriend_check *_add_friend_check;
signals:
    void sendFriendData(QString,QString);
public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void getMyFriend(QString,QString);
private:
    Ui::MainView *ui;

protected:
   void closeEvent(QCloseEvent *event);
private slots:
   void on_pushButton_clicked();
   void on_pushButton_myfreind_clicked();
   void on_pushButton_mygroup_clicked();
   void receiveFindData(QString,QString);

};

#endif // MAINVIEW_H
