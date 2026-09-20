#include<iostream>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long numodds=0;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            if(temp%2){
                numodds++;
            }
        }

        if(y%2){
            if(x%2){
                if(numodds%2){
                    cout<<"Bob"<<endl;
                }else{
                    cout<<"Alice"<<endl;
                }
            }else{
                if(numodds%2){
                    cout<<"Alice"<<endl;
                }else{
                    cout<<"Bob"<<endl;
                }
            }
        }else{
            if(x%2){
                if(numodds%2){
                    cout<<"Alice"<<endl;
                }else{
                    cout<<"Bob"<<endl;
                }
            }else{
                if(numodds%2){
                    cout<<"Bob"<<endl;
                }else{
                    cout<<"Alice"<<endl;
                }
            }
        }

    }


    return 0;
}