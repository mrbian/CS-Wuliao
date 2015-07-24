#include "group_chat_window.h"
#include "ui_group_chat_window.h"

group_chat_window::group_chat_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::group_chat_window)
{
    ui->setupUi(this);
}

group_chat_window::~group_chat_window()
{
    delete ui;
}
