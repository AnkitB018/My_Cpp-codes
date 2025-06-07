#include<iostream>
using namespace std;

class complex;

class calculator{
    public:
    int sum_realofcomplex(complex o1 , complex o2);

};

class complex{
        int a,b;
        friend complex add_complex(complex o1 , complex o2);
        friend class calculator;
    public:
        void set_data(){
            cout<<"Enter value of a: ";
            cin>>a;
            cout<<"Enter value of b: ";;
            cin>>b;
            cout<<"Value set. "<<endl;
        }
        void get_data(){
            cout<<"value is: "<<a<<"+"<<b<<'i'<<endl;
        }
};

int calculator::sum_realofcomplex(complex o1 , complex o2){
    return (o1.a+o2.a);
}

complex add_complex(complex o1 , complex o2){
    complex o3;
    o3.a = o1.a+o2.a;
    o3.b = o1.b+o2.b;
    return o3; 
}


int main(){
    complex c1 , c2;
    c1.set_data();
    c1.get_data();
    c2.set_data();
    c2.get_data();

    complex c3 = add_complex(c1 , c2);
    cout<<"Added value of new complex number is: ";
    c3.get_data();
    calculator c4;
    int j = c4.sum_realofcomplex(c3,c1);
    cout<<j;
    return 0;
}