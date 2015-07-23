#include "dialog_addgroup.h"
#include "ui_dialog_addgroup.h"

dialog_addgroup::dialog_addgroup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_addgroup)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/1.png"));
}

dialog_addgroup::~dialog_addgroup()
{
    delete ui;
}

void dialog_addgroup::on_pushButton_yes_clicked()
{
    this->close();
    emit sendFindGroupData(ui->lineEdit_group_name->text(),ui->lineEdit_group_id->text());
}

void dialog_addgroup::on_pushButton_cancel_clicked()
{
    this->close();
}
