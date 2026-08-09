#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0 ;i<n ; i++){
            cin>>vec[i];
        }

        vector<int>res;
        for(int i=0 ; i<n ; i++){
            int l=0;
            int r=i;
            while(l <= r){
                int mid = l + (r-l)/2;
                if(vec[mid] >= i-mid+1){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            res.push_back(i-l+1);
        }

        for(int i=0 ; i<res.size() ; i++){
            cout<<res[i]<<" ";
        }

        cout<<endl;

    }

    return 0;
}