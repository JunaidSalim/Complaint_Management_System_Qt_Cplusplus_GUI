#ifndef TEACHERMENU_H
#define TEACHERMENU_H
#include "app.h"
#include <QDialog>

namespace Ui {
class TeacherMenu;
}

class TeacherMenu : public QDialog
{
    Q_OBJECT

public:
    int pressedBtn;
    explicit TeacherMenu(QWidget *parent = nullptr);
    QPair<QString,int> getNameAndRegNo();
    // void getPassword();
    ~TeacherMenu();

private slots:
    void on_AddStu_clicked();

    void on_show_app_clicked();


    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::TeacherMenu *ui;
    QPair<QString,int> NameAndRegNo;
    // QString password;


};

#endif // TEACHERMENU_H
