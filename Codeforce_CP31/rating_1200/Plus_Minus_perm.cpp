#include<iostream>
#include<vector>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find LCM
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    
    // Divide first to avoid arithmetic overflow
    return (a / gcd(a, b)) * b; 
}


int main(){
    int test;
    cin>>test;
    while(test--){
        long long n,x,y;
        cin>>n>>x>>y;

        long long max_need = n/x;
        long long min_need = n/y;

        long long common = n/lcm(x,y);

        max_need -=common;
        min_need -=common;

        long long best = 0;
        best += max_need*n - (max_need*(max_need-1)/2);
        best -= min_need*(min_need+1)/2;

        cout<<best<<endl;
    }
}