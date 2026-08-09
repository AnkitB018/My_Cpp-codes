#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

        vector<int>freq(31, 0);
        for(auto &ele:vec){
            for(int i=0 ; i<31 ; i++){
                if(ele & 1){
                    freq[i]++;
                }
                ele = ele>>1;
            }
        }

        int g = 0;
        for(auto ele: freq){
            g = gcd(g, ele);
        }

        if(g == 0){
            for(int i=1 ; i<=n ; i++){
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }

        vector<int>factors;
        for(int i=1 ; i*i<=g ; i++){
            if(g%i == 0){
                factors.push_back(i);
                if(i != g/i){
                    factors.push_back(g/i);
                }
            }
        }
        sort(factors.begin(), factors.end());

        for(auto ele:factors){
            cout<<ele<<" ";
        }

        cout<<endl;


    }


    return 0;
}