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
       QMessageBox::about(this,tr("����"),tr("��������û�������"));
   }
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
