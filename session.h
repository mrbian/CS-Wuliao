#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include "dialog_deal.h"
class Session : public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = 0);
    int account;
    QString user_password;
    QString user_name;
    QString user_friend;
    QString user_own_group;
    QString user_join_group;
    QString user_email;
    int user_grant;
signals:

public slots:

};

#endif // SESSION_H
