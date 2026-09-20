#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>rows(100001);
    vector<vector<int>>cols(100001);

    for(int i=0 ;i<n ; i++){
        for(int j=0; j<m ; j++){
            int temp;
            cin>>temp;
            rows[temp].push_back(i);
            cols[temp].push_back(j);
        }
    }

    long long ans = 0;
    long long row_diff = 0;
    long long col_diff = 0;
    for(int i=0 ; i<rows.size() ; i++){
        if(rows[i].size()  <= 1){
            continue;
        }

        sort(rows[i].begin(), rows[i].end());
        int k= rows[i].size();
        for(int j=0 ; j<k ; j++){
            row_diff += rows[i][j]*(2LL*j-k+1);
        }

    }

    for(int i=0; i<cols.size() ; i++){
        if(cols[i].size() <= 1){
            continue;
        }
        sort(cols[i].begin(), cols[i].end());
        int k = cols[i].size();
        for(int j=0 ; j<k ; j++){
            col_diff += cols[i][j]*(2LL*j-k+1);
        }
    }

    ans = row_diff + col_diff;
    cout<<ans<<endl;

}