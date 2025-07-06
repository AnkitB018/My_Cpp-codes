#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int optimal_merge_pattern(vector<int>cost){
    priority_queue<int , vector<int>, greater<int>> heap(cost.begin(), cost.end());
    int ans=0;
    while(heap.size() >1){
        int i = heap.top(); heap.pop();
        int j = heap.top(); heap.pop();
        ans+=i+j;
        heap.push(i+j);
    }

    return ans;

}


int main(){
    vector<int>lists = {8,3,4,6,5}; 
    int ans = optimal_merge_pattern(lists);
    cout<<ans;

return 0;
}