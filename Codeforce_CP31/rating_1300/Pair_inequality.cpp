#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<long long>vec(n);

        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        vector<pair<long long, long long>>valids;
        for(int i=0 ; i<n ; i++){
            if(vec[i] < (i+1)){
                valids.push_back({vec[i], i+1});
            }
        }

        long long ans = 0;
        sort(valids.begin(), valids.end());

        for(int i=0 ; i<valids.size() ; i++){
            long long base = valids[i].second;
            int l=i+1;
            int r=valids.size()-1;
            while(l<=r){
                long long mid = l+(r-l)/2;
                if(valids[mid].first <= base){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }

            ans += valids.size()-l;

        }


        cout<<ans<<endl;

    }


    return 0;
}