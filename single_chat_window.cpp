#include "single_chat_window.h"
#include "ui_single_chat_window.h"

single_chat_window::single_chat_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::single_chat_window)
{
    ui->setupUi(this);
}

single_chat_window::~single_chat_window()
{
    delete ui;
}
