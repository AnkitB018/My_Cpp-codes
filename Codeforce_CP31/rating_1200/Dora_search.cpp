#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        int min = 1;
        int max = n;
        
        int l=0;
        int r=n-1;
        bool flag = false;

        while(l<r){
            if(vec[l] == min || vec[l] == max){
                if(vec[l] == min){
                    min++;
                }else{
                    max--;
                }
                l++;
                flag = false;
            }

            if(vec[r] == min || vec[r] == max){
                if(vec[r] == min){
                    min++;
                }else{
                    max--;
                }

                r--;
                flag = false;
            }

            if(flag){
                break;
            }

            flag = true;
        }


        if(l<r){
            cout<<l+1<<" "<<r+1<<endl;
        }else{
            cout<<-1<<endl;
        }


    }


    return 0;
}