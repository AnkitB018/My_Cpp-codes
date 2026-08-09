#include<iostream>
#include<string>
#include<algorithm>


using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        string a,b;
        cin>>a>>b;
        if(a>b){
            swap(a, b);
        }

        int main_cost = a.size()+b.size();
        string r = a;
        bool found = false;
        for(int i=0 ; i<a.size() ; i++){
            for(int j=i ; j<a.size() ; j++){
                r = a.substr(i, j-i+1);
                for(int k=0 ; k<b.size() ; k++){
                    if(b[k] == r[0]){
                        if(b.substr(k, r.size()) == r){
                            int cost = a.size()+b.size() - 2*r.size();
                            if(cost < main_cost) main_cost = cost;
                        }
                    }
                }
            }
        }

        cout<<main_cost<<endl;

    }

    return 0;
}