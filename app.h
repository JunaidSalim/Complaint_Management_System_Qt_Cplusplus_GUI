#ifndef APP_H
#define APP_H
#include<QPair>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <QMessageBox>
#include "submitapp.h"
#include "teachermenu.h"
#include "studentmenu.h"
#include<QRadioButton>
#include <QFile>
#include <QTextStream>




class Application{
public:
    QString subject;
    QString msg;
    int isApproved;


    QString ApprovedOrNot(){
        if (isApproved==1) return "Approved";
        if(isApproved==-1) return "Declined";
        return "Not Reviewed";
    }

};

class StudentDetails{
public:
    int regNo;
    QString name;
    QString password;
    StudentDetails(int r=-1,QString name="Anonymous"){
        this->regNo=r;
        this->name=name;
    }
    bool VerifyRegNo(int regNo){
        return this->regNo==regNo;
    }
};

class StudentMessages{
    public:
    StudentDetails* stu;
    QVector<Application*> apps;

    StudentMessages(StudentDetails* stu=nullptr){
        if(!stu){
            this->stu=new StudentDetails();
        }
        this->stu=stu;
    }

    void addApplication(Application* app){
        apps.push_back(app);
    }
    StudentDetails* searchStudent(int regNo){
        if(this->stu->VerifyRegNo(regNo)){
            return stu;
        }
        return nullptr;
    }

    QVector<Application*> getApp(){
        return apps;
    }
    StudentDetails* getStudentDetails(){
        return stu;
    }
};
class Node {
public:
    Application* app;
    StudentDetails* stu;
    Node* next;
    // QRadioButton *radioButtonYes;
    // QRadioButton *radioButtonNo;

    Node(Application* a, StudentDetails* s) : app(a), stu(s), next(nullptr) {}
};

class Queue {
private:


    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void RemoveThisNode(Node * node){
        Node* temp=node;
        if(node==front){
        front=front->next;
        delete temp;
        return;
        }
        Node* tempfront=front;
        while(tempfront->next!=node){
            tempfront=tempfront->next;
        }
        tempfront->next=tempfront->next->next;
        delete temp;
        return;
    }

    void enqueue(Application* a, StudentDetails* s) {
        Node* newNode = new Node(a, s);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            // Handle underflow (empty queue)
            return;
        }

        Node* temp = front;
        front = front->next;
        // delete temp;


    }
    Node* returnFront(){

        return front;
    }

    // Add other necessary methods such as peek, display, etc.
};


class Teacher{
    QString userName;
    QString password;
    QString name;
public:
    Teacher(QString userName="teacher",QString password="password",QString name="anonymous"){
        this->userName=userName;
        this->password=password;
        this->name=name;
    }

    bool Verify(QString u,QString p){
        return (this->userName==u && this->password==p);
    }

    QString Name(){
        return name;
    }


};

QT_BEGIN_NAMESPACE
namespace Ui {
class App;
}
QT_END_NAMESPACE

class App:public QMainWindow{
    Q_OBJECT
private:
    Ui::App *ui;
    Teacher* teacher;
    Queue q1;
    QVector<StudentMessages*> stu_msgs;

    QWidget window;


protected:

public:
    explicit App(QWidget *parent=nullptr);
    bool teacherLogin(QString userName,QString password);
    void ShowApplications();
    void AddStudent();
    void DeleteStudent();
    StudentMessages* StudentLogin(int RegNo);
    void SubmitApplication(StudentMessages* stu);
    void ShowMeMyApplication(StudentMessages* stu);
    void clearWidgetsFromWindow(QWidget* window);
    void ExtractAndAddStudent();
    void outPutDataToFile();

private slots:





    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // APP_H
