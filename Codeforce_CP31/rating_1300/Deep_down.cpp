#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<pair<int, int>>monstors;
        monstors.reserve(n);
        for(int i=0 ; i<n; i++){
            int size;
            cin>>size;
            vector<int>power(size);
            for(int j=0 ; j<size ; j++){
                int temp;
                scanf("%d", &temp);
                power[j] = temp-j+1;
            }
            sort(power.begin(), power.end());
            monstors.push_back({power[size-1], size});
        }


        sort(monstors.begin(), monstors.end());

        int base = monstors[0].first;
        int increase = monstors[0].second;

        for(int i=1 ; i<n ; i++){
            base = max(base, monstors[i].first - increase);
            increase += monstors[i].second;
        }

        cout<<base<<endl;

    }

    return 0;
}