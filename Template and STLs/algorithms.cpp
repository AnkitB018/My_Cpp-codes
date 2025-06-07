#include<iostream>
#include<algorithm>


using namespace std;


int main(){
    int arr[] = { 1,5,2,4,8,4,7,9,2};
    cout<<"before sorting with algo";
    for(int i = 0 ; i<9 ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr , arr+9);
    cout<<"after sorting with algo";
    for(int i = 0 ; i<9 ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"now sorting in decreasing order";
    sort(arr , arr+9 , greater<>());
    cout<<endl;
    for(int i = 0 ; i<9 ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}