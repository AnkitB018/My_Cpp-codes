#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>&a , int l ,int mid, int h){
    int i = l ; 
    int j = mid+1;
    int k = l;
    int b[100];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        }else{
            b[k++] = a[j++];
        }
    }

    for(;i<=mid ; i++){
        b[k++] = a[i];
    }
    for(; j<=h ; j++){
        b[k++] = a[j];
    }
    for(i=l ; i<=h ; i++){
        a[i] = b[i];
    }
}


void merge_sort(vector<int>&a, int l, int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        merge_sort(a , l , mid);
        merge_sort(a , mid+1 , h);
        merge(a , l , mid , h);
    }

}


int main(){
    vector<int>res = {1,5,21,8,30,4,0,12,7,24,11};
    int n = res.size()-1;
    merge_sort(res, 0 , n);
    for(auto &x:res){
        cout<<x<<"  ";
    }  

    return 0;
    //perfect
}