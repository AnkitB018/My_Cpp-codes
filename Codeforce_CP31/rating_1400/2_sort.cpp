#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<int>vec(n);
    for(int i=0 ; i<n ; i++){
        cin>>vec[i];
    }

    int i=0;
    int j=1;
    int ans = 0;
    int len;

    while(j < n){
        if(vec[j]*2 > vec[j-1]){
            j++;
        }else{
            len = j-i;
            ans += max(0, len-k);
            i=j;
            j++;
        }
    }

    len = j-i;
    ans += max(0, len-k);

    cout<<ans<<endl;

}

int main(){
    int tests;
    cin>>tests;

    while(tests--){
        solve();
    }


    return 0;
}