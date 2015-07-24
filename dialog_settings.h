#ifndef DIALOG_SETTINGS_H
#define DIALOG_SETTINGS_H

#include <QDialog>

namespace Ui {
    class dialog_settings;
}

class dialog_settings : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_settings(QWidget *parent = 0);
    ~dialog_settings();

private:
    Ui::dialog_settings *ui;
};

#endif // DIALOG_SETTINGS_H
