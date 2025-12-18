#include<iostream>
using namespace std;


int pow(int a, int b){
    if(a ==0){
        return 0;
    }
    if(a == 1 || b == 1 || b==0 ){
        return 1;
    }
    return a*pow(a , b-1);
}


int bin_to_dec(string bin){
    int ans=0;
    for(int i=bin.length()-1; i>=0 ; i--){
        if(bin.at(i) == '1'){
            ans += pow(2 , bin.length()-1-i);
        }
    }
    return ans;
}

int main(){
    string bin = "11001";
    int dec = bin_to_dec(bin);
    cout<<"Decimal value of the binary "<<bin<<" is: "<<dec;
    return 0;
}