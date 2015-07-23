#ifndef DIALOG_ADDFRIEND_CHECK_H
#define DIALOG_ADDFRIEND_CHECK_H

#include <QDialog>

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
    void sendMyFriend(QString,QString);
public slots:
    void output_data(QString,QString);
private slots:
    void on_pushButton_yes_clicked();

private:
    Ui::dialog_addfriend_check *ui;
};

#endif // DIALOG_ADDFRIEND_CHECK_H
