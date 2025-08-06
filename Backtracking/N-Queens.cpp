#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;



bool valid(int k, int l, vector<int>pos){
    for(int i=1 ; i<k ; i++){
        if(pos[i] == l || abs(i-k) == abs(pos[i]-l) ){ //diagonal condition-> add or subtract the indices ...same values mean same diagonal (i+j) = (k+l) || (i-j) = (k-l) where j is stored in pos[i]
            return false;
        }
    }
    return true;
}


void n_queen(int n, int k, vector<int>&pos){
    if(k == n+1){
        for(int i=1 ; i<=n ; i++){
            cout<<pos[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1 ; i<= n ; i++){
        if(valid(k, i, pos)){
            pos[k] = i;
            n_queen(n, k+1, pos);
        }
    }
}



int main(){
    int n=8;
    vector<int>pos(n+1, 0);
    n_queen(n, 1, pos);
return 0;
}