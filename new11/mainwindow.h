#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Login_Button_clicked();

    void on_Profile_back_button_clicked();

    void on_Profile_Exit_button_clicked();

    void on_additem_back_button_clicked();

    void on_profile_additem_button_clicked();

    void on_additem_enterbutton_clicked();


    void on_profile_updateitem_button_clicked();

    void on_pushButton_clicked();

    void on_update_back_button_clicked();

    void on_profile_finditem_button_clicked();

    void on_Find_item_back_button_clicked();

    void on_profile_availableitem_button_clicked();

    void on_available_item_back_button_clicked();

    void on_profile_expireditem_button_clicked();

    void on_expired_item_back_button_clicked();

    void on_profile_solditem_button_clicked();

    void on_sold_item_back_button_clicked();

    void on_Find_item_button_clicked();

    void on_update_item_button_clicked();

    void on_profile_spoileditem_button_clicked();

    void on_spoiled_item_back_button_clicked();

    void on_login_register_button_clicked();

    void on_registration_page_signup_button_clicked();

    void on_registration_page_back_button_clicked();

private:
    Ui::MainWindow *ui;
    QString Login_Email, Login_Pass,Register_name,Register_email,Register_pass,Register_contact,additem_name_input,additem_quantity_input,additem_status_combo_input,additem_dateofpurchase_input,additem_dateofsell_input,additem_sellingprice_input,additem_purchaseprice_input;
    QSqlDatabase db;
    QSqlQuery query;
};
#endif // MAINWINDOW_H
