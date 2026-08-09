#include<iostream>
#include<vector>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;
        int best=INT_MAX;
        int curr = 0;
        int l=0;
        int r=k-1;
        for(int i=l ; i<=r ; i++){
            if(s[i] == 'W'){
                curr++;
            }
        }

        l++;
        r++;
        best = curr;

        while(r<n){
            if(s[l-1] == 'W'){
                curr--;
            }
            if(s[r] == 'W'){
                curr++;
            }
            if(curr<best){
                best = curr;
            }
            l++;
            r++;
        }

        cout<<best<<endl;

    }


    return 0;
}