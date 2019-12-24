#include "user.h"

User::User(QObject *parent) :
    QObject(parent)
{
    client = new QTcpSocket();
    client->connectToHost(QHostAddress("127.0.0.1"),5000);
    QObject::connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

bool User::addUser(QString name,QString password,int account,QString email){                //0
    QString type = "add_user";                                  //定义消息类型
    QString account_str;
    account_str.setNum(account);                                //将account转换成int
    QString temp_data =type +'-'+ name + "-" + password + "-" + account_str +'-' +email;    //组合消息使用-连接
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::setUserName(int account,QString name){                                       //1
    QString type = "set_user_name";
    QString account_str;
    account_str.setNum(account);                                //将account转换成int
    QString temp_data =type +'-'+account_str+'-'+name;    //组合消息使用-连接
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::setPassword(int account,QString newpassword){                                //2
    QString type = "set_user_password";
    QString account_str;
    account_str.setNum(account);
    QString temp_data = type + '-'
                        +account_str+'-'
                        +newpassword;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::userLogin(int account, QString password){                            //3
    QString type = "user_login";
    QString account_str;
    account_str.setNum(account);
    QString temp_data = type +'-'
            +account_str +'-'
            +password +'-';
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::findFriend(int account){                                                 //4
    QString type = "find_friend";
    QString account_str;
    account_str.setNum(account);
    QString temp_data = type + '-'
                +account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;

}

bool User::findGroup(int group_account){                                        //5
    QString type = "find_group";
    QString group_account_str;
    group_account_str.setNum(group_account);
    QString temp_data = type +'-'
            +group_account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::createGroup(int account, int group_account ,QString group_name,QString group_describe){                         //6
    QString type = "create_group";
    QString account_str,group_account_str;
    account_str.setNum(account);
    group_account_str.setNum(group_account);
    QString temp_data = type + '-'
            +account_str + '-'
            +group_account_str +'-'
            +group_name +'-'
            +group_describe;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::joinGroup(int account, int group_account){                          //7
    QString type = "join_group";
    QString account_str,group_account_str;
    account_str.setNum(account);
    group_account_str.setNum(group_account);
    QString temp_data = type+ '-'
            +account_str +'-'
            +group_account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}



bool User::addFriend(int account,int friend_account){                       //8
    QString type = "add_friend";
    QString account_str;
    QString friend_account_str;
    account_str.setNum(account);
    friend_account_str.setNum(friend_account);
    QString temp_data = type + '-'
            +account_str + '-'
            +friend_account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::setGrant(int account,int grant){                                    //9
    QString type = "set_grant";
    QString account_str;
    QString grant_str;
    account_str.setNum(account);
    grant_str.setNum(grant);
    QString temp_data = type + '-'
            +account_str +'-'
            +grant_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}


bool User::sendSingleMessage(int account, int rev_account,QString message){         //10
    QString type = "send_single_message";
    QString account_str,rev_account_str;
    account_str.setNum(account);
    rev_account_str.setNum(rev_account);
    QString temp_data = type +'-'
            +account_str +'-'
            +rev_account +'-'
            +message;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool User::sendGroupMessage(int account, int group_account,QString message){        //11
    QString type = "send_group_message";
    QString account_str,group_account_str;
    account_str.setNum(account);
    group_account_str.setNum(group_account);
    QString temp_data = type +'-'
            +account_str + '-'
            +group_account_str +'-'
            +message;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

void User::readMessage(){
    QByteArray _data;
    _data = this->client->readAll();  //接受消息
    QString data;
    data.prepend(_data);
    QStringList datalist = data.split('-');  //对消息分组

    QString type= datalist[0];
    QString result = datalist[1];
    QString datacontent;
    if(type == "add_user"){                 //0

    }


    else if(type == "set_name"){            //1

    }



    else if(type == "set_password"){        //2

    }



    else if(type == "user_login"){          //3
        emit user_login_done(data);
    }


    else if(type == "find_friend"){         //4

    }


    else if(type == "add_friend"){          //5

    }



    else if(type == "set_grant"){           //6

    }


    else if(type == "user_join_group"){          //7

    }



    else if(type == "user_create_group"){        //8

    }



    else if(type == "find_group"){          //9

    }


    else if(type == "send_single_message"){     //10

    }


    else if(result == "send_group_message"){        //11
    }
}
