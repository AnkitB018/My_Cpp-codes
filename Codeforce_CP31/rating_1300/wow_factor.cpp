#include<iostream>
#include<vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<long long>pre(n, 0);

    long long cnt= 0;

    long long curr = 0;
    for(int i=1; i<n ; i++){
        if(s[i] == 'v'){
            if(s[i-1] == 'v'){
                curr++;
            }
        }
        pre[i] = curr;
    }

    long long total = pre[n-1];

    for(int i=0 ; i<n ; i++){
        if(s[i] != 'o'){
            continue;
        }

        cnt += pre[i] * (total-pre[i]);

    }

    cout<<cnt<<endl;

    return 0;
}