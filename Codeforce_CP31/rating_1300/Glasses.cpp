#include<iostream>
#include<vector>
#include<map>

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

        vector<long long>pre_odd(n, 0);
        vector<long long>pre_even(n, 0);

        pre_even[0] = vec[0];

        map<long long, long long>mp;
        mp[0]++;
        mp[pre_even[0]-pre_odd[0]]++;

        bool flag = false;
        for(int i=1 ; i<n ; i++){
            pre_even[i] += pre_even[i-1];
            pre_odd[i] += pre_odd[i-1];
            if(i%2){
                pre_odd[i] += vec[i];
            }else{
                pre_even[i] += vec[i];
            }

            mp[pre_even[i] - pre_odd[i]]++;
            if(mp[pre_even[i] - pre_odd[i]] == 2){
                flag = true;
                break;
            }

        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }


    return 0;
}