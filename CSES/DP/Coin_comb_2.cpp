#include<iostream>
#include<vector>

using namespace std;

int MOD = 1e9+7;

int main(){
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);
    for(int i=0 ; i<n ; i++){
        cin>>coins[i];
    }

    //vector<vector<int>>dp(n+1, vector<int>(x+1, 0));

    vector<int>nextState(x+1, 0);
    nextState[0] = 1;

    /*for(int i=0 ; i<n ; i++){
        dp[i][0] = 1;
    }*/

    for(int i=n-1; i>=0 ; i--){
        vector<int>currState(x+1, 0);
        currState[0] = 1;
        for(int sum=1 ; sum<=x ; sum++){
            int skip = nextState[sum];
            int taken = 0;
            if(sum >= coins[i]){
                taken = currState[sum-coins[i]];
            }
            currState[sum] = (skip + taken)%MOD;
        }

        nextState = currState;
    }

    cout<<nextState[x]<<endl;


}