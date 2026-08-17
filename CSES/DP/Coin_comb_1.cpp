#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long MOD = 1e9+7;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);
    for(int i=0 ; i<n ; i++){
        cin>>coins[i];
    }

    sort(coins.begin(), coins.end());

    vector<long long>dp(x+1, 0);
    dp[0] = 1;

    for(int i=0 ; i<=x; i++){
        if(dp[i] == 0){
            continue;
        }
        for(int j=0 ; j<n ; j++){
            if(i + coins[j] > x){
                break;
            }
            dp[i + coins[j]] = (dp[i + coins[j]] + dp[i]);
            if(dp[i + coins[j]] >= MOD){
                dp[i + coins[j]] -= MOD;
            }
        }
    }

    cout<<dp[x]<<endl;


    return 0;
}