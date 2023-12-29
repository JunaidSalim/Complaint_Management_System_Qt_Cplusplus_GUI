#include "teachermenu.h"
#include "ui_teachermenu.h"
#include "app.h"
#include<QInputDialog>
TeacherMenu::TeacherMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TeacherMenu)
{
    ui->setupUi(this);
    pressedBtn=0;
}

TeacherMenu::~TeacherMenu()
{
    delete ui;
}
QPair<QString,int> TeacherMenu::getNameAndRegNo(){
    return NameAndRegNo;
}
// QString getPassword(){
//     return password;
// }

void TeacherMenu::on_AddStu_clicked()
{
    pressedBtn=1;
    QString name = QInputDialog::getText(nullptr, "Input Name", "Enter Student name: ");
    int regNo = QInputDialog::getInt(nullptr, "Input Name", "Enter Student RegNo: ");
    // password=QInputDialog::getInt(nullptr, "Input Password", "Enter Student Password: ");
    NameAndRegNo.first=name;
    NameAndRegNo.second=regNo;

    close();
}


void TeacherMenu::on_show_app_clicked()
{
    pressedBtn=2;
    close();
}




void TeacherMenu::on_pushButton_4_clicked()
{
    pressedBtn=4;
    close();
}


void TeacherMenu::on_pushButton_3_clicked()
{
    pressedBtn=3;
    close();
}

