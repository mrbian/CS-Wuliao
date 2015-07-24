#include "dialog_addgroup_check.h"
#include "ui_dialog_addgroup_check.h"

dialog_addgroup_check::dialog_addgroup_check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_addgroup_check)
{
    ui->setupUi(this);
    ui->tableWidget_add_group->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_add_group->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->tableWidget_add_friend->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_add_group->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_add_group->setAlternatingRowColors(true);
    setWindowIcon(QIcon(":/1.png"));
}

dialog_addgroup_check::~dialog_addgroup_check()
{
    delete ui;
}

void dialog_addgroup_check::receiveFindGroupData(QString name, QString id){
    if(name == "root" || id == "root"){
        int row_count = ui->tableWidget_add_group->rowCount();
        ui->tableWidget_add_group->insertRow(row_count);
        ui->tableWidget_add_group->setItem(0,0,new QTableWidgetItem(name));
        ui->tableWidget_add_group->setItem(0,1,new QTableWidgetItem(id));
    }
    this->exec();
}


void dialog_addgroup_check::on_pushButton_yes_clicked()
{
    QString name = ui->tableWidget_add_group->item(0,0)->text();
    QString id = ui->tableWidget_add_group->item(0,1)->text();
    this->close();
    emit sendMyGroup(name,id);
}

void dialog_addgroup_check::on_pushButton_cancel_clicked()
{
    this->close();
}
