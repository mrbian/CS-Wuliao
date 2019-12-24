#include "chatroom.h"
#include "ui_chatroom.h"

chatroom::chatroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatroom)
{
    ui->setupUi(this);
}

chatroom::~chatroom()
{
    delete ui;
}

void chatroom::getMessage(QString data){
    this->show();           //×Ô¶¯µ¯³ö
    QStringList datalist = data.split('-');
    QString send_account_str = datalist[1];
    QString message = datalist[2];
    if(send_account_str != account_str){
        date = QDateTime::currentDateTime().toString("yyyy-mm-dd  hh:mm:ss");
        QString str = send_account_str +"          "+date;
        this->ui->listWidget_chat->addItem(str);
        this->ui->listWidget_chat->addItem(message);
    }
    this->ui->textEdit->clear();
}

void chatroom::on_pushButton_clicked()
{
    message = this->ui->textEdit->toPlainText();
    date = QDateTime::currentDateTime().toString("yyyy-mm-dd  hh:mm:ss");
    QString str = account_str +"          "+date;
    this->ui->listWidget_chat->addItem(str);
    this->ui->listWidget_chat->addItem(message);
    emit sendMessage(account_str,message);
    this->ui->textEdit->clear();
}

void chatroom::get_online_user(QString data){
    QStringList datalist = data.split('|');
    QString users = datalist[2];
    QStringList userlist = users.split('-');
    this->ui->listWidget_member->clear();
    for(int i =0;i<userlist.length();i++){
        QString members = "ÕËºÅid£º" + userlist[i];
        this->ui->listWidget_member->insertItem(i,members);
    }
}
