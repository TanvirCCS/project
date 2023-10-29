#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QDebug>
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/SMS_db.db");
    db.open();
    qDebug() << db.isOpen();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_Login_Button_clicked()
{
    db = QSqlDatabase::database();
    Login_Email = ui->Login_email->text();
    Login_Pass = ui->Login_password->text();
    QSqlQuery qryyy;
    qryyy.exec("select * from Register where Email='"+Login_Email+"' and Password='"+Login_Pass+"'");
    if(qryyy.next())
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::warning(this,"Login","Wrong Email Password!");
    }
    ui->Login_email->clear();
    ui->Login_password->clear();
}


void MainWindow::on_Profile_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Profile_Exit_button_clicked()
{
    QMessageBox::StandardButton Reply;
    Reply = QMessageBox::question(this,"Exit","Are you sure?",QMessageBox::Yes | QMessageBox::No);
    if(Reply== QMessageBox::Yes) this->close();
}


void MainWindow::on_profile_additem_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_additem_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_additem_enterbutton_clicked()
{
    //db = QSqlDatabase::database();
    additem_name_input= ui -> additem_name_input->text();
    additem_quantity_input = ui -> additem_quantity_input->text();
    additem_status_combo_input = ui -> additem_combo_box->currentText();
    additem_dateofpurchase_input = ui->additem_dateofpurches_input->text();
    additem_dateofsell_input = ui->additem_dateofsell_input->text();
    additem_sellingprice_input = ui->additem_sellingprice_input->text();
    additem_purchaseprice_input = ui->additem_purchesprice_input->text();
    ui->stackedWidget->setCurrentIndex(1);
    ui->additem_name_input->clear();
    ui->additem_quantity_input->clear();
    ui->additem_dateofpurches_input->clear();
    ui->additem_dateofsell_input->clear();
    ui->additem_sellingprice_input->clear();
    QSqlQuery query;
    query.exec("insert into Add_item(Name, Quantity, Status, Date_of_purchase, Date_of_sell, Selling_price, Purchase_price) VALUES('"+additem_name_input+"','"+additem_quantity_input+"','"+additem_status_combo_input+"','"+additem_dateofpurchase_input+"','"+additem_dateofsell_input+"','"+additem_sellingprice_input+"','"+additem_purchaseprice_input+"')");
    QMessageBox::information(this,"additem","Item add successfully!");
}





void MainWindow::on_profile_updateitem_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_update_back_button_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_profile_finditem_button_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_Find_item_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_profile_availableitem_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    db = QSqlDatabase::database();
    qDebug() << "in init()";
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("select * from Add_item where Status='Available'");
    if(!qry->exec())
        qDebug() << qry->lastQuery();
    else
    {
        if(qry->numRowsAffected()>0)
            qDebug() << "== success query fetch() : " << qry->lastQuery();
        else
        {
            qDebug() << "No record ! found ";
            qDebug() << "Query is : " <<qry->lastQuery();
        }
    }
    while(qry->next())
        qDebug() << qry->value(0).toString();

    model-> setQuery(*qry);
    delete qry;
    ui->available_item_table->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->available_item_table->show();
    db.close();
}


void MainWindow::on_available_item_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_profile_expireditem_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    db = QSqlDatabase::database();
    qDebug() << "in init()";
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("select * from Add_item where Status='Expired'");
    if(!qry->exec())
        qDebug() << qry->lastQuery();
    else
    {
        if(qry->numRowsAffected()>0)
            qDebug() << "== success query fetch() : " << qry->lastQuery();
        else
        {
            qDebug() << "No record ! found ";
            qDebug() << "Query is : " <<qry->lastQuery();
        }
    }
    while(qry->next())
        qDebug() << qry->value(0).toString();

    model-> setQuery(*qry);
    delete qry;
    ui->expired_item_table->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->expired_item_table->show();
    db.close();
}


void MainWindow::on_expired_item_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_profile_solditem_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    db = QSqlDatabase::database();
    qDebug() << "in init()";
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("select * from Add_item where Status='Sold'");
    if(!qry->exec())
        qDebug() << qry->lastQuery();
    else
    {
        if(qry->numRowsAffected()>0)
            qDebug() << "== success query fetch() : " << qry->lastQuery();
        else
        {
            qDebug() << "No record ! found ";
            qDebug() << "Query is : " <<qry->lastQuery();
        }
    }
    while(qry->next())
        qDebug() << qry->value(0).toString();

    model-> setQuery(*qry);
    delete qry;
    ui->sold_item_table->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->sold_item_table->show();
    db.close();
}


void MainWindow::on_sold_item_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Find_item_button_clicked()
{
    db = QSqlDatabase::database();
    /*QSqlQueryModel *modal = new QSqlQueryModel(this);
    QSqlQuery qry;
    qry.prepare("selcet * from Add_item");
    qry.exec();
    modal->setQuery(qry);
    ui->Find_item_table_view->setModel(modal);
    qDebug() << (modal->rowCount());*/
    QString S_Value = ui -> Find_item_input->text();
    QString sCriteriaColumn = "";
    if(ui->radio_name->isChecked())
        sCriteriaColumn="Name";
    else if(ui->radio_quantity->isChecked())
        sCriteriaColumn="Quantity";
    else if(ui->radio_selling_price->isChecked())
        sCriteriaColumn="Selling_price";
    else
        sCriteriaColumn="Name";

    qDebug() << "in init()";
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("select * from Add_item where " +sCriteriaColumn+" like '" +S_Value+ "' ");

    if(!qry->exec())
        qDebug() << qry->lastQuery();
    else
    {
        if(qry->numRowsAffected()>0)
            qDebug() << "== success query fetch() : " << qry->lastQuery();
        else
        {
            qDebug() << "No record ! found ";
            qDebug() << "Query is : " <<qry->lastQuery();
        }
    }
    while(qry->next())
        qDebug() << qry->value(0).toString();

    model-> setQuery(*qry);
    delete qry;
    ui->Find_item_table_view->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->Find_item_table_view->show();
    db.close();
    ui->Find_item_input->clear();
}



void MainWindow::on_update_item_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    db = QSqlDatabase::database();
    QString sName = ui->update_item_name_input->text();
    QString sStatus = ui->update_comboBox->currentText();
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("update Add_item set Status='" +sStatus+ "' where Name = '" +sName+ "'");

    if(!qry->exec())
        qDebug() << qry->lastQuery();
    else{
        if(query.numRowsAffected()>0)
        {
            qDebug() << "Item Updated Successfully!";
        }
        else
        {
            qDebug() << " Unable to update Item";
        }
    }
    QMessageBox::StandardButton Reply;
    Reply = QMessageBox::question(this,"update","Are you sure?",QMessageBox::Yes | QMessageBox::No);
    if(Reply== QMessageBox::Yes)
    QMessageBox::information(this,"update","Item updated successfully!");
    db.close();
    ui->update_item_name_input->clear();
}


void MainWindow::on_profile_spoileditem_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    db = QSqlDatabase::database();
    qDebug() << "in init()";
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery *qry = new QSqlQuery(db);
    qry->prepare("select * from Add_item where Status='Spoiled '");
    if(!qry->exec())
    qDebug() << qry->lastQuery();
    else
    {
    if(qry->numRowsAffected()>0)
            qDebug() << "== success query fetch() : " << qry->lastQuery();
    else
    {
            qDebug() << "No record ! found ";
            qDebug() << "Query is : " <<qry->lastQuery();
    }
    }
    while(qry->next())
    qDebug() << qry->value(0).toString();

    model-> setQuery(*qry);
    delete qry;
    ui->spoiled_item_table->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->spoiled_item_table->show();
    db.close();
}


void MainWindow::on_spoiled_item_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_login_register_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_registration_page_signup_button_clicked()
{
    Register_name = ui->registration_page_name_input->text();
    Register_email= ui->registration_page_email_input->text();
    Register_pass= ui-> registration_page_password_input->text();
    Register_contact= ui->registration_page_contact_input->text();
    ui->stackedWidget->setCurrentIndex(0);
    ui->registration_page_name_input->clear();
    ui->registration_page_email_input->clear();
    ui->registration_page_password_input->clear();
    ui->registration_page_contact_input->clear();
    QSqlQuery qryy;
    qryy.exec("insert into Register(Name, Email, Password, Contact) VALUES('"+Register_name+"','"+Register_email+"','"+Register_pass+"','"+Register_contact+"')");
    QMessageBox::information(this,"Sign_up","Account created successfully!");
}


void MainWindow::on_registration_page_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

