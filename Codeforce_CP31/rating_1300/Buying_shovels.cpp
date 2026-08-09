#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;

        vector<int>divs;
        for(int i=1 ; i*i<=n ; i++){
            if(n%i == 0){
                divs.push_back(i);
                divs.push_back(n/i);
            }
        }

        sort(divs.rbegin(), divs.rend());

        int ans = n;
        for(int i=0 ; i<divs.size() ; i++){
            if(divs[i] <= k){
                ans = n/divs[i];
                break;
            }
        }

        printf("%d\n", ans);

    }


    return 0;
}