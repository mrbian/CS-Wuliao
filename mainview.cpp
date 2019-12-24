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
    //没有注释太可怕了- - ，要养成加注释的好习惯，等项目结束给这个加上！！！！不然过个半个月自己都看不懂
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
    room = new chatroom();
    single_chat_length = 0;
    group_chat_length = 0;
    deal = new dialog_deal(); //socket已经不一样了,使用信号和槽传值也没有效果
    connect(_find,SIGNAL(sendFindData(int)),this,SLOT(receiveFindData(int)));
    connect(deal,SIGNAL(find_friend_done(QString)),_add_friend_check,SLOT(receiveFindData(QString)));
    connect(deal,SIGNAL(add_friend_done(QString)),this,SLOT(receiveAddFriendData(QString)));
    connect(_find_group,SIGNAL(sendFindGroupData(int)),_add_group_check,SLOT(receiveFindGroupData(int)));
    connect(_add_friend_check,SIGNAL(sendMyFriend(QString)),this,SLOT(getMyFriend(QString)));
    connect(_add_group_check,SIGNAL(sendMyGroup(QString,QString)),this,SLOT(getMyGroup(QString,QString)));
    connect(this,SIGNAL(change_socket(int)),deal,SLOT(changeSocket(int)));
    connect(_single_chat,SIGNAL(send_single_message(int,int,QString)),this,SLOT(sendSingleMessage(int,int,QString)));
    connect(deal,SIGNAL(send_single_message_done(QString)),this,SLOT(check_single_message(QString)));
    connect(this,SIGNAL(single_show()),_single_chat,SLOT(get_show_done()));
    connect(_creategroup,SIGNAL(send_createGroup(QString,QString,QString)),this,SLOT(getCreateMessage(QString,QString,QString)));
    connect(deal,SIGNAL(create_group_done(QString)),_creategroup,SLOT(check_create_group(QString)));
    connect(_creategroup,SIGNAL(create_done(QString)),this,SLOT(create_done(QString)));
    connect(deal,SIGNAL(send_chat_message(QString)),room,SLOT(getMessage(QString)));
    connect(room,SIGNAL(sendMessage(QString,QString)),this,SLOT(send_message(QString,QString)));
    connect(deal,SIGNAL(send_online_user(QString)),room,SLOT(get_online_user(QString)));
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



void MainView::getMyFriend(QString friend_account_str){
    int friend_account = friend_account_str.toInt();
    deal->addFriend(session.account,friend_account);
}

void MainView::getMyGroup(QString name, QString id){
    ui->tableWidget_group->insertRow(0);
    ui->tableWidget_group->setItem(0,0,new QTableWidgetItem(name));
    ui->tableWidget_group->setItem(0,1,new QTableWidgetItem(id));
}


void MainView::on_tableWidget_friend_doubleClicked(const QModelIndex &index)
{
    //以后换成链表
    _single_chat[single_chat_length].user_account.setNum(session.account);
    _single_chat[single_chat_length].friend_account = this->ui->tableWidget_friend->item(index.row(),1)->text();
    _single_chat[single_chat_length].friend_email = session.user_email;
    //connect(deal,SIGNAL(send_single_message_done(QString)),&_single_chat[single_chat_length],SLOT(get_single_message(QString)));

    connect(this,SIGNAL(single_show()),&_single_chat[single_chat_length],SLOT(get_show_done()));
    emit single_show();
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

void MainView::get_user_session(int user_account,QString user_password,QString user_name,QString user_friend,QString user_own_group,QString user_join_group,QString user_email,int user_grant){

    session.account = user_account;
    session.user_name = user_name;
    session.user_friend = user_friend;
    session.user_password = user_password;
    session.user_own_group = user_own_group;
    session.user_join_group = user_join_group;
    session.user_email = user_email;
    session.user_grant = user_grant;
   // this->deal->client = client;
    this->CreateTrayIcon();
    if(session.user_friend != "null"){
        QStringList my_friend = session.user_friend.split("-");
        for(int i =0;i<my_friend.length();i++){
            ui->tableWidget_friend->insertRow(i);
            ui->tableWidget_friend->setItem(i,1,new QTableWidgetItem(my_friend[i]));
        }
    }
    if(session.user_join_group != "null"){
        QStringList my_group = session.user_join_group.split("-");
        for(int i=0;i<my_group.length();i++){
            ui->tableWidget_group->insertRow(i);
            ui->tableWidget_group->setItem(i,1,new QTableWidgetItem(my_group[i]));
        }
    }
    QString name = "你好，"+session.user_name;  // 你好的消息
    this->ui->label->setText(name);
    this->show();
    emit change_socket(user_account);
}

void MainView::receiveFindData(int friend_account){
    deal->findFriend(friend_account);
}

void MainView::receiveAddFriendData(QString data){
    QStringList datalist = data.split('-');
    QString result = datalist[1];
    if(result == "no_such_user"){
        QMessageBox::about(this,tr("sorry"),tr("没有这个用户"));
    }else if(result == "already_have"){
        QMessageBox::about(this,tr("sorry"),tr("他已经是你的好友了"));
    }else if(result == "only_one"){
        QMessageBox::about(this,tr("sorry"),tr("不能添加自己为好友o(╯□╰)o"));
    }else if(result == "need_check"){
        QMessageBox::about(this,tr("attention"),tr("等待对方验证后添加"));
    }else if(result == "no_add"){
        QMessageBox::about(this,tr("sorry"),tr("对方不想任何人加ta好友"));
    }else if(result == "add_success"){
        this->ui->tableWidget_friend->insertRow(ui->tableWidget_friend->rowCount());
        ui->tableWidget_friend->setItem(ui->tableWidget_friend->rowCount()-1,1,new QTableWidgetItem(datalist[2]));
    }else if(result == "add_fail"){
        QMessageBox::about(this,tr("sorry"),tr("服务器错误"));
    }
}

void MainView::sendSingleMessage(int account, int friend_account, QString message){
    deal->sendSingleMessage(account,friend_account,message);
}

void MainView::check_single_message(QString data){
    QStringList datalist = data.split('-');
    QString send_account_str = datalist[2];
    QString rev_account_str = datalist[3];
    QString message = datalist[4];
    QString my_account_str;
    my_account_str.setNum(session.account);
    int flag_me = 0;                                //判断接受账号是否是我，不是我直接丢掉
    if(rev_account_str == my_account_str){
        flag_me = 1;
    }
    //然后判断我是否已经有对话框和这个好友通讯
    int flag_window = 0;
    if(flag_me){
        for(int i=0;i<single_chat_length;i++){
            if(_single_chat[i].friend_account == send_account_str){
                flag_window = 1;
                single_chat_id = i;
            }
        }
    }

    if(flag_window){            //如果有，接受到指定对话框
        connect(this,SIGNAL(sendToChatWindow(QString)),&_single_chat[single_chat_id],SLOT(get_single_message(QString)));
        emit sendToChatWindow(message);
    }else{                      //如果没有，自己新建对话框并接受
        _single_chat[single_chat_length].user_account = my_account_str;
        _single_chat[single_chat_length].friend_account = send_account_str;
        _single_chat[single_chat_length].friend_email = session.user_email; //这里是错误的 = = 不应该是自己的邮箱= =
        //connect(deal,SIGNAL(send_single_message_done(QString)),&_single_chat[single_chat_length],SLOT(get_single_message(QString)));
        connect(this,SIGNAL(single_show()),&_single_chat[single_chat_length],SLOT(get_show_done()));
        emit single_show();
        connect(this,SIGNAL(sendToChatWindow(QString)),&_single_chat[single_chat_length],SLOT(get_single_message(QString)));
        emit sendToChatWindow(message);
        _single_chat[single_chat_length].show();
        single_chat_length ++;
    }
}

void MainView::getCreateMessage(QString group_name, QString group_account_str,QString group_describe){
    int group_account = group_account_str.toInt();
    deal->createGroup(session.account,group_account,group_name,group_describe);
}

void MainView::create_done(QString group_account_str){
    this->ui->tableWidget_group->insertRow(ui->tableWidget_group->rowCount());
    this->ui->tableWidget_group->setItem(ui->tableWidget_group->rowCount(),1,new QTableWidgetItem(group_account_str));
}

void MainView::on_pushButton_chatroom_clicked()
{
    room->show();
    room->account_str.setNum(session.account);
}

void MainView::send_message(QString account_str, QString message){
    deal->sendChatMessage(account_str,message);
}
