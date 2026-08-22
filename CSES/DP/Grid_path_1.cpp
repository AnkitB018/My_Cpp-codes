#include<iostream>
#include<vector>


using namespace std;

long long MOD = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<char>>grid;
    for(int i=0 ; i<n ; i++){
        vector<char>temp;
        for(int j=0 ; j<n ; j++){
            char in;
            cin>>in;
            temp.push_back(in);
        }
        grid.push_back(temp);
    }

    vector<vector<int>>dp(n, vector<int>(n, 0));
    dp[n-1][n-1] = grid[n-1][n-1] == '*'? 0:1;

    for(int i=n-1 ; i>=0 ; i--){
        for(int j=n-1; j>=0 ; j--){
            if(grid[i][j] == '*'){
                continue;
            }
            if(i-1 >=0 ){
                if(grid[i-1][j] == '*'){
                    dp[i-1][j] = 0;
                }else{
                    dp[i-1][j] = (dp[i-1][j] + dp[i][j])  % MOD;
                }
            }
            if(j-1 >=0 ){
                if(grid[i][j-1] == '*'){
                    dp[i][j-1] = 0;
                }else{
                    dp[i][j-1] = (dp[i][j-1] + dp[i][j]) % MOD;
                }
            }
        }
    }

    cout<<dp[0][0]<<endl;



    return 0;
}