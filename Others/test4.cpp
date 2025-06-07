#include<iostream>
using namespace std;

void fib(int n){
    static int f = 0;
    static int s = 1;
    static int loop = 0;
    if(loop == 0){
        cout<<f<<" " ;
    }
    cout<<s<<" " ;
    loop++;
    int temp = f;
    f = s;
    s = s+temp;
    ;
    if(loop == n ){
        return;
    }else{
        fib(n);
    }

}


int main(){
    fib(15);
    return 0;
}