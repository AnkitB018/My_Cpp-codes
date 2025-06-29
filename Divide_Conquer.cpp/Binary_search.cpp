#include<iostream>
#include<vector>
using namespace std;

int Binary_search(vector<int>a, int l, int h, int key){
    if(l>h){
        return -1;
    }

    int mid = (l+h)/2;
    if(a[mid] == key){
        return mid;
    }
    if(key<a[mid]){
        return Binary_search(a,l,mid-1,key);
    }else{
        return Binary_search(a,mid+1, h, key);
    }
    
}


int main(){
    vector<int>a = {1,4,6,7,9,10,13,16,21,34,51,56,59,64,72,78,89,90,98,101,109,151,200};
    int i = Binary_search(a,0,a.size()-1,64);
    if(i == -1){
        cout<<"Not found!";
    }else{
        cout<<a[i];
    }

return 0;
}