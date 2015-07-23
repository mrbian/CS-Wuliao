#ifndef DIALOG_ADDFRIEND_H
#define DIALOG_ADDFRIEND_H

#include <QDialog>

namespace Ui {
    class dialog_addfriend;
}

class dialog_addfriend : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_addfriend(QWidget *parent = 0);
    ~dialog_addfriend();

private:
    Ui::dialog_addfriend *ui;
};

#endif // DIALOG_ADDFRIEND_H
