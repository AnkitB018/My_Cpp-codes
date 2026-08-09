#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        long long n,x;
        cin>>n>>x;
        vector<long long>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        sort(vec.begin(), vec.end());

        long long ans = 0;
        long long sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += vec[i];
            if(sum > x){
                break;
            }
            long long days = (x-sum)/(i+1) + 1;
            ans+=days;
        }

        cout<<ans<<endl;

    }


    return 0;
}