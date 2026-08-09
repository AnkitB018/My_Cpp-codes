#include<iostream>
#include<cmath>

using namespace std;

int log_base(long long base, long long val){
    int cnt = 0;
    long long p = 1;

    while(p <= val / base){
        p *= base;
        cnt++;
    }

    return cnt;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        long long a,b;
        cin>>a>>b;
        int move = 0;
        if(b == 1){
            b++;
            move++;
        }
        while(true){
            int first = log_base(b,a)+1;
            int sec = log_base(b+1, a)+1;
            if(first-sec >=1){
                b++;
                move++;
                continue;
            }
            break;
        }

        move += log_base(b,a)+1;
        cout<<move<<endl;

    }


    return 0;
}