#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double knapsack_frac(vector<vector<double>>&obj, double k, int n){
    sort(obj.begin() , obj.end(), [](const vector<double>&a, const vector<double>&b){
        return a[0]/a[1] > b[0]/b[1];
    });
    double profit = 0;
    for(int i=0 ; i<n ; i++){
        if(obj[i][1]<=k){
            profit +=obj[i][0];
            k-=obj[i][1];
        }else{
            profit += obj[i][0] * (k/obj[i][1]);
            break;
        }
    }
    return profit;

}

int main(){
    vector<vector<double>>a = {{12,2},{17,5},{9,7},{7,3},{5,1},{21,4},{8,1}};
    double ans = knapsack_frac(a, 15, 7);
    cout<<ans;

return 0;
}