#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<long long>vec(n);

        for(int i=0 ;i<n; i++){
            cin>>vec[i];
        }

        vector<long long>maxbits(32, 0);

        for(int i=0 ;i<n; i++){
            for(int j=31; j>=0 ; j--){
                if((vec[i] & (1<<j))){
                    maxbits[j]++;
                    break;
                }
            }
        }

        long long ans=0;
        for(int i=0 ; i<32 ; i++){
            ans += (maxbits[i] * (maxbits[i]-1))/2;
        }

        cout<<ans<<endl;

    }

    return 0;
}