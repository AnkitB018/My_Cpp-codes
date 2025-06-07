#include<iostream>
using namespace std;

int sum(int *a){
    *a = *a+5;
    return *a;
}

void swap(int *a , int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main(){
    int a,b;
    cout<<"Enter value of a: ";
    cin>>a;
    cout<<"Enter value of b: ";
    cin>>b;
    cout<<"Values before swap :\n A:"<<a<<"\n B:"<<b<<"\n";
    swap(&a , &b);
    cout<<"Values after swap :\n A:"<<a<<"\n B:"<<b<<"\n";
    cout<<"Hello World!";
    return 0;
}