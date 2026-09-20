#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=-1,r=-1;
    int total = 0;
    for(int i=0 ; i<n ; i++){
        if(s[i] == '*'){
            total++;
        }
    }
    if(total == 0){
        cout<<0<<endl;
        return;
    }
    int need = (total/2)+1;
    int curr = 0;
    for(int i=0 ; i<n ; i++){
        if(s[i] == '*'){
            curr++;
        }
        if(curr == need){
            l = i;
            r = i;
            break;
        }
    }

    long long moves = 0;
    for(int i=l-1 ; i>=0 ; i--){
        if(s[i] == '*'){
            moves += (l-i-1);
            l--;
        }
    }
    for(int i=r+1 ; i<n ; i++){
        if(s[i] == '*'){
            moves += (i-r-1);
            r++;
        }
    }

    cout<<moves<<endl;

}

int main(){
    int tests;
    cin>>tests;

    while(tests--){
        solve();
    }

    return 0;
}