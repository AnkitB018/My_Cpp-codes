#include<iostream>

using namespace std;

bool fair(long long n){
    long long temp = n;
    while(temp>0){
        int rem = temp%10;
        if(rem!=0 && n%rem != 0){
            return false;
        }
        temp = temp/10;
    }
    return true;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;

        while(!fair(n)){
            n++;
        }

        cout<<n<<endl;

    }


}