#include<iostream>
using namespace std;

class base{
    public:
        base(){
            cout<<"IN base"<<endl;
        }

};

class base2{
    public:
        base2(){
            cout<<"IN base2"<<endl;
        }
};

class derived: public base2 , public base{
    public:
        derived(){
            cout<<"IN derived"<<endl;
        }

};

int main(){
    derived d;
    return 0;
}