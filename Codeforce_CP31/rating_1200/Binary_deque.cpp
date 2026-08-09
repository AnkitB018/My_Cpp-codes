#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,s;
        cin>>n>>s;
        vector<int>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        int sum=0;
        int len = -1;
        map<int, int>mp; // len, idx

        mp[0] = -1;
        
        for(int i=0 ; i<n ; i++){
            sum += vec[i];

            if(mp.count(sum-s)){
                len = max(len, i - mp[sum - s]);
            }

            if(!mp.count(sum)){
                mp[sum] = i;
            }
        }

        if(len == -1){
            cout<<-1<<endl;
            continue;
        }
        cout<<(n-len)<<endl;

    }


    return 0;
}