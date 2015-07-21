#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QDialog>

namespace Ui {
    class MainView;
}

class MainView : public QDialog
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    Ui::MainView *ui;
};

#endif // MAINVIEW_H
