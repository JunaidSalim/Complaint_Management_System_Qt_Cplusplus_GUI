#include "studentloginpage.h"
#include "ui_studentloginpage.h"

StudentLoginPage::StudentLoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentLoginPage)
{
    ui->setupUi(this);

}

QPair<QString,int> StudentLoginPage::getNameAndRegNo(){
    return NameAndRegNo;
}

StudentLoginPage::~StudentLoginPage()
{
    delete ui;
}

void StudentLoginPage::on_Login_clicked()
{
    NameAndRegNo.first=ui->lineEdit_3->text();
    NameAndRegNo.second=ui->lineEdit_4->text().toInt();

    close();
}

void StudentLoginPage::changeTheText(QString str){

    ui->label->setText(str);

}
