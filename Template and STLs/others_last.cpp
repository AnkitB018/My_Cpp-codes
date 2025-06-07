#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;


int main(){

    stack<int>st;
    st.push(1);

    priority_queue<int>pt; //max heap
    pt.push(12);
    pt.push(29);
    pt.push(100);
    pt.push(74);
    pt.push(98);    

    //cout<<pt.top()<<endl;
    //pt.pop();
    //cout<<pt.top()<<endl;
    //pt.pop();
    //cout<<pt.top()<<endl;

    //try binary search on a array

    int arr[]={1,6,3,5,2,7,2,10,4,2};
    sort(arr,arr+10);
    int i;
    cout<<"Enter an element to search: "<<endl;
    cin>>i;
    if(binary_search(arr , arr+10 , i)){
        cout<<"searcing for element " <<i <<".....found!"<<endl;
    }else{
        cout<<"searching for element "<<i <<".....not found!"<<endl;
    }

    return 0;
}