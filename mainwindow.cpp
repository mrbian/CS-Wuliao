#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->deal = new dialog_deal();
    CreateTrayIcon();
    connect(deal,SIGNAL(user_login_done(QString)),this,SLOT(check_user_login(QString)));
    connect(&f,SIGNAL(send_reg_data(int,QString,QString,QString)),this,SLOT(get_reg_data(int,QString,QString,QString)));
    connect(deal,SIGNAL(add_user_done(QString)),this,SLOT(check_add_user(QString)));
    connect(this,SIGNAL(send_user_session(int,QString,QString,QString,QString,QString,QString,int,QTcpSocket *)),&m,SLOT(get_user_session(int,QString,QString,QString,QString,QString,QString,int)));

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
   int account = str_account.toInt();
   deal->userLogin(account,str_password);
   /*if(str_account == "root" && str_password == "root"){
       this->hide();
       myTrayIcon->hide();
       m.CreateTrayIcon();
       m.show();
   }else{
       QMessageBox::about(this,tr("错误"),tr("密码或者用户名错误"));
   }*/
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

void MainWindow::check_user_login(QString data){
    QStringList datalist = data.split('|');  //对消息分组,登录分组比较特殊

    QString type= datalist[0];
    QString result = datalist[1];
    QString user_account_str,user_password,user_name,user_friend,user_own_group,user_join_group,user_email,user_grant_str;

    if(result == "success"){
        this->hide();
        myTrayIcon->hide();
        user_account_str = datalist[2];
        user_password = datalist[3];
        user_name = datalist[4];
        user_friend = datalist[5];
        user_own_group = datalist[6];
        user_join_group = datalist[7];
        user_email = datalist[8];
        user_grant_str = datalist[9];
        emit send_user_session(user_account_str.toInt(),user_password,user_name,user_friend,user_own_group,user_join_group,user_email,user_grant_str.toInt(),this->deal->client);
        /*m.CreateTrayIcon();
        m.show();*/
    }else if(result == "fail"){
        if(datalist[2] == "already_login")
            QMessageBox::about(this,tr("错误"),tr("用户已登录"));
        else
            QMessageBox::about(this,tr("错误"),tr("密码或者用户名错误"));
    }
}

void MainWindow::get_reg_data(int account, QString password, QString email, QString name){
    deal->addUser(name,password,account,email);
}

void MainWindow::check_add_user(QString data){
    QStringList datalist = data.split('-');  //对消息分组

    QString type= datalist[0];
    QString result = datalist[1];
    QString datacontent;
    if(result == "success"){
        QMessageBox::about(&f,tr("恭喜"),tr("注册成功"));
    }else if(result == "fail"){
        QMessageBox::about(&f,tr("sorry"),tr("用户已被注册"));
    }
}
