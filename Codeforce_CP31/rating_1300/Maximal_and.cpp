#include<iostream>
#include<vector>

using namespace std;

void bits(vector<int>&set, vector<int>&nums){
    for(auto ele:nums){
        for(int i=0 ; i<=30 ; i++){
            if(ele & 1){
                set[i]--;
            }
            ele = ele>>1;
        }
    }
}

long long pow(long long base, long long exp){
    long long res = 1;
    while(exp){
        if(exp & 1){
            res = base * res;
        }

        base = base * base;
        exp = exp >>1;
    }

    return res;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        vector<int>set(31, n);
        bits(set, vec);
        long long ans = 0;
        for(int i=30 ; i>=0; i--){
            if(set[i] <= k){
                k-=set[i];
                ans = ans | pow(2LL, 1LL*i);
            }
        }

        cout<<ans<<endl;


    }

    return 0;
}