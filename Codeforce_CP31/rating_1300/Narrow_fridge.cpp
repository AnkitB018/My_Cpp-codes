#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    long long n, h;
    cin>>n>>h;
    vector<int>org(n);

    for(int i=0 ; i<n ; i++){
        cin>>org[i];
    }

    int l=0;
    int r=n-1;
    
    while(l<=r){
        int mid = l+(r-l)/2;

        vector<int>temp(org.begin(), org.begin()+mid+1);
        sort(temp.begin(), temp.end());


        long long total = 0;
        for(int i=temp.size()-1 ; i>=0 ; i-=2){
            total += temp[i];
        }

        if(total > h){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<r+1<<endl;


    return 0;
}