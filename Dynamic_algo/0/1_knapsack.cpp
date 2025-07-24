#include<iostream>
#include<vector>
using namespace std;

//just recursion one
int knap(vector<int>p, vector<int>w, int n, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(m<w[n]){
        knap(p, w, n-1, m);
    }
    int yes = knap(p, w, n-1, m-w[n]) + p[n];
    int no = knap(p, w, n-1, m);
    return yes>no?yes:no;
    
}

//upgrading using memoization
int knap_memoization(vector<int>p, vector<int>w, int n, int m, vector<vector<int>>&T){
    if(n == 0 || m ==0){
        T[n][m] = 0;
        return 0;
    }
    if(T[n][m] != -1){
        return T[n][m];
    }

    if(w[n]>m){
        T[n][m] = knap_memoization(p,w,n-1,m,T);
        return T[n][m];
    }

    int yes = knap_memoization(p,w, n-1, m-w[n], T) + p[n];
    int no = knap_memoization(p,w,n-1, m, T);
    T[n][m] = yes>no?yes:no;
    return T[n][m];

}

int knap_tabulation(vector<int>p, vector<int>w, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(w[i]>j){
                dp[i][j] = dp[i-1][j];
            }
            int a = dp[i-1][j];
            int b = dp[i-1][j-w[i]] + p[i];
            dp[i][j] = a>b?a:b;
        }
    }

    return dp[n][m];
}



int main(){
    vector<int>profit = {0,6,5,3,8}; //not using the 0th index
    vector<int>weight = {0,1,2,1,2};
    int n= profit.size();
    int m = weight.size();
    vector<vector<int>> helper(n+1, vector<int>(m+1, -1)); 
    int ans = knap_tabulation(profit, weight, 4, 5);

    cout<<ans;
return 0;
}