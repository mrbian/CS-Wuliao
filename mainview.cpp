#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}
