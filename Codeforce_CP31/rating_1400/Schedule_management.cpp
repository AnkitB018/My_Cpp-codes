#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long num_comp(vector<int>&pr, int t){
    long long done = 0;
    for(int i=0 ; i<pr.size() ; i++){
        done += min(t, pr[i]+(t-pr[i])/2);
    }

    return done;
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int>pr(n, 0);

    for(int i=0 ; i<m ; i++){
        int temp;
        cin>>temp;
        pr[temp-1]++;
    }

    int l = 1;
    int r = m;

    while(l <= r){
        int mid = l+(r-l)/2;
        if(num_comp(pr, mid) >= m){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<l<<endl;

}

int main(){
    int tests;
    cin>>tests;
    while(tests--){
        solve();
    }


    return 0;
}