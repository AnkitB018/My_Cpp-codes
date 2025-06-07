#include<iostream>
using namespace std;

class complex{
    int real , complex;
    public:
        void set_data(int a , int b){
            real = a;
            complex = b;
        }
        void print_data();
};
 
void complex :: print_data(){
    cout<<"The complex number is: "<<real<<"+"<<complex<<"i"<<endl;
}

int main(){
    complex *a = new complex[2];
    cout<<sizeof(*a)<<endl;
    (a+1)->set_data(7,4);
    (&a[1])->print_data();
    complex *ptr = new complex;
    ptr->set_data(1,5);
    (*ptr).print_data();
    return 0;
}