#include<iostream>
using namespace std;

class Employee{
    public:
        int id;
        string name;
        void set_data(){
            cout<<"Enter name: " << endl;
            cin>>name;
            cout<<"Enter id: "<< endl;
            cin>>id;
        }
        void disp_data();
};

class Programmer : public Employee{
    public:
        int pg_id;
        int dept;
};

void Employee :: disp_data(){
        cout<<"Name of Employee :"<<name<<endl;
        cout<<"Id of Employee :"<<id<<endl;
}

int main(){
    Programmer p1 , p2 ;
    p1.set_data();
    p2.set_data();
    p1.disp_data();
    p2.disp_data();
    return 0;
}