#include "dialog_addfriend_check.h"
#include "ui_dialog_addfriend_check.h"

dialog_addfriend_check::dialog_addfriend_check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_addfriend_check)
{
    ui->setupUi(this);
    ui->tableWidget_add_friend->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_add_friend->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->tableWidget_add_friend->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_add_friend->setAlternatingRowColors(true);
    ui->tableWidget_add_friend->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setWindowIcon(QIcon(":/1.png"));
}

dialog_addfriend_check::~dialog_addfriend_check()
{
    delete ui;
}

void dialog_addfriend_check::receiveFindData(QString data){
    QStringList datalist = data.split("-");
    QString result = datalist[1];
    if(result == "success"){
        QString friend_name = datalist[2];
        QString friend_account_str = datalist[3];
        int row_count = ui->tableWidget_add_friend->rowCount();
        ui->tableWidget_add_friend->insertRow(row_count);
        ui->tableWidget_add_friend->setItem(0,0,new QTableWidgetItem(friend_name));
        ui->tableWidget_add_friend->setItem(0,1,new QTableWidgetItem(friend_account_str));
        this->exec();
    }else if(result == "fail"){
        QMessageBox::about(this->parentWidget(),tr("sorry"),tr("没有此用户"));
    }
}

void dialog_addfriend_check::on_pushButton_yes_clicked()
{
    QString friend_account = ui->tableWidget_add_friend->item(0,1)->text();
    this->ui->tableWidget_add_friend->removeRow(0);
    this->close();
    emit sendMyFriend(friend_account);
}


void dialog_addfriend_check::on_pushButton_cancel_clicked()
{
    this->close();
}
