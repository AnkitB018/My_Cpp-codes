#include<iostream>
using namespace std;

class Employee{
    private:
        int salary, id;
    public:
        string name , dept;
    void set_data(string name , string dept ,int salary , int id){
        salary = salary;
        name = name;
        dept = dept;
        id=id;
        cout<<"Data Set "<<endl;
    } 
    void get_data();

};

void Employee :: get_data(){
    cout<< "name is "<<name<<endl;
    cout<< "dept is "<<dept<<endl;
    cout<< "salary is "<<salary<<endl;
    cout<< "id is "<<id<<endl;
} 


int main(){
    Employee e1;
    e1.set_data("Ankit" , "IT" , 10000000 , 120220);
    e1.get_data();
    return 0;
}