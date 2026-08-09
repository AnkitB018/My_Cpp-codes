#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        if(c == 'g'){
            cout<<0<<endl;
            continue;
        }
        vector<int>green;
        vector<int>curr;
        for(int i=0 ; i<n ; i++){
            if(s[i] == c){
                curr.push_back(i);
                continue;
            }
            if(s[i] == 'g'){
                green.push_back(i);
            }
        }
        int best = INT_MIN;

        for(int i=0 ; i<curr.size() ; i++){
            int pos = curr[i];
            int l=0;
            int r = green.size()-1;
            if(pos > green[r]){
                int now = n-pos+green[0];
                if(now > best){
                    best = now;
                }
                break;
            }
            while(l<=r){
                int mid = l+(r-l)/2;
                if(green[mid] > pos){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            int now = green[l]-pos;
            if(now > best){
                best = now;
            }

        }

        cout<<best<<endl;

    }


    return 0;
}