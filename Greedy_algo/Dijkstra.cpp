#include<iostream>
#include<vector>
#include<climits>
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


//relaxation -> d[u] + cost[u,v] < d[v]
//O(n^2) if adj matrix is used, O(n.e) if adj list is used 
//O(n) space required
vector<int> dijkstra(vector<vector<int>>cost, int n, int s){
    vector<int>d(n+1, INT_MAX); //distance from each vertex to s
    vector<int>selected(n+1 , 0);
    selected[s] = 1;

    for(int i=1 ; i<=n ; i++){
        d[i] = cost[s][i];
    }

    int min;
    int v;
    for(int k=1 ; k<n ; k++){
        min = INT_MAX;
        bool found = false;

        for(int i=1; i<=n ; i++){
            if(d[i] < min && selected[i] == 0){
                min = d[i];
                v=i;
                found = true;
            }   
        }
        if(!found){
            break;
        }
        selected[v] = 1;

        for(int i=1 ; i<=n ; i++){
            if(selected[i] ==0 && d[v] + cost[v][i] < d[i] && cost[v][i] != INT_MAX){
                d[i] = d[v] + cost[v][i];
            }
        }

    }

    return d;
}


int main(){
    vector<vector<int>> edge = {{1,2,28},{1,6,10},{2,3,16},{2,7,14},{3,4,12},{4,5,22},{4,7,18},{5,6,25},{5,7,24}};
    vector<vector<int>> edges = edge_cost_to_adj_mat(edge , 7);

    vector<int> SSSP = dijkstra(edges , 7, 1);

    for(int i=1 ; i<=7 ; i++){
        cout<<i<<" : "<<SSSP[i]<<endl;
    }

return 0;
}