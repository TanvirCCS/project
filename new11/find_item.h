#ifndef FIND_ITEM_H
#define FIND_ITEM_H

#include <QWidget>

namespace Ui {
class Find_item;
}

class Find_item : public QWidget
{
    Q_OBJECT

public:
    explicit Find_item(QWidget *parent = nullptr);
    ~Find_item();

private slots:
    //void on_Find_item_back_button_clicked();

private:
    Ui::Find_item *ui;
};
#endif // FIND_ITEM_H
