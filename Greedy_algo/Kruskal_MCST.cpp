#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class disjoint_set{
    public:
        int n;
        int *arr;
        disjoint_set(int size){
            n = size;
            arr = new int[n];
            for(int i=0 ; i<n ; i++){
                arr[i] = -1;
            }
        }

        ~disjoint_set(){
            delete [] arr;
        }

        int find(int u){
            int x = u;
            while(arr[x]>0){
                x = arr[x];
            }
            return x;
        } 

        void Union(int u, int v){
            if(find(u) == find(v)){
                return;
            }
            int x = find(u);
            arr[x] = v;
        }


};

int kruskal_MCST(vector<vector<int>>edges, int n){ //without using heap in O(n.e) time and O(e + n) space
    int min_cost =0;
    int idx=-1;
    int u=-1;
    int v=-1;
    int edge_count = 0;
    vector<int>visited(edges.size(),0);
    disjoint_set ds(n+1); //we start vertice number from 1 so 0th position in set is not used
    while(edge_count<n-1){

        int cost = 100000;
        for(int i=0 ; i<edges.size() ; i++){
            if(edges[i][2]<cost && visited[i] == 0){
                cost = edges[i][2];
                idx = i;
            }
        }


        u=edges[idx][0];
        v=edges[idx][1];
        if(ds.find(u) == ds.find(v)){
            visited[idx] = 1;
            continue;
        }

        min_cost+=edges[idx][2];
        edge_count++;
        ds.Union(u,v);   
        visited[idx] = 1;
    }

    return min_cost;

}

int kruskal_MCST_using_heap(vector<vector<int>>edges, int n){
        auto cmp = [](const vector<int>&a, const vector<int>&b){
            return a[2]>b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>,decltype(cmp)>min_heap(cmp, edges);
        int total_cost=0;
        int edge_count=0;
        disjoint_set ds(n+1);
        while(edge_count<n-1){
            int i = min_heap.top()[0];
            int j= min_heap.top()[1];
            int cost = min_heap.top()[2];
            min_heap.pop();
            if(ds.find(i) == ds.find(j)){
                continue;
            }
            ds.Union(i, j);
            total_cost +=cost;
            edge_count++;
        }

        return total_cost;
}

int main(){
    vector<vector<int>> edges = {{1,2,28},{1,6,10},{2,3,16},{2,7,14},{3,4,12},{4,5,22},{4,7,18},{5,6,25},{5,7,24}};
    int min_cost = kruskal_MCST(edges, 7);
    int min_cost1 = kruskal_MCST_using_heap(edges, 7);
    cout<<min_cost<<endl;
    cout<<min_cost1<<endl;
    
return 0;

//add kruskal using heap
}