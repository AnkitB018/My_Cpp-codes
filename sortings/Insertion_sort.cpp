#include<iostream>
#include<vector>
using namespace std;

void insertion_sort(vector<int>&a){
    int x,j;
    for(int i = 0 ;i<a.size() ; i++){
        j = i-1;
        x = a[i];
        while(j>-1 && a[j]>x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}


int main(){
    vector<int>res = {1,5,21,8,30,4,0,12,7,24,11};
    insertion_sort(res);
    for(auto &x:res){
        cout<<x<<"  ";
    }
    
    return 0;
}