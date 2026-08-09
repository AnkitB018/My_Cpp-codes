#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<long long, long long> count(int n){
    long long zeros = 0;
    long long total = 0;

    bool flag = true;
    while(n>0){
        total++;
        int temp = n%10;
        n = n/10;
        if(flag){
            if(temp == 0){
                zeros++;
            }else{
                flag = false;
            }
        }
    }

    return {zeros, total};
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;

        vector<long long>vec(n);
        long long dig = 0;
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
            
        }

        vector<long long>zeros(n);
        for(int i=0 ; i<n ; i++){
            pair<long long, long long> op = count(vec[i]);
            zeros[i] = op.first;
            dig += op.second;
        }

        sort(zeros.rbegin(), zeros.rend());

        for(int i=0 ; i<n ; i+=2){
            if(dig <= m){
                break;
            }
            dig -= zeros[i];
        }

        if(dig <= m){
            cout<<"Anna"<<endl ;
        }else{
            cout<<"Sasha"<<endl;
        }



    }


    return 0;   
}