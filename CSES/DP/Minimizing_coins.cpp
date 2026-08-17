#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);

    for(int i=0 ; i<n ; i++){
        cin>>coins[i];
    }

    vector<int>dp(x+1, INT_MAX);

    dp[0] = 0;
    for(int i=0 ; i<=x ; i++){
        if(dp[i] == INT_MAX){
            continue;
        }

        for(int j=0 ; j<n ; j++){
            if(i + coins[j] <= x){
                dp[i+coins[j]] = min(dp[i+coins[j]], dp[i] + 1);
            }
        }
    }

    if(dp[x] == INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<dp[x]<<endl;
    }

    

    return 0;
}