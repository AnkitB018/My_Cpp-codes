#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class graph{
    public:
        int vertices;
        vector<vector<int>>g;
        graph(int vertice){
            this->vertices = vertice;   
        }

        void create(vector<vector<int>>copy){
            g = copy;
        }

        void BFS(int i){
            queue<int> q;
            vector<int>visited(vertices+1 , 0);
            int u=i;
            cout<<u<<"  ";
            visited[u] = 1;
            q.push(u);
            while(!q.empty()){
                u = q.front();
                q.pop();
                for(int v=1 ; v<vertices+1 ; v++){
                    if(g[u][v]==1){
                        if(visited[v] == 1){
                            continue;
                        }
                        cout<<v<<"  ";
                        visited[v]=1;
                        q.push(v);
                    }   
                }
            }
            cout<<endl;
        }

        void DFS(int i){
            static vector<int>visited(vertices+1,0);
            cout<<i<<"  "; 
            visited[i] = 1;
            for(int j=1; j<vertices+1 ; j++){
                if(g[i][j] == 1 && visited[j] == 0){
                    DFS(j);
                }
            }
        }

};


int main(){
    graph g(7);
    vector<vector<int>>a = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    g.create(a);
    g.BFS(6);
    g.DFS(6);
    cout<<endl;

return 0;
}