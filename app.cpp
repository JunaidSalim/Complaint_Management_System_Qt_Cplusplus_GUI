#include "app.h"
#include "ui_app.h"
#include<QInputDialog>
#include<QApplication>
#include<QVector>
#include<QRadioButton>
#include "studentloginpage.h"
#include "teacherloginpage.h"

void App::clearWidgetsFromWindow(QWidget* window) {
    // Get the list of child widgets and layouts of the window
    QObjectList children = window->children();

    // Iterate through each child
    for (QObject *child : children) {
        // Remove and delete layouts
        if (QLayout *layout = qobject_cast<QLayout*>(child)) {
            while (QLayoutItem *item = layout->takeAt(0)) {
                if (QWidget *widget = item->widget()) {
                    widget->deleteLater(); // Delete associated widgets
                }
                delete item;
            }
            delete layout; // Delete the layout itself
        }

        // Delete widgets
        if (QWidget *widget = qobject_cast<QWidget*>(child)) {
            widget->deleteLater(); // Delete the widget
        }
    }
}

App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
    teacher=new Teacher;
}

bool App::teacherLogin(QString userName,QString password){
   return  teacher->Verify(userName,password);
}
void App::AddStudent(){
   QString name = QInputDialog::getText(nullptr, "Input Name", "Enter Student name: ");
   int regNo = QInputDialog::getInt(nullptr, "Input Name", "Enter Student name: ");

    StudentDetails* newStu=new StudentDetails(regNo,name);
   StudentMessages* newStuMsgClass=new StudentMessages(newStu);
    stu_msgs.push_back(newStuMsgClass);
}
void App::ExtractAndAddStudent(){



    QFile file("D:\\CS Lab project\\LabProject\\student.txt");

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QVector <QString> name;
        QVector<int> reg;
        int temp;
        QString temp2;
        while(!in.atEnd())
        {
            in>>temp2;
            in>>temp;
            StudentDetails* newStu=new StudentDetails(temp,temp2);
            StudentMessages* newStuMsgClass=new StudentMessages(newStu);
            stu_msgs.push_back(newStuMsgClass);
        }


    }
}

void App::outPutDataToFile(){
    QFile output("D:\\CS Lab project\\LabProject\\applications.txt");
    QTextStream out(&output);
    output.open(QIODevice::WriteOnly | QIODevice::Text);
    Queue qTemp=q1;
    while(!qTemp.isEmpty()){
        Node* node= qTemp.returnFront();
        out<<node->stu->name<<" "<<node->stu->regNo<<" "<< node->app->subject<<" "<<node->app->msg<<"\n";
        qTemp.dequeue();
    }
}
void App::ShowApplications(){
    Queue qTemp=q1;
    window.setWindowTitle("Messages of Students");
    QVBoxLayout *layout = new QVBoxLayout(&window);
    while(!qTemp.isEmpty()){
        Node* app=qTemp.returnFront();
        qDebug()<<"this loop is running";
        if(!app){
            QMessageBox::warning(this,"Application of Students","No application to review ");
        }



        QWidget *messageWidget = new QWidget();
        QHBoxLayout *messageLayout = new QHBoxLayout(messageWidget);

        QLabel *messageLabel = new QLabel("<b style='font-size:larger;text-decoration:underline;' >Student:</b><div style='color:red; '> "+app->stu->name+"("+QString::number(app->stu->regNo)+")</div><br>"+"<b style='font-size:larger;text-decoration:underline'; >Subject:</b> "+app->app->subject+"<br><b style='font-size:larger;'>Message:</b> <br>"+ app->app->msg + "<br>");
        messageLayout->addWidget(messageLabel);

        QRadioButton *radioButtonYes = new QRadioButton("Yes");
        QRadioButton *radioButtonNo = new QRadioButton("No");

        // Connect a slot to radio buttons' toggled signal
        QObject::connect(radioButtonYes, &QRadioButton::toggled, [=]() {
            if(radioButtonYes->isChecked()){
                app->app->isApproved=1;
                q1.RemoveThisNode(app);

            }
        });

        QObject::connect(radioButtonNo, &QRadioButton::toggled, [=]() {
            if (radioButtonNo->isChecked()) {
                app->app->isApproved=-1;
                q1.RemoveThisNode(app);

            }
        });

        messageLayout->addWidget(radioButtonYes);
        messageLayout->addWidget(radioButtonNo);

        layout->addWidget(messageWidget);
        qTemp.dequeue();

    }
    window.setLayout(layout);
    window.show();
}

StudentMessages* App::StudentLogin(int RegNo){
    StudentDetails* stu;
    for(auto stu_msg : stu_msgs){
        stu=stu_msg->searchStudent(RegNo);
        if(stu){
            return stu_msg;
        }
    }
    QMessageBox::warning(this,"No Student","You are not added");
    return nullptr;
}

void App::SubmitApplication(StudentMessages* stu){
    Application* app=new Application;
    // Msg and Subject is taken from the another window
    // and this is added to the submit application

    SubmitApp submitApp; // Create an instance of the SubmitApp window

    // Show the SubmitApp window
    submitApp.exec();

    // Get the subject and message from SubmitApp
    QPair<QString, QString> subjectAndMessage = submitApp.getData();

    // Use the received subject and message as needed
    QString sub = subjectAndMessage.first;
    QString msg = subjectAndMessage.second;
    app->subject=sub;
    app->msg=msg;
    stu->addApplication(app);
    q1.enqueue(app,stu->getStudentDetails());
}

void App::ShowMeMyApplication(StudentMessages *stu){

    QVector<Application*> apps=stu->getApp();
    QString str="";
    int count=0;
    for(auto app : apps){
        str+=QString::number(count)+") <b>Subject</b>: "+app->subject;
        str+="<br><b style= font-size:large; >Message:</b> <br>"+app->msg;
        str+="<br><i style=text-align:right;>"+app->ApprovedOrNot()+" </i>";
        str+="<br><br>";
        count++;
    }
    QMessageBox::information(this,"Your Messages",str);


}




int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    App window;
    window.show();
    return app.exec();
}

void App::on_pushButton_3_clicked()
{
    clearWidgetsFromWindow(&window);
    StudentLoginPage student_login_page;
    student_login_page.exec();
    QPair<QString,int> NameAndRegNo=student_login_page.getNameAndRegNo();
    StudentMessages* currStu;
    currStu=StudentLogin(NameAndRegNo.second);


    if(!currStu) return;
    StudentMenu stu_menu;
    stu_menu.changeTheLabel("Welcome " + currStu->stu->name + "!");
    stu_menu.exec();
    if(stu_menu.pressedBtn==1){
        SubmitApplication(currStu);
    }
    if(stu_menu.pressedBtn==2){
        ShowMeMyApplication(currStu);
    }


}




void App::on_pushButton_4_clicked()
{
    clearWidgetsFromWindow(&window);
    TeacherLoginPage teacher_login_page;
    teacher_login_page.exec();
    QPair<QString,QString> userNameAndPassword=teacher_login_page.getData();
    bool isOk=teacherLogin(userNameAndPassword.first,userNameAndPassword.second);
    if(!isOk) {
        QMessageBox::warning(this,"Failed to login","Username or password is wrong");
        return;
    }

    TeacherMenu teacher_menu;
    teacher_menu.exec();
    if(teacher_menu.pressedBtn==1){
        QPair<QString,int> nameAndRegNo=teacher_menu.getNameAndRegNo();
        // QString password=teacher_menu.getPassword();
        StudentDetails* stu=new StudentDetails(nameAndRegNo.second,nameAndRegNo.first);
        StudentMessages* newStu=new StudentMessages(stu);
        stu_msgs.push_back(newStu);

    }
    if(teacher_menu.pressedBtn==2){
        ShowApplications();

    }
    if(teacher_menu.pressedBtn==3){
        ExtractAndAddStudent();
    }
    if(teacher_menu.pressedBtn==4){
        outPutDataToFile();
    }


}




