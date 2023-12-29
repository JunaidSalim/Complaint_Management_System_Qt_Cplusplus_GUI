#ifndef TEACHERLOGINPAGE_H
#define TEACHERLOGINPAGE_H

#include <QDialog>

namespace Ui {
class TeacherLoginPage;
}

class TeacherLoginPage : public QDialog
{
    Q_OBJECT

public:
    QPair<QString,QString> getData();
    explicit TeacherLoginPage(QWidget *parent = nullptr);
    ~TeacherLoginPage();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::TeacherLoginPage *ui;
    QPair<QString,QString> userNameAndPassword;
};

#endif // TEACHERLOGINPAGE_H
