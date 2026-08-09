#include<iostream>
#include<string>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,r,b;
        cin>>n>>r>>b;
        int dis = r/(b+1);
        int rem = r%(b+1);
        int curr = 0;
        for(int i=0 ; i<n ; i++){
            if(curr < dis){
                cout<<"R";
                curr++;
            }else if(curr == dis && rem){
                rem--;
                curr = 0;
                cout<<"R";
                if(b){
                    cout<<"B";
                    b--;
                }
                i++;
            }else{
                if(b){
                    cout<<"B";
                    b--;
                }
                curr=0;
            }
        }

        cout<<endl;


    }


    return 0;
}