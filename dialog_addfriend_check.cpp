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

void dialog_addfriend_check::receiveFindData(QString name, QString id){
    if(name == "root" || id == "root"){
        int row_count = ui->tableWidget_add_friend->rowCount();
        ui->tableWidget_add_friend->insertRow(row_count);
        ui->tableWidget_add_friend->setItem(0,0,new QTableWidgetItem(name));
        ui->tableWidget_add_friend->setItem(0,1,new QTableWidgetItem(id));
    }
    this->exec();
}

void dialog_addfriend_check::on_pushButton_yes_clicked()
{
    QString name = ui->tableWidget_add_friend->item(0,0)->text();
    QString id = ui->tableWidget_add_friend->item(0,1)->text();
    this->close();
    emit sendMyFriend(name,id);
}


void dialog_addfriend_check::on_pushButton_cancel_clicked()
{
    this->close();
}
