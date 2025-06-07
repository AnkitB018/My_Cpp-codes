#include<iostream>
using namespace std;

class student{
    protected:
        int roll;
    public:
        string name;
        void set_data();
        void get_data();
};

void student :: set_data(){
    cout<<"Input roll number: "<<endl;
    cin>>roll;
    cout<<"Input name: "<<endl;
    cin>>name;
}
void student:: get_data(){
    cout<<"Name of the student is : "<<name <<endl;
    cout<<"Roll of the student is :"<<roll<<endl;
}

class subjects : public student{
    protected:
        float maths;
        float physics;
        float comp;
    public:
        void set_marks(){
            cout<<"input marks in Maths: "<<endl;
            cin>>maths;
            cout<<"Input marks in physics: "<<endl;
            cin>>physics;
            cout<<"Input marks in computer: "<<endl;
            cin>>comp;
        }
        void get_marks(){
            cout<<"marks in Maths: "<<maths<<endl;
            cout<<"marks in physics: "<<physics<<endl;
            cout<<"marks in computer: "<<comp<<endl;
        }
};

class result:subjects{
        int percentage;
    public:
        void set_all(){
            set_data();
            set_marks();
        }
        void get_result(){
            get_data();
            get_marks();
            cout<<"Your result is: "<<(maths+physics+comp)/3<<"%"<<endl;
        }

};

int main(){
    result r1;
    r1.set_all();
    r1.get_result();  
    return 0;
}