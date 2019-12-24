#ifndef DIALOG_ADDGROUP_H
#define DIALOG_ADDGROUP_H

#include <QDialog>

namespace Ui {
    class dialog_addgroup;
}

class dialog_addgroup : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_addgroup(QWidget *parent = 0);
    ~dialog_addgroup();
signals:
    void sendFindGroupData(int);
private slots:
    void on_pushButton_yes_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::dialog_addgroup *ui;
};

#endif // DIALOG_ADDGROUP_H
