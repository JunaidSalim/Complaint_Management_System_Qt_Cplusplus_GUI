#include<iostream>
#include<vector>
using namespace std;


class StudentMessage{
        private:
        int approved;
        public:
        string Subject;
        string msg;

        int isApproved(){
            return approved;
        }
            
};
class StudentInfo{
    private:
    vector<StudentMessage*> msgs;
    public:
    string name;
    double regNo;

    void AllMessages(){
        cout<<"\n\t\tThe Applications of: "<<name<<"("<<regNo<<") are:\n";
        int count=0;

        for(auto msg: msgs){
            cout<<"\nMessage ID is: "<<count;
            cout<<"\nSubject : "<<msg->Subject<<endl;
            cout<<"\nMessage : \n"<<msg->msg<<endl;
            if(msg->isApproved()==1){
                cout<<"\nThis message is Approved."<<endl;
            }
            else if(msg->isApproved()==0){
                cout<<"\nThis message is Declined."<<endl;
            }
            else{
                cout<<"\nUntill it is not reviewed";
            }
            count++;
        }
    }
    void ShowNotReviewedApplication(){
        cout<<"\n\t\tThe Not Reviewed Application of: "<<name<<"("<<regNo<<") are:\n";
        int count=0;
        for(auto msg:msgs){
            if(msg->isApproved()!=0 && msg->isApproved()!=1){
                cout<<"\nMessage ID is: "<<count;
                cout<<"\nSubject : "<<msg->Subject<<endl;
                cout<<"\nMessage: \n"<<msg->msg;
            }
            count++;
        }
    }

};

class Teacher{
    private:
    //These will be stored in the file and this user name and password will be taken to verify ;
    string userName;
    string password;

    public:
    bool verify(string userName,string password){
        return this->userName==userName && this->password==password;
    }
    bool resetNameAndPass(string userName,string password,string NewuserName,string Newpassword){
        if (this->verify(userName,password)){
            newNameAndPassword(NewuserName,Newpassword);
        }
    }
    void newNameAndPassword(string NewuserName,string Newpassword){
        this->userName=NewuserName;
        this->password=Newpassword;
        cout<<"\nYour userName and password has been reseted";
    }
    void showMeAllAplication(vector<StudentInfo> stuArr){
        for(auto stu:stuArr){
            stu.ShowNotReviewedApplication();
        }
    }



      

};




int main(){



}