#include "dialog_addfriend.h"
#include "ui_dialog_addfriend.h"

dialog_addfriend::dialog_addfriend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_addfriend)
{
    ui->setupUi(this);
}

dialog_addfriend::~dialog_addfriend()
{
    delete ui;
}

void dialog_addfriend::on_pushButton_yes_clicked()
{
    emit sendFindData(ui->lineEdit_friend_name->text(),ui->lineEdit_friend_id->text());
}
