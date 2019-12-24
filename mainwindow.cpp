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
       QMessageBox::about(this,tr("����"),tr("��������û�������"));
   }*/
   //QMessageBox::about(this,tr("title"),str_account);
}

void MainWindow::CreateTrayMenu(){
    miniSizeAction = new QAction("��С��(&N)",this);
    maxSizeAction = new QAction("���(&X)",this);
    restoreWinAction = new QAction("��ԭ(&R)",this);
    quitAction = new QAction("�˳�(&Q)",this);

    connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());
    myMenu->addAction(miniSizeAction);
    myMenu->addAction(maxSizeAction);
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();     //����һ�������
    myMenu->addAction(quitAction);
}

void MainWindow::CreateTrayIcon(){
    CreateTrayMenu();
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //�ж�ϵͳ�Ƿ�֧��ϵͳ����ͼ��
    {
        return;
    }

    myTrayIcon = new QSystemTrayIcon(this);

    myTrayIcon->setIcon(QIcon(":/1.png"));   //����ͼ��ͼƬ

    setWindowIcon(QIcon(":/1.png"));  //��ͼƬ���õ�������

    //myTrayIcon->setToolTip("SystemTrayIcon V1.0");    //����ʱ��������ȥ����ʾ��Ϣ

   // myTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,10000);

    myTrayIcon->setContextMenu(myMenu);     //�������������Ĳ˵�
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
    QStringList datalist = data.split('|');  //����Ϣ����,��¼����Ƚ�����

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
            QMessageBox::about(this,tr("����"),tr("�û��ѵ�¼"));
        else
            QMessageBox::about(this,tr("����"),tr("��������û�������"));
    }
}

void MainWindow::get_reg_data(int account, QString password, QString email, QString name){
    deal->addUser(name,password,account,email);
}

void MainWindow::check_add_user(QString data){
    QStringList datalist = data.split('-');  //����Ϣ����

    QString type= datalist[0];
    QString result = datalist[1];
    QString datacontent;
    if(result == "success"){
        QMessageBox::about(&f,tr("��ϲ"),tr("ע��ɹ�"));
    }else if(result == "fail"){
        QMessageBox::about(&f,tr("sorry"),tr("�û��ѱ�ע��"));
    }
}
