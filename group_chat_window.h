#ifndef GROUP_CHAT_WINDOW_H
#define GROUP_CHAT_WINDOW_H

#include <QDialog>

namespace Ui {
    class group_chat_window;
}

class group_chat_window : public QDialog
{
    Q_OBJECT

public:
    explicit group_chat_window(QWidget *parent = 0);
    ~group_chat_window();

private:
    Ui::group_chat_window *ui;
};

#endif // GROUP_CHAT_WINDOW_H
