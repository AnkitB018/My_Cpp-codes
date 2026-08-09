#include<iostream>
#include<vector>
#include<string>

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

        bool flag = false;
        for(int i=0 ; i<n ; i++){
            if(s[i] != c){
                flag = true;
                break;
            }
        }

        if(!flag){
            cout<<0<<endl;
            continue;
        }

        int num;
        for(int i=1 ; i<=n ; i++){
            flag = true;
            int temp = i;
            while(temp-1 < n){
                if(s[temp-1] !=c ){
                    flag = false;
                    break;
                }
                temp += i;
            }

            if(flag){
                num = i;
                break;
            }
        }

        if(flag){
            cout<<1<<endl;
            cout<<num<<endl;
        }else{
            cout<<2<<endl;
            cout<<n-1<<" "<<n<<endl;
        }


    }



    return 0;
}