#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int test;
    scanf("%d", &test);
    while(test--){
        int n,m;
        scanf("%d %d", &n, &m);

        vector<int>k;
        k.reserve(n);
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            k.push_back(temp-1);
        }

        sort(k.rbegin(), k.rend());

        vector<int>c(m);
        for(int i=0 ; i<m ; i++){
            scanf("%d", &c[i]);
        }

        long long ans = 0;
        int l=0;
        for(int i=0 ; i<n ; i++){
            if(l>=k[i]){
                ans+= c[k[i]];
            }else{
                ans += c[l++];
            }
        }

        cout<<ans<<endl;

    }


    return 0;
}