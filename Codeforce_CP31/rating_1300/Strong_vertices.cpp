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
        vector<int>a(n, 0);
        vector<int>b(n, 0);

        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }

        for(int i=0 ; i<n ; i++){
            cin>>b[i];
        }

        vector<pair<int, int>>diff;

        for(int i=0 ; i<n ; i++){
            diff.push_back({a[i]-b[i], i});
        }

        sort(diff.rbegin(), diff.rend());

        vector<int>ans;
        int high = diff[0].first;
        int i=0;
        while(i<n && diff[i].first == high){
            ans.push_back(diff[i].second+1);
            i++;
        }

        cout<<ans.size()<<endl;
        for(int i=ans.size()-1 ; i>=0 ; i--){
            cout<<ans[i]<<" ";
        }

        cout<<endl;


    }


    return 0;
}