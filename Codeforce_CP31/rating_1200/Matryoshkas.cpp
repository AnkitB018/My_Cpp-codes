#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

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

        sort(vec.rbegin(), vec.rend());
        multiset<int>s;
        int sets = 1;
        s.insert(vec[0]-1);

        for(int i=1 ; i<n ; i++){
            auto it = s.find(vec[i]);
            if(it != s.end()){
                s.erase(it);
                s.insert(vec[i]-1);
            }else{
                s.insert(vec[i]-1);
                sets++;
            }
        }


        cout<<sets<<endl;
    }


    return 0;
}