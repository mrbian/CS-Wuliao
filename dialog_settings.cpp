#include "dialog_settings.h"
#include "ui_dialog_settings.h"

dialog_settings::dialog_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_settings)
{
    ui->setupUi(this);
}

dialog_settings::~dialog_settings()
{
    delete ui;
}
