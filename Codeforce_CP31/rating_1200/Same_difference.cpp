#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        unordered_map<int, long long>m;
        for(int i=0; i<n ; i++){
            m[vec[i] - i]++;
        }

        long long ans =0;
        for(auto ele:m){
            long long temp= (ele.second*(ele.second-1)) /2LL ;
            ans += temp;
        }

        cout<<ans<<endl;


    }


    return 0;
}