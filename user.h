#ifndef USER_H
#define USER_H

#include <QObject>
#include <QtNetwork>


//���ͷ�ļ���ʱ����,������dialog_deal����
class User : public QObject
{
    Q_OBJECT
public:
     QTcpSocket *client;
    explicit User(QObject *parent = 0);
    bool addUser(QString name,QString password,int account,QString email);
    bool setUserName(int account,QString name);
    bool setPassword(int account,QString newpassword);
    //bool setUserAccount();
    bool userLogin(int account,QString password);
    bool findFriend(int account);
    bool addFriend(int account,int friend_account);
    //7-28������ز����Ѿ���ɣ�����11�㿪ʼ���йظ��˵Ĳ���Ƕ��gui����(���һ����ȫ��д�ĵ�)
    bool findGroup(int group_account);
    bool joinGroup(int account,int group_account);
    bool createGroup(int account,int group_account,QString group_name,QString group_describe);
    bool setGrant(int account,int grant);
    bool sendSingleMessage(int account,int rev_account,QString message);
    bool sendGroupMessage(int account,int group_account,QString message);
signals:
    void user_login_done(QString data);
public slots:
    void readMessage();
};

#endif // USER_H
