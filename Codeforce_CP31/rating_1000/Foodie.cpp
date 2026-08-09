#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

int main(){
    int test;
    cin>>test;
    while(test--){
        ll n,x;
        cin>>n>>x;
        vector<ll>vec;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }

        ll ans = 0;
        vector<vector<ll>>intervals;
        for(int i=0 ; i<n ; i++){
            vector<ll>temp;
            temp.push_back(vec[i]-x);
            temp.push_back(vec[i]+x);

            intervals.push_back(temp);
        }

        vector<ll>curr = intervals[0];
        for(int i=0 ; i<n ; i++){
            vector<ll>temp = intervals[i];
            if(temp[1] > curr[1]){
                if(temp[0] > curr[1]){
                    curr =temp;
                    ans++;
                    continue;
                }
            }else{
                if(curr[0] > temp[1]){
                    ans++;
                    curr = temp;
                    continue;
                }
            }
            curr[0] = max(curr[0], temp[0]);
            curr[1] = min(curr[1], temp[1]);

        }


        cout<<ans<<endl;

    }


    return 0;
}