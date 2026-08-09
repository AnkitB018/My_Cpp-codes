#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        vector<int>vec;
        cin>>n;
        for(int i=0 ; i<n; i++){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }

        if(n == 1){
            cout<<-1<<endl;
            continue;
        }

        int l=0;
        int r=0;
        vector<pair<int,int>>points;
        while(r<n){
            if(vec[l] == vec[r]){
                r++;
                continue;
            }
            points.push_back({l, r-1});
            l=r;
        }
        points.push_back({l, r-1});
        vector<int>ans;

        bool flag=false;
        for(int i=0; i<points.size(); i++){
            if(points[i].first == points[i].second ){
                flag = true;
                break;
            }
            int left = points[i].first;
            int right = points[i].second;
            while(left<=right){
                if(left == right){
                    ans.push_back(points[i].first+1);
                    break;
                }
                ans.push_back(left+2);
                left++;
            }
        }

        if(flag){
            cout<<-1<<endl;
        }else{
            for(int i=0 ; i<ans.size() ; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }

    }


    return 0;
}