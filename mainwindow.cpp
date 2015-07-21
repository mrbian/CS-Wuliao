#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_submit_clicked()
{
    this->hide();
    QDesktopWidget *deskdop = QApplication::desktop();
    f.setFixedSize(475,350);
    f.move((deskdop->width()-f.width())/2,(deskdop->height()-f.height())/2);
    f.show();
    f.exec();
    this->show();
}

void MainWindow::on_pushButton_login_clicked()
{
   QString str_account = ui->lineEdit_account->text();
   QMessageBox::about(this,tr("title"),str_account);
}
