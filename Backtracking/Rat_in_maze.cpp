#include<iostream>
#include<vector>
using namespace std;

int N=7;                 //  0  1  2  3  4  5  6
vector<vector<int>>maze = { {1, 1, 1, 0, 1, 1, 1},
                            {0, 1, 0, 1, 0, 0, 1},
                            {0, 1, 0, 1, 1, 0, 1},
                            {1, 1, 1, 0, 1, 0, 1},
                            {1, 0, 0, 0, 1, 0, 0},
                            {1, 1, 1, 0, 1, 1, 1},
                            {0, 0, 1, 1, 1, 0, 1} }; // 0 means blocked and 1 means open

vector<vector<int>> sol(2, vector<int>((N)*(N), 0));
int path = 0;

void Rim(int i, int j){
    if(i == N-1 && j == N-1){
        for(int i=0 ; i<path ; i++){
            cout<<sol[0][i]<<" ";
        }
        cout<<endl;
        for(int i=0 ; i<path ; i++){
            cout<<sol[1][i]<<" ";
        }
        cout<<endl;
        return;
    } 
    maze[i][j] = 0; //block the current cell
    sol[0][path] = i;
    sol[1][path] = j;
    path++;
    if(j<N-1 && maze[i][j+1] == 1){
        Rim(i,j+1);
    }
    if(i<N-1 && maze[i+1][j] == 1){
        Rim(i+1, j);
    }
    if(j>0 && maze[i][j-1] == 1){
        Rim(i, j-1);
    }
    if(i>0 && maze[i-1][j] == 1){
        Rim(i-1, j);
    }
    maze[i][j] = 1;
    path--;

}


int main(){
    Rim(0,0);
return 0;
}