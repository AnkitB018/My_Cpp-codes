#include<iostream>
#include<string>

using namespace std;

int main(){
    int test;
    cin>>test;
    while (test--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;


        int open=0;
        int useless_close = 0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                open++;
            }else{
                if(open){
                    open--;
                }else{
                    useless_close++;
                }
            }
        }

        cout<<useless_close<<endl;

    }
    
    

    return 0;
}