#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main(){
    string a = "1011";
    int dec1 = 0;
    for(int i = 0 ; i<a.length() ; i++){
        if(a.at(a.length()-1-i) == '1'){
            dec1+=  pow(2,i);
        }
    }
    cout<<dec1;
return 0;

}