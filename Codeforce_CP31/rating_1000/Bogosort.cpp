#include<iostream>
#include<vector>
#include<utility>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec(n,0);
        for(int i=0 ; i<n;i++){
            cin>>vec[i];
        }

        vector<int>need(n);
        for(int i=0 ; i<n ; i++){
            need[i] = i-vec[i];
        }

        vector<int>ans(n);

        for(int i=0; i<n; i++){
            pair<int, int> min_idx = {i, need[i]};
            for(int j=i+1; j<n ; j++){
                int val = need[j] - (j-i);
                if(val < min_idx.second){
                    min_idx = {j, val};
                }
            }
            swap(vec[i], vec[min_idx.first]);
            need[min_idx.first] = (min_idx.first-i)+need[i]; 
        }

        for(auto ele:vec){
            cout<<ele<<" ";
        }

        cout<<endl;

    }


    return 0;
}
