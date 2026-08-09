#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        vector<vector<long long>>vec(m, vector<long long>(n, 0));
        for(int i =0; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin>>vec[j][i];
            }
        }

        long long sum = 0;
        for(int i= 0 ; i<m ; i++){
            sort(vec[i].begin(), vec[i].end());
            for(long long j=0 ; j<n ; j++){
                sum += (vec[i][j]*j - vec[i][j]*(n-1-j));
            }
        }


        cout<<sum<<endl;

    }


    return 0;
}