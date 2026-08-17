#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    vector<int>nearestenemy(n+1, 0);

    for(int i=0 ; i<m ; i++){
        int l,r;
        cin>>l>>r;
        if(l>r){
            swap(l, r);
        }

        nearestenemy[r] = max(nearestenemy[r], l);
    }

    vector<int>leftbest(n+1, 1);

    for(int i=1 ; i<=n ; i++){
        leftbest[i] = max(nearestenemy[i]+1, leftbest[i-1]);
    }

    long long ans = 0;
    for(int i=1 ; i<=n ; i++){
        ans += (i - leftbest[i] + 1);
    }

    cout<<ans<<endl;

    

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin>>test;

    while(test--){
        solve();
    }

    return 0;
}