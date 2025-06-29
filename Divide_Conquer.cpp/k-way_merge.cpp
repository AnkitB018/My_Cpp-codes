#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> four_way_merge(vector<int>a,vector<int>b,vector<int>c,vector<int>d){
    vector<int>result;
    int i,j,k,h;
    i=j=k=h=0;
    priority_queue<int , vector<int>, greater<int>> heap;
    do{
        if(i<a.size()){heap.push(a[i++]);};
        if(j<b.size()){heap.push(b[j++]);};
        if(k<c.size()){heap.push(c[k++]);};
        if(h<d.size()){heap.push(d[h++]);};
        result.push_back(heap.top());
        heap.pop();
    }while(!heap.empty());
    return result;
}


int main(){
    vector<int>a={1,4,6};
    vector<int>b={2,8,10};
    vector<int>c={7,11,13};
    vector<int>d={3,5,18};

    vector<int>ans;
    ans = four_way_merge(a,b,c,d);

    for(int x:ans){
        cout<<x<<"  ";
    }


return 0;
}