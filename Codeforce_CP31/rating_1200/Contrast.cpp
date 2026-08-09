#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }

        if(n == 1){
            cout<<1<<endl;
            continue;
        }

        vector<int>ans;
        ans.push_back(vec[0]);
        for(int i=1 ; i<n ; i++){
            if(vec[i-1] == vec[i]){
                continue;
            }

            if(ans.back() == vec[i-1]){
                continue;
            }
            if(ans.back() < vec[i-1]){ //inc order
                if(vec[i] > vec[i-1]){
                    continue;
                }else{
                    ans.push_back(vec[i-1]);
                }
            }

            if(ans.back() > vec[i-1]){ //dec order
                if(vec[i] < vec[i-1]){
                    continue;
                }else{
                    ans.push_back(vec[i-1]);
                }
            }
        }
        ans.push_back(vec.back());

        if(ans.size() == 2){
            if(ans[0] == ans[1]){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
            continue;
        }

        cout<<ans.size()<<endl;
        
    }


    return 0;
}