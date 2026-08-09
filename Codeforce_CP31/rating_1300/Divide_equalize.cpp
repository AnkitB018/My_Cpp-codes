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
        for(int i=0; i<n ; i++){
            cin>>vec[i];
        }

        // need prime factors of each numbers
        map<int , int>mp;
        for(int i=0; i<n ; i++){
            for(int j=2 ; j*j <= vec[i] ; j++){
                while(vec[i] % j == 0){
                    mp[j]++;
                    vec[i] = vec[i]/j;
                }
            }

            if(vec[i] > 1){
                mp[vec[i]]++;
            }

        }

        bool flag = true;
        for(auto ele:mp){
            if(ele.second % n ){
                flag = false;
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