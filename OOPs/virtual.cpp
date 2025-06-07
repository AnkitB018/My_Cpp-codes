#include<iostream>
using namespace std;

class base{
    int a = 1 ;
    public:
        virtual void display(){
            cout<<"currently in base"<<endl;
        }
};

class derived : public base{
    int b=2;
    public:
        void display(){
            cout<<"Currently in derived "<<endl;
        }
};

int main(){
    base *bptr ;
    derived obj1;
    bptr = &obj1;
    bptr->display();
    return 0;
}