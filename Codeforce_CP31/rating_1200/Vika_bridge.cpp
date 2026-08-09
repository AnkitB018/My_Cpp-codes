#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;

        vector<vector<int>>colors(k+1, vector<int>(1,0));
        for(int i=1 ; i<=n ; i++){
            int temp;
            cin>>temp;
            colors[temp].push_back(i);
        }

        int ans = INT_MAX;
        for(int i=1; i<=k ; i++){
            priority_queue<int>heap;
            colors[i].push_back(n+1);
            for(int j=0 ; j<colors[i].size()-1 ; j++){
                heap.push(colors[i][j+1] - colors[i][j] - 1);
            }

            int max = heap.top();
            heap.pop();
            heap.push(max/2);
            heap.push(max/2-1);
            if(heap.top() < ans){
                ans = heap.top();
            }

        }

        cout<<ans<<endl;

    }
}