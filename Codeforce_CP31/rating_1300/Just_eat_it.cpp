#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec(n);
        long long sum= 0;

        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
            sum +=vec[i];
        }

        bool flag = false;
        long long best = 0;
        int l=0;
        int r = 0;
        for(int i=0 ; i<n ; i++){
            if(best + vec[i] > 0){
                r = i;
                best += vec[i];
            }else{
                best = 0;
                l = i+1;
                r = i+1;
            }

            if(best >= sum){
                if(l == 0 && r == n-1){
                    continue;
                }
                flag = true;
            }


        }

        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }


    }


    return 0;
}