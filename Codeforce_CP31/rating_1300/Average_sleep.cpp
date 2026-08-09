#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int>sleep(n);
    for(int i=0 ; i<n ; i++){
        cin>>sleep[i];
    }

    long long total = 0;

    long long sum = 0;
    for(int i=0 ; i<k ; i++){
        sum += sleep[i];
    }

    total += sum;
    int l=0;
    int r=k;
    while(r<n){
        sum -= sleep[l++];
        sum += sleep[r++];

        total += sum;
    }

    cout<<fixed<<setprecision(6)<<1.0* total / (n-k+1)<<endl;

    return 0;
}