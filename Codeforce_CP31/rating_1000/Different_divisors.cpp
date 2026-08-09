#include<iostream>

using namespace std;

bool isPrime(long long a){
    for(long long i=2 ; i*i<=a ; i++){
        if(a%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int d;
        cin>>d;
        long long p=0;
        long long q=0;
        long long i=1+d;
        while(true){
            if(isPrime(i)){
                p=i;
                i+=d;
                break;
            }
            i++;
        }

        while(true){
            if(isPrime(i)){
                q=i;
                break;
            }
            i++;
        }

        cout<<min(1LL * p*p*p, 1LL * p*q)<<endl;



    }

    return 0;
}