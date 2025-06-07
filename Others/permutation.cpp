#include<iostream>
#include<string>
using namespace std;

void permutation(string s, int k){
    static int a[10];
    static char result[10];
    if(s[k] == '\0'){
        cout<<result<<endl;
        k--;
        return;
    }

    for(int i=0 ; s[i]!='\0' ; i++){
        if(a[i] == 0){
            a[i] = 1;
            result[k] = s[i];
            permutation(s , k+1);
            a[i] = 0;
        }
    }

}

void perm(string &s, int l, int h){
    if(l == h){
        cout<<s<<endl;
        return;
    }
    char temp;
    for(int i=l ; i<=h ; i++){
        temp = s[i];
        s[i] = s[l];
        s[l] = temp;
        perm(s,l+1,h);
        temp = s[i];
        s[i] = s[l];
        s[l] = temp;
    }

}

int main(){

    //permutation("ABCDEFGH" , 0);
    string s = "ABCDE"; 
    perm(s , 0 , 4);
    return 0;

}