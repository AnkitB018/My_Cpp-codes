#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1 ; i<=n ; i++){
        string temp = to_string(i);
        for(char c:temp){
            int dig = c - '0';
            if(dig == 0){
                continue;
            }
            dp[i] = min(dp[i], dp[i-dig] +1 );
        }
    }

    cout<<dp[n]<<endl;
    

    return 0;
}