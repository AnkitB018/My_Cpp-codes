#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int partition(vector<int>& a, int l, int h); // Forward declaration


void quick_sort(vector<int>&a, int l , int h){

    static int flag = 0;
    if(flag == 0){
        a.push_back(INT_MAX);
        h++;
        flag++;
    }
    int j;
    if(l<h){
        j = partition(a , l , h);
        quick_sort(a , l , j);
        quick_sort(a, j+1 , h);
    }   
}

int partition(vector<int>&a , int l , int h){
    int i = l;
    int j = h;
    int pivot = a[i];
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i<j);

    int temp = a[j];
    a[j] = a[l];
    a[l] = temp;
    return j;

}


int main(){
    vector<int>res = {1,5,21,8,30,4,0,12,7,24,11};
    int n = res.size()-1;
    quick_sort(res, 0 , n);
    res.erase(res.begin()+n+1);
    for(auto &x:res){
        cout<<x<<"  ";
    }     

return 0;
//perfect


}