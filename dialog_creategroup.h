#ifndef DIALOG_CREATEGROUP_H
#define DIALOG_CREATEGROUP_H

#include <QDialog>

namespace Ui {
    class dialog_creategroup;
}

class dialog_creategroup : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_creategroup(QWidget *parent = 0);
    ~dialog_creategroup();

private:
    Ui::dialog_creategroup *ui;
};

#endif // DIALOG_CREATEGROUP_H
