#include<iostream>
using namespace std;

void check_something(int **a){
    int b = 5;
    *a = &b;
}

int main(){
    int *ptr;
    int *p = new int[5];
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    p[4] = 4;
    check_something(&ptr);
    delete &p[4];
    for(int i = 0 ; i<5;i++){
        cout<<p[i]<<endl; 
    }
    
    return 0;
}