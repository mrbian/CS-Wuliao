#include "dialog_creategroup.h"
#include "ui_dialog_creategroup.h"

dialog_creategroup::dialog_creategroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_creategroup)
{
    ui->setupUi(this);
}

dialog_creategroup::~dialog_creategroup()
{
    delete ui;
}

void dialog_creategroup::on_pushButton_2_clicked()
{
    this->close();
}

void dialog_creategroup::on_pushButton_clicked()
{
    QString group_name = this->ui->lineEdit_account->text();
    QString group_account = this->ui->lineEdit_group_name->text();
    QString group_describe = this->ui->textEdit_describe->toPlainText();
    emit send_createGroup(group_name,group_account,group_describe);
}

void dialog_creategroup::check_create_group(QString data){
    QStringList datalist = data.split('-');
    QString result = datalist[1];
    if(result == "success"){
        QMessageBox::about(this,tr("�ɹ�"),tr("�����Լ���Ⱥ��"));
        this->close();
        emit create_done(datalist[2]);
    }else if(result == "fail"){
        if(datalist[3] == "already_have"){
            QMessageBox::about(this,tr("fail"),tr("��Ⱥ���Ѿ�����"));
        }else if(datalist[3] == "already_own"){
            QMessageBox::about(this,tr("fail"),tr("���Ѿ��и�Ⱥ��"));
        }
    }
}
