#include "teacherloginpage.h"
#include "ui_teacherloginpage.h"

TeacherLoginPage::TeacherLoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeacherLoginPage)
{
    ui->setupUi(this);
}

TeacherLoginPage::~TeacherLoginPage()
{
    delete ui;
}

QPair<QString,QString> TeacherLoginPage::getData(){
    return userNameAndPassword;
}
void TeacherLoginPage::on_pushButton_2_clicked()
{
    userNameAndPassword.first=ui->lineEdit_3->text();
    userNameAndPassword.second=ui->lineEdit_4->text();
    close();
}

