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
        vector<pair<int, int>>bandit;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            bandit.push_back({temp, i});
        }

        sort(bandit.begin(), bandit.end());
        if(bandit.front().first == bandit.back().first){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;

        int r=n-1;
        while(bandit[r].first != bandit.front().first){
            cout<<bandit[0].second+1<<" "<<(bandit[r].second+1)<<endl;
            r--;
        }

        while(r != 0){
            cout<<(bandit[r].second+1)<<" "<<bandit.back().second+1<<endl;
            r--;
        }


    }

    return 0;
}