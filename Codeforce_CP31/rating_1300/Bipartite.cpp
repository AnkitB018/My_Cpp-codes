#include<iostream>
#include<vector>

using namespace std;

void DFS(int start, vector<vector<int>>&adj_list ,vector<int>&s1, vector<int>&s2,bool turn, vector<int>&vis){
    if(turn){
        s1.push_back(start);
    }else{
        s2.push_back(start);
    }

    vis[start] = 1;

    for(auto &ele:adj_list[start]){
        if(vis[ele] == 1){
            continue;
        }
        DFS(ele, adj_list, s1, s2, !turn, vis);
    }
}

int main(){
    long long n;
    cin>>n;

    vector<vector<int>>adj_list(n+1);
    for(int i=1 ; i<n ; i++){
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int>s1;
    vector<int>s2;
    vector<int>vis(n+1, 0);

    DFS(1, adj_list, s1, s2, true, vis);

    long long ans = s1.size() * s2.size() - (n-1);

    cout<<ans<<endl;



    return 0;
}