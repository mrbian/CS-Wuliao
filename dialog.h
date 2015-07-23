#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QToolButton>
#include <QPixmap>
#include <QStyle>
#include <QMessageBox>
namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void CreateTrayMenu();
    void CreateTrayIcon();
    QSystemTrayIcon *myTrayIcon;
    QMenu *myMenu;
    QAction *miniSizeAction;
    QAction *maxSizeAction;
    QAction *restoreWinAction;
    QAction *quitAction;
private slots:
    void on_pushButton_2_clicked();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
private:
    Ui::Dialog *ui;
protected:
   void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H
