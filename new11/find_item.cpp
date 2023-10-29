#include "find_item.h"
#include "ui_find_item.h"

Find_item::Find_item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Find_item)
{
    ui->setupUi(this);
}

Find_item::~Find_item()
{
    delete ui;
}

/*void Find_item::on_Find_item_back_button_clicked()
{
    MainWindow *mainwidow_display;
    mainwidow_display=new MainWindow(this);
    this -> hide();
    mainwidow_display -> show();
}*/

