#include<iostream>
#include<vector>
#include<set>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0 ; i<n ;i++){
            cin>>vec[i];
        }

        set<int>s;
        for(auto &ele: vec){
            s.insert(ele);
        }

        if(s.size() == n){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }


    return 0;
}