#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>vec(n);

        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        map<int, vector<int>>rem;
        for(int i=0 ; i<n ; i++){
            rem[vec[i]%y].push_back(vec[i]);
        }

        long long ans = 0;
        for(auto ele:rem){
            vector<int>r = ele.second;
            map<int, int>m;
            for(int i=0 ; i<r.size() ; i++){
                m[r[i]%x]++;
            }

            for(auto it:m){
                if(it.first == 0 || (it.first == x/2 && x%2 == 0)){
                    long long cnt = it.second;
                    ans += (cnt*(cnt-1))/2;
                }else{
                    long long cnt1 = it.second;
                    long long cnt2 = m[x-it.first];
                    ans += cnt1*cnt2;
                    m[x-it.first] = 0;
                }
            }

        }

        cout<<ans<<endl;


    }


    return 0;
}