#include<iostream>
#include<vector>

using namespace std;

void DFS(vector<int>& visited,
         int lastEdge,
         int reads,
         vector<vector<pair<int,int>>>& adj_list,
         int start,
         int &ans)
{
    visited[start] = 1;
    ans = max(ans, reads);

    for(auto &ele : adj_list[start]){
        int val = ele.first;
        int idx = ele.second;

        if(visited[val]) continue;

        if(idx < lastEdge)
            DFS(visited, idx, reads + 1, adj_list, val, ans);
        else
            DFS(visited, idx, reads, adj_list, val, ans);
    }
}

void solve(){
    int n;
    cin >> n;

    vector<vector<pair<int,int>>> adj_list(n+1);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back({v,i});
        adj_list[v].push_back({u,i});
    }

    vector<int> visited(n+1,0);

    int ans = 1;
    DFS(visited, -1, 1, adj_list, 1, ans);

    cout << ans << '\n';
}

int main(){
    int T;
    cin >> T;
    while(T--)
        solve();
}