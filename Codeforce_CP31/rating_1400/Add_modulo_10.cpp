#include<iostream>
#include<vector>

using namespace std;

int get_slot(int n){
    int last = n%10;
    int first = n/10;

    if(first%2 == 0){
        if(last == 1 || last == 2 || last == 4 || last == 8){
            return 1;
        }else if(last == 3 || last == 6){
            return 2;
        }else if(last == 7 || last == 9){
            return 2;
        }else{
            return 0;
        }
    }else{
        if(last == 1 || last == 2 || last == 4 || last == 8){
            return 2;
        }else if(last == 3 || last == 6){
            return 1;
        }else if(last == 7 || last == 9){
            return 1;
        }else{
            return 0;
        }
    }
}

void solve(){
    int n;
    cin>>n;

    bool flag = true;
    vector<int>vec(n);
    for(int i=0 ; i<n ; i++){
        cin>>vec[i];
    }

    if(vec[0]%5 != 0){
        int slot = get_slot(vec[0]);
        for(int i=1 ; i<n ; i++){
            if(slot != get_slot(vec[i])){
                flag = false;
                break;
            }
        }
    }else{
        int f = vec[0];
        int s = (vec[0]%2==0)?vec[0]-5:vec[0]+5;
        for(int i=1 ; i<n ; i++){
            if(vec[i] == f || vec[i] == s){
                continue;
            }

            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}

int main(){
    int tests;
    cin>>tests;
    while(tests--){
        solve();
    }

    return 0;
}