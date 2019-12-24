#include "single_chat_window.h"
#include "ui_single_chat_window.h"

single_chat_window::single_chat_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::single_chat_window)
{
    ui->setupUi(this);
}

single_chat_window::~single_chat_window()
{
    delete ui;
}


void single_chat_window::on_pushButton_clicked()
{
    QString message = this->ui->textEdit->toPlainText();
    QString str;
    date = QDateTime::currentDateTime().toString("yyyy-mm-dd  hh:mm:ss");
    str = date +"          "+ friend_account;
    this->ui->listWidget->addItem(this->user_account);
    this->ui->listWidget->addItem(message);
    this->ui->textEdit->clear();
    emit this->send_single_message(this->user_account.toInt(),this->friend_account.toInt(),message);
}

void single_chat_window::get_single_message(QString message){
    QString str;
    date = QDateTime::currentDateTime().toString("yyyy-mm-dd  hh:mm:ss");
    str = date +"          "+ friend_account;
    this->ui->listWidget->addItem(this->friend_account);
    this->ui->listWidget->addItem(message);
}

void single_chat_window::get_show_done(){
    this->ui->listWidget_2->addItem("ÕËºÅ:");
    this->ui->listWidget_2->addItem(this->friend_account);
    this->ui->listWidget_2->addItem("ÓÊÏä:");
    this->ui->listWidget_2->addItem(this->friend_email);
}
