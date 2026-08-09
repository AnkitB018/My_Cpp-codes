#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin>>s;

    int n = s.size();
    for(int i=1 ; i<n ; i++){
        if(s[i] == s[i-1]){
            if(i == n-1){
                char temp = s[i-1]+1;
                if(temp == 'z'+1){
                    temp = 'a';
                }
                s[i] = temp;
            }else{
                char temp = max(s[i-1], s[i+1])+1;
                if(temp == 'z'+1){
                    temp = min(s[i-1], s[i+1])-1;
                    if(temp == 'a'-1){
                        temp = 'b';
                    }
                }
                s[i] = temp;
            }
        }
    }

    cout<<s<<endl;

    return 0;
}