#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainView)
{
    Qt::WindowFlags flags=Qt::Dialog;

    flags |=Qt::WindowMinimizeButtonHint;

    setWindowFlags(flags);
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::CreateTrayMenu(){
    miniSizeAction = new QAction("��С��(&N)",this);
    maxSizeAction = new QAction("���(&X)",this);
    restoreWinAction = new QAction("��ԭ(&R)",this);
    quitAction = new QAction("�˳�(&Q)",this);

    this->connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(hide()));
    this->connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    this->connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());
    myMenu->addAction(miniSizeAction);
    myMenu->addAction(maxSizeAction);
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();     //����һ�������
    myMenu->addAction(quitAction);
}

void MainView::CreateTrayIcon(){
    CreateTrayMenu();
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //�ж�ϵͳ�Ƿ�֧��ϵͳ����ͼ��
    {
        return;
    }

    myTrayIcon = new QSystemTrayIcon(this);

    myTrayIcon->setIcon(QIcon(":/1.png"));   //����ͼ��ͼƬ

    setWindowIcon(QIcon(":/1.png"));  //��ͼƬ���õ�������

    //myTrayIcon->setToolTip("SystemTrayIcon V1.0");    //����ʱ��������ȥ����ʾ��Ϣ

    //myTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,10000);

    myTrayIcon->setContextMenu(myMenu);     //�������������Ĳ˵�
    myTrayIcon->show();
    this->connect(myTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainView::iconActivated(QSystemTrayIcon::ActivationReason reason){
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

void MainView::closeEvent(QCloseEvent *event){
    if(myTrayIcon->isVisible()){
        hide();
        event->accept();
    }else{
        event->accept();
    }
}



void MainView::on_pushButton_myfreind_clicked()
{
    if(ui->tableWidget_friend->isVisible()){
        ui->tableWidget_friend->hide();
    }else{
        ui->tableWidget_friend->show();
    }
}

void MainView::on_pushButton_mygroup_clicked()
{
    if(ui->tableWidget_group->isVisible()){
        ui->tableWidget_group->hide();
    }else{
        ui->tableWidget_group->show();
    }
}

void MainView::on_pushButton_clicked()
{
    //connect(a,SIGNAL(sendFindData(QString,QString)),this,SLOT(receiveFindData(QString,QString)));
   // a->exec();
}

void MainView::receiveFindData(QString name, QString id){
    QMessageBox::about(this,name,id);
}
