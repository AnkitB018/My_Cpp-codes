#include<iostream>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int a,b;
        cin>>a>>b;
        int xor_sum = 0;
        if(a%4 == 1){
            xor_sum = a-1;
        }else if(a%4 == 2){
            xor_sum = 1;
        }else if(a%4 == 3){
            xor_sum = 1 ^ (a-1);
        }else{
            xor_sum = 0;
        }

        if(xor_sum == b){
            cout<<a<<endl;
        }else if((xor_sum ^ b) == a){
            cout<<(a+2)<<endl;
        }else{
            cout<<(a+1)<<endl;
        }

    }


    return 0;
}