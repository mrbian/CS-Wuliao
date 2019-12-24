#ifndef DIALOG_CREATEGROUP_H
#define DIALOG_CREATEGROUP_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
    class dialog_creategroup;
}

class dialog_creategroup : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_creategroup(QWidget *parent = 0);
    ~dialog_creategroup();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
public slots:
    void check_create_group(QString);

signals:
    void send_createGroup(QString,QString,QString);
    void create_done(QString group_account_str);
private:
    Ui::dialog_creategroup *ui;
};

#endif // DIALOG_CREATEGROUP_H
