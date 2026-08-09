#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        vector<pair<long long, long long>>buildings;
        for(long long i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            buildings.push_back({temp, i});
        }

        auto lambda = [](auto &a, auto &b){
            return a.first>b.first;
        };
        sort(buildings.begin(), buildings.end(), lambda);

        long long cost = 0;
        vector<long long>pos(n+1, 0);
        long long idx = 1;
        for(long long i=0 ; i<n ; i++){
            pos[buildings[i].second+1] =  idx;
            cost += 2*abs(idx-0)*buildings[i].first;
            if(idx > 0){
                idx = 0-idx;
            }else{
                idx = 0-idx;
                idx++;
            }
        }

        cout<<cost<<endl;
        for(auto &ele:pos){
            cout<<ele<<" ";
        }
        cout<<endl;

    }


    return 0;
}