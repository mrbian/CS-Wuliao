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
#include <QModelIndex>
#include "dialog_addfriend.h"
#include "dialog_addfriend_check.h"
#include "dialog_addgroup.h"
#include "dialog_addgroup_check.h"
#include "dialog_creategroup.h"
#include "dialog_settings.h"
#include "single_chat_window.h"
#include "group_chat_window.h"
#include "session.h"
#include "dialog_deal.h"
#include "chatroom.h"
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
    QTcpSocket *client;
    dialog_deal *deal;
    dialog_addfriend *_find;
    dialog_addfriend_check *_add_friend_check;
    dialog_addgroup * _find_group;
    dialog_addgroup_check *_add_group_check;
    dialog_creategroup *_creategroup;
    dialog_settings *_settings;
    single_chat_window *_single_chat;
    group_chat_window * _group_chat;
    chatroom * room;
    int single_chat_length;
    int group_chat_length;
    int single_chat_id;
    Session session;
public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void getMyFriend(QString);
    void getMyGroup(QString,QString);
    void get_user_session(int user_account,QString user_password,QString user_name,QString user_friend,
                          QString user_own_group,QString user_join_group,QString user_email,int user_grant);
    void receiveFindData(int friend_account);
    void receiveAddFriendData(QString data);
    void sendSingleMessage(int account,int friend_account,QString message);
    void check_single_message(QString);
    void getCreateMessage(QString,QString,QString);
    void create_done(QString);
    void send_message(QString,QString);
private:
    Ui::MainView *ui;
signals:
    void change_socket(int account);
    void single_show();
    void sendToChatWindow(QString message);
protected:
   void closeEvent(QCloseEvent *event);
private slots:
   void on_pushButton_clicked();
   void on_pushButton_myfreind_clicked();
   void on_pushButton_mygroup_clicked();
   void on_pushButton_addgroup_clicked();
   void on_tableWidget_friend_doubleClicked(const QModelIndex &index);
   void on_tableWidget_group_doubleClicked(const QModelIndex &index);
   void on_pushButton_creategroup_clicked();
   void on_pushButton_settings_clicked();
   void on_pushButton_chatroom_clicked();
};

#endif // MAINVIEW_H
