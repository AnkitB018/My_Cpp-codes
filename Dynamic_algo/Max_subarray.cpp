#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxsub(vector<int>&a){ // Time = O(N^2)
    int max_sum = INT_MIN;
    for(int i=0 ; i<a.size() ; i++){
        int sum = 0;
        for(int j=i ; j<a.size() ; j++){
            sum+=a[j];
            if(sum>max_sum){
                max_sum = sum;
            }
        }
    }

    return max_sum;
}

//now using dp
int maxsub_dp(vector<int>&a){ // time-> O(N) and space->O(N)
    vector<int>dp(a.size(), -1);
    dp[0] = a[0];
    int max=dp[0];
    for(int i=1 ; i<a.size() ; i++){
        if(dp[i-1] >=0){
            dp[i] = dp[i-1]+a[i];
        }else{
            dp[i] = a[i];
        }
        if(dp[i]>max){
            max = dp[i];
        }
    }

    return max;
}

//now kadane's algo which is better dp approach
int max_sub_kad(vector<int>&a){ //time-> O(N) and space->O(1)
    int prev_sum=a[0];
    int max_sum=prev_sum;
    int start = 0, end=0, substart=0;
    for(int i=1 ; i<a.size() ; i++ ){
        if(prev_sum >0){
            prev_sum+=a[i];
        }else{
            prev_sum = a[i];
            substart = i;
        }
        if(prev_sum>max_sum){
            max_sum = prev_sum;
            start = substart;
            end=i;
        }
    }

    return max_sum; // we can return start and end to find the exact subarray
}


int main(){
    vector<int> a = {4, -5, 8, -2, -1, 7, -6};
    int cost = maxsub_dp(a);
    cout<<cost<<endl;
    vector<int>b = {3, -7, 10, -2, -1, 7, -11, -5, 9, 3};
    int ans = max_sub_kad(b);
    cout<<ans;
return 0;
}