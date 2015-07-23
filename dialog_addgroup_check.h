#ifndef DIALOG_ADDGROUP_CHECK_H
#define DIALOG_ADDGROUP_CHECK_H

#include <QDialog>

namespace Ui {
    class dialog_addgroup_check;
}

class dialog_addgroup_check : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_addgroup_check(QWidget *parent = 0);
    ~dialog_addgroup_check();
public slots:
    void receiveFindGroupData(QString,QString);
signals:
    void sendMyGroup(QString,QString);
private slots:
    void on_pushButton_yes_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::dialog_addgroup_check *ui;
};

#endif // DIALOG_ADDGROUP_CHECK_H
