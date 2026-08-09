#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n, q;
        cin>>n>>q;
        vector<int>a(n);
        vector<pair<int, int>>b;

        long long curr = 0;

        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }

        for(int i=0 ; i<q ; i++){
            int temp;
            cin>>temp;
            b.push_back({temp, i});
        }

        auto lambda = [](auto &a, auto &b){
            return a.first<b.first;
        };

        sort(b.begin(), b.end(), lambda);

        vector<long long>ans(q);

        int l=0;
        for(int i=0 ; i<q ; i++){
            while(l<n && a[l] <= b[i].first){
                curr+=a[l];
                l++;
            }
            ans[b[i].second] = curr;
        }

        for(int i=0 ; i<q ; i++){
            cout<<ans[i]<<" ";
        }

        cout<<endl;


    }


    return 0;
}