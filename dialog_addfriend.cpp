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
