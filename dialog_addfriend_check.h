#ifndef DIALOG_ADDFRIEND_CHECK_H
#define DIALOG_ADDFRIEND_CHECK_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
    class dialog_addfriend_check;
}

class dialog_addfriend_check : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_addfriend_check(QWidget *parent = 0);
    ~dialog_addfriend_check();
signals:
    void sendMyFriend(QString);
public slots:
    void receiveFindData(QString);
private slots:
    void on_pushButton_yes_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::dialog_addfriend_check *ui;
};

#endif // DIALOG_ADDFRIEND_CHECK_H
