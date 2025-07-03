#include<iostream>
#include<vector>
#include <climits>
using namespace std;

vector<vector<int>> edge_cost_to_adj_mat(vector<vector<int>>a, int n){
    vector<vector<int>>res(n+1 , vector<int>(n+1,INT_MAX));
    for(int i=0 ; i<a.size() ; i++){
        res[a[i][0]][a[i][1]] = a[i][2];
        res[a[i][1]][a[i][0]]= a[i][2];
    }
    for(int i=0 ; i<=n ; i++){
        res[i][i] = 0;
    }
    return res;
}

int Prims_MCST(vector<vector<int>>edges, int n){ // O(n^2) time and O(n)space
    vector<int>near(n+1 , 0);
    vector<int>selected(n+1,0);
    int u,v;
    u=1;
    int min_cost=0;
    int min = INT_MAX;

    //initialization begins
    for(int i=2 ; i<=n ; i++){
        if(edges[1][i] < min){
            min = edges[1][i];
            v = i;
        }
    }

    min_cost +=edges[u][v];
    selected[u] = selected[v] = 1;
    for(int i=1 ; i<=n ; i++){
        if(selected[i]==0){
            if(edges[u][i] < edges[v][i]){
                near[i] = u;
            }else{
                near[i] = v;
            }
        }
    }
    //initialization ends

    for(int j=1 ; j<=n-2 ; j++){
        min = INT_MAX;
        for(int i=1 ; i<=n ; i++){
            if(selected[i] == 0 && edges[i][near[i]] < min){
                min = edges[i][near[i]];
                v = i;
            }
        }

        u = near[v];
        min_cost += edges[u][v];
        selected[v] = 1;

        for(int i=1 ; i<=n ; i++){
            if(selected[i] == 0 && edges[v][i] < edges[near[i]][i]){
                near[i] = v;
            }
        }

    }

    return min_cost;
    

}


int main(){
    vector<vector<int>> edge = {{1,2,28},{1,6,10},{2,3,16},{2,7,14},{3,4,12},{4,5,22},{4,7,18},{5,6,25},{5,7,24}};
    vector<vector<int>> edges = edge_cost_to_adj_mat(edge , 7);
    int res = Prims_MCST(edges, 7);

    cout<<res;

return 0;
}