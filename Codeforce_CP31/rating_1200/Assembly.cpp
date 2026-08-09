#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n;
        cin>>n;
        long long b = n*(n-1)/2;
        vector<int>vec;
        unordered_map<int, int>m;
        for(int i=0 ; i<b ; i++){
            int temp;
            cin>>temp;
            m[temp]++;
            if(m[temp] == 1){
                vec.push_back(temp);
            }
        }

        sort(vec.rbegin(), vec.rend());
        vector<long long>ans;
        long long bigger = 0;
        for(long long i=0 ; i<vec.size() ; i++){
            long long curr = vec[i];
            long long freq = m[curr];
            while(freq>0 && n>0){
                ans.push_back(curr);
                freq-=bigger;
                bigger++;
                n--;
            }
        }


        for(int i=0 ; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }

        cout<<endl;

    }
}