#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;

        k--;
        if(n%2==0){
            cout<<(k%n+1)<<endl;
        }else{
            int val = n/2;
            int real = ((k+(k/val))%n)+1;
            cout<<real<<endl;
        }
    }


    return 0;
}