#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long a,b;
        cin>>a>>b;
        if(a>b){
            swap(a, b);
        }

        if(b%a != 0){
            cout<<-1<<endl;
            continue;
        }

        long long move =0;
        long long div = b/a;
        while(div%8 == 0){
            div /=8;
            move++;
        }
        
        while(div%4 == 0){
            div /=4;
            move++;
        }

        while(div%2 == 0){
            div /=2;
            move++;
        }

        if(div == 1){
            cout<<move<<endl;
        }else{
            cout<<-1<<endl;
        }


    }


    return 0;   
}