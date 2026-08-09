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
        vector<pair<int, int>>a;
        vector<pair<int, int>>b;
        vector<pair<int, int>>c;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            a.push_back({temp, i});
        }
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            b.push_back({temp, i});
        }

        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            c.push_back({temp, i});
        }

        auto lambda = [](auto &a, auto &b){
            return a.first>b.first;
        };

        sort(a.begin(), a.end(), lambda);
        sort(b.begin(), b.end(), lambda);
        sort(c.begin(), c.end(), lambda);        

        int best = INT_MIN;
        for(int i=0 ; i<3; i++){
            int f = a[i].first;
            for(int j=0; j<3; j++){
                if(b[j].second == a[i].second){
                    continue;
                }
                int s = b[j].first;
                for(int k=0 ; k<3; k++){
                    if(c[k].second == b[j].second || c[k].second == a[i].second){
                        continue;
                    }
                    int t = c[k].first;
                    int sum = f+s+t;
                    if(sum > best){
                        best = sum;
                    }
                }
            }
        }

        cout<<best<<endl;

    }
}