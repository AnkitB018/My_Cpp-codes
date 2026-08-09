#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n,p;
        cin>>n>>p;
        vector<long long>share(n);
        for(int i=0 ; i<n ; i++){
            cin>>share[i];
        }
        vector<pair<long long, long long>>costs;
        for(int i=0 ; i<n ; i++){
            long long temp;
            cin>>temp;
            costs.push_back({temp, i});
        }

        auto cmp = [](auto &a, auto &b){
            return a.first<b.first;
        };
        sort(costs.begin() , costs.end() , cmp);

        if(p<=costs[0].first){
            cout<<n*p<<endl;
            continue;
        }

        long long ans=0;
        long long told = 0;
        told++;
        ans+=p;
        int i=0;
        while(told != n){
            long long can = min(share[costs[i].second], n-told);
            told += can;
            ans+= can*costs[i].first;
            i++;
            if(i == n){
                break;
            }
            if(costs[i].first > p){
                break;
            }
        }
        ans+=p*(n-told);
        cout<<ans<<endl;


    }


    return 0;
}