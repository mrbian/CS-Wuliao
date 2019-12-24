#include "dialog_deal.h"
#include "ui_dialog_deal.h"

dialog_deal::dialog_deal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_deal)
{
    ui->setupUi(this);
    client = new QTcpSocket();
    client->connectToHost(QHostAddress("127.0.0.1"),5000);
    QObject::connect(client,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

dialog_deal::~dialog_deal()
{
    delete ui;
}

bool dialog_deal::addUser(QString name,QString password,int account,QString email){                //0
    QString type = "add_user";                                  //定义消息类型
    QString account_str;
    account_str.setNum(account);                                //将account转换成int
    QString temp_data =type +'-'+ name + "-" + password + "-" + account_str +'-' +email;    //组合消息使用-连接
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool dialog_deal::setUserName(int account,QString name){                                       //1
    QString type = "set_user_name";
    QString account_str;
    account_str.setNum(account);                                //将account转换成int
    QString temp_data =type +'-'+account_str+'-'+name;    //组合消息使用-连接
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool dialog_deal::setPassword(int account,QString newpassword){                                //2
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

bool dialog_deal::userLogin(int account, QString password){                            //3
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

bool dialog_deal::findFriend(int account){                                                 //4
    QString type = "find_friend";
    QString account_str;
    account_str.setNum(account);
    QString temp_data = type + '-'
                +account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool dialog_deal::findGroup(int group_account){                                        //5
    QString type = "find_group";
    QString group_account_str;
    group_account_str.setNum(group_account);
    QString temp_data = type +'-'
            +group_account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool dialog_deal::createGroup(int account, int group_account ,QString group_name,QString group_describe){                         //6
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

bool dialog_deal::joinGroup(int account, int group_account){                          //7
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



bool dialog_deal::addFriend(int account,int friend_account){                       //8
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

bool dialog_deal::setGrant(int account,int grant){                                    //9
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


bool dialog_deal::sendSingleMessage(int account, int rev_account,QString message){         //10
    QString type = "send_single_message";
    QString account_str,rev_account_str;
    account_str.setNum(account);
    rev_account_str.setNum(rev_account);
    QString temp_data = type +'-'
            +account_str +'-'
            +rev_account_str +'-'
            +message;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
    return true;
}

bool dialog_deal::sendGroupMessage(int account, int group_account,QString message){        //11
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

bool dialog_deal::sendChatMessage(QString account_str, QString message){
    QString type = "send_chat_message";
    QString temp_data = type + '-'
            +account_str +'-'
            +message;
    QByteArray data = temp_data.toAscii();
    client->write(data);
    return true;
}

void dialog_deal::readMessage(){
    QByteArray _data;
    _data = this->client->readAll();  //接受消息
    QString data;
    data.prepend(_data);
    QStringList datalist;
    if(data.indexOf("|") == -1)
        datalist = data.split('-');  //对消息分组,如果不是user_login或者give_user_online消息（user_login需要传递session所有的群组消息）
    else
        datalist = data.split('|');
    QString type= datalist[0];
    QString result = datalist[1];
    QString datacontent;
    if(type == "add_user"){                 //0
        emit add_user_done(data);
    }


    else if(type == "set_name"){            //1

    }



    else if(type == "set_password"){        //2

    }



    else if(type == "user_login"){          //3
        emit user_login_done(data);
    }


    else if(type == "find_friend"){         //4
        emit find_friend_done(data);
    }


    else if(type == "add_friend"){          //5
        emit add_friend_done(data);
    }



    else if(type == "set_grant"){           //6

    }


    else if(type == "user_join_group"){          //7

    }



    else if(type == "user_create_group"){        //8
        emit create_group_done(data);
    }



    else if(type == "find_group"){          //9

    }


    else if(type == "send_single_message"){     //10
        emit send_single_message_done(data);
    }


    else if(type == "send_group_message"){        //11

    }

    else if(type == "send_chat_message"){
        emit send_chat_message(data);
    }

    else if(type == "give_online_user"){
        emit send_online_user(data);
    }
}

void dialog_deal::changeSocket(int account){
    QString type = "inform";
    QString account_str;
    account_str.setNum(account);
    QString temp_data = type +'-'
            +account_str;
    QByteArray data = temp_data.toLatin1();
    client->write(data);
}
