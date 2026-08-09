#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int best = INT_MAX;
        for(int i=0 ; i<26 ; i++){
            char now = 'a'+i;
            int l=0;
            int r=n-1;
            int curr = 0;
            bool found = true;
            while(l<r){
                if(s[l] == s[r]){
                    l++;
                    r--;
                    continue;
                }

                if(s[l] == now){
                    l++;
                    curr++;
                    continue;
                }
                if(s[r] == now){
                    r--;
                    curr++;
                    continue;
                }

                found = false;
                break;
            }
            if(found){
                if(best > curr){
                    best = curr;
                }
            }
        }

        if(best == INT_MAX){
            cout<<-1<<endl;
        }else{
            cout<<best<<endl;
        }

    }


    return 0;
}