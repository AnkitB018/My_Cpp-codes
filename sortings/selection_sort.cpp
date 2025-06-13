#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int>&a){
    int max;
    int n = a.size()-1;
    for(int i=n; i>=0; i--){
        max = i;
        for(int j=0 ; j<i ; j++){
            if(a[j]>a[max]){
                max = j;
            }
        }
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }
}

int main(){
    vector<int>res = {1,5,21,8,30,4,0,12,7,24,11};
    selection_sort(res);
    for(auto &x:res){
        cout<<x<<"  ";
    }
return 0;
}