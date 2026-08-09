#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int w,h;
        cin>>w>>h;
        int k;
        cin>>k;
        vector<pair<int,int>>left;
        vector<pair<int,int>>right;
        vector<pair<int,int>>bottom;
        vector<pair<int,int>>top;
        for(int i=0 ; i<k ; i++){
            int temp;
            cin>>temp;
            bottom.push_back({temp, 0});
        }

        cin>>k;
        for(int i=0 ; i<k ; i++){
            int temp;
            cin>>temp;
            top.push_back({temp, h});
        }

        cin>>k;

        for(int i=0 ; i<k ; i++){
            int temp;
            cin>>temp;
            left.push_back({0, temp});
        }

        cin>>k;

        for(int i=0 ; i<k ; i++){
            int temp;
            cin>>temp;
            right.push_back({w, temp});
        }

        long long ans = INT_MIN;
        long long area;        
        long long base = abs(left[0].second - left[left.size()-1].second);
        area = base*w;
        if(area > ans) ans= area;

        base = abs(right[0].second - right[right.size()-1].second);
        area = base*w;
        if(area > ans) ans= area;

        base = abs(bottom[0].first - bottom[bottom.size()-1].first);
        area = base*h;
        if(area > ans) ans= area;

        base = abs(top[0].first - top[top.size()-1].first);
        area = base*h;
        if(area > ans) ans= area;

        cout<<ans<<endl;


    }

    return 0;
}