#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mat_mul(int i, int j, vector<int>d){
    if(i == j){
        return 0;
    }
    int min_cost = INT_MAX;
    for(int k= i ; k<j ; k++){
        int cost = mat_mul(i, k, d) + mat_mul(k+1, j, d) + d[i-1]*d[k]*d[j];
        if(cost<min_cost){
            min_cost = cost;
        } 
    }
    return min_cost;
}

//with memoization
int mat_mul_mem(int i, int j, vector<vector<int>>&m, vector<int>&d){
    if(i == j){
        m[i][j] = 0;
        return 0;
    }
    if(m[i][j] != -1){
        return m[i][j];
    }
    m[i][j] = INT_MAX;
    int cost = 0;
    for(int k=i ; k<j ; k++){
        if(m[i][k] == -1){
            m[i][k] = mat_mul_mem(i, k, m, d);
        }
        if(m[k+1][j] == -1){
            m[k+1][j] = mat_mul_mem(k+1, j, m, d);
        }

        cost = m[i][k]+m[k+1][j] + d[i-1]*d[k]*d[j];
        if(cost < m[i][j]){
            m[i][j] = cost;
        }
    }

    return m[i][j];
}

int mat_mul_tabulation(vector<int>&d, int n, vector<vector<int>>&m, vector<vector<int>>&K){
    for(int i=0 ; i<=n ; i++){
        m[i][i] = 0;
    }
    for(int diff = 1 ; diff<n ; diff++){
        for(int i=1 ; i+diff<=n ; i++){
            int j= i+diff;
            m[i][j] = INT_MAX;
            for(int k=i ; k<j ; k++){
                int cost = m[i][k]+m[k+1][j]+d[i-1]*d[k]*d[j];
                if(cost<m[i][j]){
                    m[i][j] = cost;
                    K[i][j] = k;
                }
            }
        }
    }

    return m[1][n];

}

int main(){
    vector<int>d = {3,2,4,2,5};
    int n= d.size();
    vector<vector<int>>m(n, vector<int>(n, -1));
    int cost = mat_mul_mem(1, 4, m, d);
    cout<<cost;
    vector<vector<int>>m1(n, vector<int>(n, -1));
    vector<vector<int>>k(n, vector<int>(n, -1));
    int cost2 = mat_mul_tabulation(d, 4, m1, k);
    cout<<cost2;

return 0;
}