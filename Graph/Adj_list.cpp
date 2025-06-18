#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class graph{
    public:
        Node* arr;
        int size;

        graph(int vertice){
            size = vertice;
            arr = new Node[size];
            for(int i=0 ; i<size ; i++){
                arr->next = NULL;
            }
        }

        void create(){
            Node *add;
            Node *aux;
            int key;
            for(int i=0 ; i<size ; i++){
                int temp;
                cout<<"Enter number of Nodes connected to Node "<<i<<": ";
                cin>>temp;
                aux = (arr+i);
                while(temp--){
                    cout<<"Enter Node connected to Node "<<i<<": ";
                    cin>>key;
                    add = new Node;
                    add->data = key;
                    add->next = NULL;
                    aux->next = add;
                    aux = aux->next;
                }
                cout<<endl;
            }
        }

        void create_from_matrix(vector<vector<int>>a){
            Node *temp;
            Node *add;
            for(int i=0 ; i<size ; i++){
                temp = (arr+i);
                for(int j=0 ; j<size ; j++){
                    if(a[i][j] == 0){
                        continue;
                    }
                    add = new Node;
                    add->data = j;
                    add->next = NULL;
                    temp->next = add;
                    temp = temp->next;
                }
            }            
        }

        void show(){
            Node *temp;
            for(int i=0 ; i<size ; i++){ 
                temp = (arr+i)->next;
                cout<<i<<": ";
                while(temp){
                    cout<<temp->data<<"->";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        void DFS(int i){
            static vector<int>visited(size , 0);
            cout<<i<<"  ";
            visited[i] = 1;
            Node *temp = (arr+i)->next;
            while(temp){
                if(visited[temp->data] == 1){
                    temp = temp->next;
                    continue;
                }
                DFS(temp->data);
                temp = temp->next;
            }
        }

        void BFS(int i){
            vector<int>visited(size, 0);
            int u;
            queue<int>q;
            cout<<i<<"  ";
            visited[i] = 1;
            Node *temp;
            q.push(i);
            while(!q.empty()){
                u = q.front();
                q.pop();
                temp = arr[u].next;
                while(temp){
                    if(visited[temp->data]==1){
                        temp = temp->next;
                        continue;
                    }
                    visited[temp->data] = 1;
                    q.push(temp->data);
                    cout<<temp->data<<"  ";
                    temp = temp->next;
                }
            }
            cout<<endl;
        }

};


int main(){
    graph g(7);
    vector<vector<int>>a = {
                   {0, 1, 1, 1, 0, 0, 0},
                   {1, 0, 1, 0, 0, 0, 0},
                   {1, 1, 0, 1, 1, 0, 0},
                   {1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    g.create_from_matrix(a);
    g.DFS(4);
    cout<<endl;
    g.BFS(4);


return 0;
//perfect
}