#ifndef CHATROOM_H
#define CHATROOM_H

#include <QDialog>
#include <QDateTime>
namespace Ui {
    class chatroom;
}

class chatroom : public QDialog
{
    Q_OBJECT

public:
    explicit chatroom(QWidget *parent = 0);
    QString account_str;
    QString message;
    ~chatroom();
    QString date;
public slots:
    void getMessage(QString);
    void get_online_user(QString);
signals:
    void sendMessage(QString,QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::chatroom *ui;
};

#endif // CHATROOM_H
