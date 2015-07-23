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
    ui->tableWidget_friend->setAlternatingRowColors(true);
    ui->tableWidget_friend->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_friend->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_group->setAlternatingRowColors(true);
    ui->tableWidget_group->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_group->setSelectionMode(QAbstractItemView::SingleSelection);
    _find = new dialog_addfriend();
    _add_friend_check = new dialog_addfriend_check();
    _find_group = new dialog_addgroup();
    _add_group_check = new dialog_addgroup_check();
    connect(_find,SIGNAL(sendFindData(QString,QString)),_add_friend_check,SLOT(receiveFindData(QString,QString)));
    connect(_find_group,SIGNAL(sendFindGroupData(QString,QString)),_add_group_check,SLOT(receiveFindGroupData(QString,QString)));
    connect(_add_friend_check,SIGNAL(sendMyFriend(QString,QString)),this,SLOT(getMyFriend(QString,QString)));
    connect(_add_group_check,SIGNAL(sendMyGroup(QString,QString)),this,SLOT(getMyGroup(QString,QString)));
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
   _find->exec();
}

void MainView::on_pushButton_addgroup_clicked()
{
    _find_group->exec();
}



void MainView::getMyFriend(QString name, QString id){
    ui->tableWidget_friend->insertRow(0);
    ui->tableWidget_friend->setItem(0,0,new QTableWidgetItem(name));
    ui->tableWidget_friend->setItem(0,1,new QTableWidgetItem(id));
}

void MainView::getMyGroup(QString name, QString id){
    ui->tableWidget_group->insertRow(0);
    ui->tableWidget_group->setItem(0,0,new QTableWidgetItem(name));
    ui->tableWidget_group->setItem(0,1,new QTableWidgetItem(id));
}

