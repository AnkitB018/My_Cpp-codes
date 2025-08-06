#include<iostream>
#include<vector>
using namespace std;

void perm(int k, string&a, vector<int>&set){
    static string b= a;
    if(k == set.size()){
        cout<<b<<endl;
    }
    for(int i=0 ; i<set.size() ; i++){
        if(set[i] == 0){
            b[k] = a[i];
            set[i] = 1;
            perm(k+1, a, set);
            set[i] = 0;
        }
    }
}

void perm_no_consecutive(int k, string&a, vector<int>&set){
    static string b= a;
    if(k == set.size()){
        cout<<b<<endl;
    }
    for(int i=0 ; i<set.size() ; i++){
        if(set[i] == 0){
            if(k>0 && a[i]-b[k-1] == 1){
                continue;
            }
            b[k] = a[i];
            set[i] = 1;
            perm_no_consecutive(k+1, a, set);
            set[i] = 0;
        }
    }


}


int main(){
    string a = "abcdef";
    int n= a.length();
    vector<int> set(n, 0);
    perm_no_consecutive(0, a, set);    
return 0;
}