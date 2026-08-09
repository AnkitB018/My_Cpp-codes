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
        vector<int>vec(n);

        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        int ans = 0;
        int x = INT_MAX;
        int y = INT_MAX;

        for(int i=0 ; i<n ; i++){
            if(x > y){
                swap(x, y);
            }

            if(vec[i] <= x){
                x = vec[i];
            }else if(vec[i] <= y){
                y = vec[i];
            }else{
                x = vec[i];
                ans++;
            }
        }

        cout<<ans<<endl;

    }

}