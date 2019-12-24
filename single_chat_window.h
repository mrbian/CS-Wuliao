#ifndef SINGLE_CHAT_WINDOW_H
#define SINGLE_CHAT_WINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QDateTime>
namespace Ui {
    class single_chat_window;
}

class single_chat_window : public QDialog
{
    Q_OBJECT

public:
    explicit single_chat_window(QWidget *parent = 0);
    ~single_chat_window();
    QString user_account;
    QString friend_account;
    QString friend_email;
    QString date;
public slots:
    void get_single_message(QString data);
    void get_show_done();
private slots:
    void on_pushButton_clicked();
signals:
    void send_single_message(int account,int friend_account,QString message);

private:
    Ui::single_chat_window *ui;
};

#endif // SINGLE_CHAT_WINDOW_H
