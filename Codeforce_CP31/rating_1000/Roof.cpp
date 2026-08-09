#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

int main(){
    int test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        n--;
        vector<ll>ans;
        ll msb = log2(n);
        int highest = pow(2,msb);
        int num = highest -1;
        while(num>=0){
            cout<<num<<" ";
            num--;
        }
        cout<<highest<<" ";
        num = highest +1;
        while(num <= n){
            cout<<num<<" ";
            num++;
        }

        cout<<endl;

    }


    return 0;
}