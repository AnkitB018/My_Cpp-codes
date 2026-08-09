#include<iostream>

using namespace std;
typedef long long ll;

int main(){
    int test;
    cin>>test;
    while(test--){
        ll n,k,b,s;
        cin>>n>>k>>b>>s;

        if(s/k < b){
            cout<<-1<<endl;
            continue;
        }

        if(s/k == b){
            for(ll i=0 ; i<n ; i++){
                if(i == n-1){
                    cout<<s<<endl;
                }else{
                    cout<<0<<" ";
                }
            }
            continue;
        }

        ll ans = (k*(b+1))-1;
        ll remain = s-ans;
        if(remain > (n-1)*(k-1)){
            cout<<-1<<endl;
            continue;
        }

        for(ll i=0 ; i<n ; i++){
            if(i==n-1){
                cout<<ans<<endl;
            }else{
                if(remain >= k-1){
                    cout<<k-1<<" ";
                    remain-=(k-1);
                }else if(remain == 0){
                    cout<<0<<" ";
                }else{
                    cout<<remain<<" ";
                    remain = 0;
                }
            }
        }



    }


    return 0;
}