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
        vector<pair<long long, long long>>vec;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            vec.push_back({temp, i+1});
        }

        sort(vec.begin(), vec.end());

        long long ans = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(vec[i].first * vec[j].first >= 2*n) break;

                if(vec[i].first * vec[j].first == vec[i].second + vec[j].second){
                    ans++;
                }
            }
        }

        cout<<ans<<endl;


    }


    return 0;
}