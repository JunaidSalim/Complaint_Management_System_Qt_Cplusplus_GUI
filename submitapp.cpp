#include "submitapp.h"
#include "ui_submitapp.h"

SubmitApp::SubmitApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SubmitApp)
{
    ui->setupUi(this);
}

SubmitApp::~SubmitApp()
{
    delete ui;
}

void SubmitApp::on_pushButton_clicked()
{

    QString sub=ui->lineEdit->text();
    QString msg=ui->plainTextEdit->toPlainText();
    sub_and_msg.first=sub;
    sub_and_msg.second=msg;
    // close the window
    close();
}

QPair<QString,QString> SubmitApp::getData(){
    return sub_and_msg;
}

