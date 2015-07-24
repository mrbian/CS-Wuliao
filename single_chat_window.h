#ifndef SINGLE_CHAT_WINDOW_H
#define SINGLE_CHAT_WINDOW_H

#include <QDialog>

namespace Ui {
    class single_chat_window;
}

class single_chat_window : public QDialog
{
    Q_OBJECT

public:
    explicit single_chat_window(QWidget *parent = 0);
    ~single_chat_window();

private:
    Ui::single_chat_window *ui;
};

#endif // SINGLE_CHAT_WINDOW_H
