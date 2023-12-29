#ifndef STUDENTMENU_H
#define STUDENTMENU_H
#include "app.h"

#include <QDialog>

namespace Ui {
class StudentMenu;
}

class StudentMenu : public QDialog
{
    Q_OBJECT

public:
    void changeTheLabel(QString str);
    int pressedBtn;
    explicit StudentMenu(QWidget *parent = nullptr);
    ~StudentMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::StudentMenu *ui;
};

#endif // STUDENTMENU_H
