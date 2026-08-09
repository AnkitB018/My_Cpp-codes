#include<iostream>
#include<vector>
#include<map>


using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        bool flag = false;
        vector<vector<int>>exp(n);
        map<int, int>bits;

        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            for(int j=0 ; j<temp ; j++){
                int curr;
                cin>>curr;
                exp[i].push_back(curr);
                bits[curr]++;
            }
        }

        for(int i=0 ; i<n ; i++){
            bool first = true;
            for(int j=0 ; j<exp[i].size() ; j++){
                if(bits[exp[i][j]] > 1){
                    continue;
                }else{
                    first = false;
                    break;
                }
            }

            if(first){
                flag = true;
                break;
            }

        }



        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }


    return 0;
}
