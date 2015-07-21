#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include "dialog.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_submit_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
    Dialog f;
};

#endif // MAINWINDOW_H
