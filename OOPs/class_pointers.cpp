#include<iostream>
using namespace std;

class comple{
    int real , complex;
    public:
        void set_data(int a , int b){
            real = a;
            complex = b;
        }
        void print_data();
};
 
void comple :: print_data(){
    cout<<"The complex number is: "<<real<<"+"<<complex<<"i"<<endl;
}

int main(){
    comple*a = new comple[2];
    cout<<sizeof(*a)<<endl;
    (a+1)->set_data(7,4);
    (&a[1])->print_data();
    comple *ptr = new comple;
    ptr->set_data(1,5);
    (*ptr).print_data();
    return 0;
}