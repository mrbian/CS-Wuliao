#ifndef DIALOG_DEAL_H
#define DIALOG_DEAL_H

#include <QDialog>
#include <QtNetwork>
namespace Ui {
    class dialog_deal;
}

class dialog_deal : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_deal(QWidget *parent = 0);
    ~dialog_deal();
    QTcpSocket *client;
   bool addUser(QString name,QString password,int account,QString email);
   bool setUserName(int account,QString name);
   bool setPassword(int account,QString newpassword);
   //bool setUserAccount();
   bool userLogin(int account,QString password);
   bool findFriend(int account);
   bool addFriend(int account,int friend_account);
   //7-28个人相关操作已经完成，早上11点开始把有关个人的操作嵌入gui界面(结果一下午全在写文档)
   bool findGroup(int group_account);
   bool joinGroup(int account,int group_account);
   bool createGroup(int account,int group_account,QString group_name,QString group_describe);
   bool setGrant(int account,int grant);
   bool sendSingleMessage(int account,int rev_account,QString message);
   bool sendGroupMessage(int account,int group_account,QString message);
   bool sendChatMessage(QString account_str,QString message);
signals:
     void user_login_done(QString data);
     void add_user_done(QString data);
     void find_friend_done(QString data);
     void add_friend_done(QString data);
     void send_single_message_done(QString data);
     void create_group_done(QString data);
     void send_chat_message(QString data);
     void send_online_user(QString data);
private:
    Ui::dialog_deal *ui;
public slots:
    void readMessage();
    void changeSocket(int);
};

#endif // DIALOG_DEAL_H
