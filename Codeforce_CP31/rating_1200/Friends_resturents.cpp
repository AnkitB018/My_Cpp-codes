#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>x(n);
        for(int i=0 ; i<n ; i++){
            cin>>x[i];
        }

        vector<int>y(n);
        for(int i=0 ; i<n ; i++){
            cin>>y[i];
        }

        multiset<int>ms;
        for(int i=0 ; i<n ; i++){
            ms.insert((y[i] - x[i]));
        }

        int ans = 0;

        while(ms.size() > 1){
            int val = *(ms.begin());
            ms.erase(ms.begin());

            auto it = ms.lower_bound(-val);

            if(it != ms.end()){
                ans++;
                ms.erase(it);
            }

        }

        cout<<ans<<endl;

    }


}