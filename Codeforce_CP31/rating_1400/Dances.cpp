#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;

        vector<long long>a(n,1);
        vector<long long>b(n);

        for(int i=1 ; i<n ; i++){
            cin>>a[i];
        }

        for(int i=0 ; i<n ; i++){
            cin>>b[i];
        }

        sort(b.begin(), b.end());
        sort(a.begin(), a.end());

        int ans = n;
        int l = 0;
        int r = n-1;
        for(int i=0 ; i<n ; i++){
            long long val = a[i];
            r = n-1;
            while(l <= r){
                int mid = l+(r-l)/2;

                if(b[mid] <= val){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }

            if(l<n){
                ans--;
            }

            l++;
            if(l >= n){
                break;
            }

        }

        cout<<ans<<endl;

    }


    return 0;
}