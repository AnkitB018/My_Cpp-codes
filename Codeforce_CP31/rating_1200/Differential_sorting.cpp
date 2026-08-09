#include<iostream>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<long long>vec(n);
        for(int i=0 ; i<n ; i++){
            cin>>vec[i];
        }

        if(vec[n-1] < vec[n-2]){
            cout<<-1<<endl;
            continue;
        }

        if(vec[n-1] >= 0){
            cout<<n-2<<endl;
            for(int i=1 ; i<n-1 ; i++){
                cout<<i<<" "<<n-1<<" "<<n<<endl;
            }
        }else{
            if(is_sorted(vec.begin(), vec.end())){
                cout<<0<<endl;
            }else{
                cout<<-1<<endl;
            }
        }


    }

    return 0;
}