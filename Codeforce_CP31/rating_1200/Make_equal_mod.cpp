#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<long long>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }
        set<long long>s;
        int i=1;
        for( ; i<61 ; i++){
            for(int j=0 ; j<n ; j++){
                long long exp = pow(2, i);
                s.insert(vec[j]%exp);
            }
            if(s.size() == 2){
                break;
            }else{
                s.clear();
            }
        }

        cout<<(long long)pow(2, i)<<endl;


    }


    return 0;
}