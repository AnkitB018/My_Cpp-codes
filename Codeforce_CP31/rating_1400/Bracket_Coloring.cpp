#include<iostream>
#include<vector>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s;
        cin>>s;


        vector<int>bal(n);
        bal[0] = (s[0] == '('?1:-1);
        for(int i=1 ; i<n ; i++){
            bal[i] = bal[i-1] + (s[i]=='(' ? 1 : -1);
        }

        if(bal[n-1] != 0){
            cout<<-1<<endl;
            continue;
        }

        if(*max_element(bal.begin(), bal.end()) == 0 || *min_element(bal.begin(), bal.end()) == 0){
            cout<<1<<endl;
            for(int i=0 ; i<n ; i++) cout<<1<<' ';
            cout<<endl;
            continue;
        }

        vector<int>col(n);
        for(int i=0 ; i<n ; i++){
            if(bal[i] > 0){
                col[i] = 1;
            }else if(bal[i] < 0){
                col[i] = 2;
            }else{
                col[i] = bal[i-1] >0?1:2;
            }
        }

        cout<<2<<endl;
        for(int i=0 ; i<n ; i++){
            cout<<col[i]<<' ';
        }

        cout<<endl;



    }

    return 0;
}