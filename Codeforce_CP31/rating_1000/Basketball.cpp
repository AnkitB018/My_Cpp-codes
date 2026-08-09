#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    vector<int>power;
    for(int i=0 ; i<n ; i++){
        int temp;
        cin>>temp;
        power.push_back(temp);
    }

    sort(power.begin(), power.end());
    int win=0;
    int j=0;
    int i=power.size()-1;
    while(j<=i){
        int best = power[i];
        i--;
        int need=0;
        need = (d+best)/best;
        need--;
        if(need){
            j+=need;
        }
        if(j<=i || j==i+1){
            win++;
        }
    }

    cout<<win<<endl;

    return 0;
}