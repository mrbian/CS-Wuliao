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
