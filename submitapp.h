#ifndef SUBMITAPP_H
#define SUBMITAPP_H
#include "app.h"
#include <QDialog>

namespace Ui {
class SubmitApp;
}

class SubmitApp : public QDialog
{
    Q_OBJECT

public:
    explicit SubmitApp(QWidget *parent = nullptr);
    ~SubmitApp();
    QPair<QString,QString> getData();
private slots:
    void on_pushButton_clicked();

private:
    Ui::SubmitApp *ui;
    QPair<QString,QString> sub_and_msg;
};

#endif // SUBMITAPP_H
