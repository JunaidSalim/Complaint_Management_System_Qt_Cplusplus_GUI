#ifndef STUDENTLOGINPAGE_H
#define STUDENTLOGINPAGE_H

#include <QDialog>

namespace Ui {
class StudentLoginPage;
}

class StudentLoginPage : public QDialog
{
    Q_OBJECT

public:
    QPair<QString,int> getNameAndRegNo();

    void changeTheText(QString str);

    explicit StudentLoginPage(QWidget *parent = nullptr);
    ~StudentLoginPage();

private slots:
    void on_Login_clicked();

private:
    Ui::StudentLoginPage *ui;
    QPair<QString,int> NameAndRegNo;
};

#endif // STUDENTLOGINPAGE_H
