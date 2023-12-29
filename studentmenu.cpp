#include "studentmenu.h"
#include "ui_studentmenu.h"
#include <QDebug>
StudentMenu::StudentMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentMenu)
{
    ui->setupUi(this);
    pressedBtn=0;
}

StudentMenu::~StudentMenu()
{
    delete ui;
}

void StudentMenu::on_pushButton_clicked()
{

    pressedBtn=1;
    qDebug()<<"The value is: "<<pressedBtn;
    close();
}


void StudentMenu::on_pushButton_2_clicked()
{
    pressedBtn=2;
    close();
}
void StudentMenu::changeTheLabel(QString str){
    ui->label->setText(str);
}

