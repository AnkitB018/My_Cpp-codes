#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int Lcs(string &s1, string &s2, int i, int j){ // time- O(2^N)
    if(i ==0 || j ==0){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1+ Lcs(s1, s2, i-1, j-1);
    }

    int a= Lcs(s1, s2, i-1, j); 
    int b= Lcs(s1, s2, i, j-1);
    return a>b?a:b;
}

int Lcs_mem(string &s1, string &s2, int i, int j, vector<vector<int>>&dp){ // time- O(m*n)
    if(i ==0 || j==0){
        dp[i][j] = 0;
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        dp[i][j] = Lcs_mem(s1, s2, i-1, j-1, dp)+1;
    }else{
        int a= Lcs(s1, s2, i-1, j); 
        int b= Lcs(s1, s2, i, j-1);
        dp[i][j] = a>b?a:b;
    }

    return dp[i][j];

}



vector<vector<int>> Lcs_itr(string &s1, string &s2){
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), 0));
    for(int i=1 ; i<s1.length() ;i++){
        for(int j=1 ; j<s2.length(); j++){
            if(s1[i] == s2[j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp;
}


int main(){
    string a= " ace"; //not using the 0th index
    string b= " abcde";
    int n= a.length()+1;
    int m = b.length()+1;
    vector<vector<int>> dp1(n, vector<int>(m, -1));
    int ans = Lcs_mem(a,b,a.length()-1, b.length()-1, dp1);

    vector<vector<int>>dp = Lcs_itr(a,b);
    for(int i=0 ; i<dp.size() ; i++){
        for(int j=0 ; j<dp[0].size() ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<ans;

return 0;
}
