#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    CreateTrayIcon();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_submit_clicked()
{
    this->hide();
    QDesktopWidget *deskdop = QApplication::desktop();
    myTrayIcon->hide();
    f.setFixedSize(475,350);
    f.move((deskdop->width()-f.width())/2,(deskdop->height()-f.height())/2);
    f.CreateTrayIcon();
    f.show();
    f.exec();
    myTrayIcon->show();
    this->show();
}

void MainWindow::on_pushButton_login_clicked()
{
   QString str_account = ui->lineEdit_account->text();
   QString str_password = ui->lineEdit_password->text();
   if(str_account == "root" && str_password == "root"){
       this->hide();
       myTrayIcon->hide();
       m.CreateTrayIcon();
       m.show();
   }else{
       QMessageBox::about(this,tr("错误"),tr("密码或者用户名错误"));
   }
   //QMessageBox::about(this,tr("title"),str_account);
}

void MainWindow::CreateTrayMenu(){
    miniSizeAction = new QAction("最小化(&N)",this);
    maxSizeAction = new QAction("最大化(&X)",this);
    restoreWinAction = new QAction("还原(&R)",this);
    quitAction = new QAction("退出(&Q)",this);

    connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());
    myMenu->addAction(miniSizeAction);
    myMenu->addAction(maxSizeAction);
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();     //加入一个分离符
    myMenu->addAction(quitAction);
}

void MainWindow::CreateTrayIcon(){
    CreateTrayMenu();
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    myTrayIcon = new QSystemTrayIcon(this);

    myTrayIcon->setIcon(QIcon(":/1.png"));   //设置图标图片

    setWindowIcon(QIcon(":/1.png"));  //把图片设置到窗口上

    //myTrayIcon->setToolTip("SystemTrayIcon V1.0");    //托盘时，鼠标放上去的提示信息

   // myTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,10000);

    myTrayIcon->setContextMenu(myMenu);     //设置托盘上下文菜单
    myTrayIcon->show();
    this->connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason){
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        showNormal();
        break;
    case QSystemTrayIcon::MiddleClick:
       myTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,10000);
         break;
    default:
        break;
    }
}

void MainWindow::closeEvent(QCloseEvent *event){
    if(myTrayIcon->isVisible()){
        hide();
        event->ignore();
    }else{
        event->accept();
    }
}
