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
    ui->tableWidget_friend->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_group->setAlternatingRowColors(true);
    ui->tableWidget_group->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_group->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_group->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _find = new dialog_addfriend();
    _add_friend_check = new dialog_addfriend_check();
    _find_group = new dialog_addgroup();
    _add_group_check = new dialog_addgroup_check();
    _creategroup = new dialog_creategroup();
    _settings = new dialog_settings();
    _single_chat = new single_chat_window[20];
    _group_chat = new group_chat_window[20];
    single_chat_length = 0;
    group_chat_length = 0;
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
    miniSizeAction = new QAction("最小化(&N)",this);
    maxSizeAction = new QAction("最大化(&X)",this);
    restoreWinAction = new QAction("还原(&R)",this);
    quitAction = new QAction("退出(&Q)",this);

    this->connect(miniSizeAction,SIGNAL(triggered()),this,SLOT(hide()));
    this->connect(maxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    this->connect(restoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    this->connect(quitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    myMenu = new QMenu((QWidget*)QApplication::desktop());
    myMenu->addAction(miniSizeAction);
    myMenu->addAction(maxSizeAction);
    myMenu->addAction(restoreWinAction);
    myMenu->addSeparator();     //加入一个分离符
    myMenu->addAction(quitAction);
}

void MainView::CreateTrayIcon(){
    CreateTrayMenu();
    if (!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        return;
    }

    myTrayIcon = new QSystemTrayIcon(this);

    myTrayIcon->setIcon(QIcon(":/1.png"));   //设置图标图片

    setWindowIcon(QIcon(":/1.png"));  //把图片设置到窗口上

    //myTrayIcon->setToolTip("SystemTrayIcon V1.0");    //托盘时，鼠标放上去的提示信息

    //myTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,10000);

    myTrayIcon->setContextMenu(myMenu);     //设置托盘上下文菜单
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


void MainView::on_tableWidget_friend_doubleClicked(const QModelIndex &index)
{
    QTableWidgetItem * item = new QTableWidgetItem();
    item = ui->tableWidget_friend->item(index.row(),0);
    _single_chat[single_chat_length].show();
    single_chat_length ++;
}



void MainView::on_tableWidget_group_doubleClicked(const QModelIndex &index)
{
    QTableWidgetItem * item = new QTableWidgetItem();
    item = ui->tableWidget_group->item(index.row(),0);
    _group_chat[group_chat_length].show();
    group_chat_length++;
}

void MainView::on_pushButton_creategroup_clicked()
{
    _creategroup->exec();
}

void MainView::on_pushButton_settings_clicked()
{
    _settings->exec();
}
