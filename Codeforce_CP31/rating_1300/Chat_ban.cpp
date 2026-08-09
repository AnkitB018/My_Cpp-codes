#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long k,x;
        cin>>k>>x;

        long long l = 1;
        long long r = k;
        while(l<=r){
            long long mid = l+(r-l)/2;
            long long total = (mid*(mid+1))/2;
            if(total < x){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        if(l == k+1){
            l--;
        }
        long long done = (l*(l+1))/2LL;
        if(done >= x){
            cout<<l<<endl;
            continue;
        }

        l = 1;
        r = k-1;
        while(l<=r){
            long long mid = l+(r-l)/2;
            long long num = k-1-mid+1;
            long long total = num*(k-1 + mid)/2;
            total += done;
            if(total < x){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        if(r == 0){
            cout<<2*k-1<<endl;
        }else{
            long long extra = k-r;
            cout<<extra + k <<endl;
        }


    }


    return 0;
}