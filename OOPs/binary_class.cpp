#include<iostream>
#include<string>
using namespace std;

int power_two(int i){
    int temp = 1;
    for(int j = 0 ; j<i ; j++){
        temp *=2;
    }
    return temp;
}

class binary{
    public : 
        string s;
    void take_string(){
        cout<<"Enter your binary number"<<endl;
        string temp;
        cin>> temp;
        for(int i = 0 ; i<temp.length() ; i++){
            if(temp.at(i)!='0' && temp.at(i)!= '1'){
                cout<<"Entered number is not binary!"<<endl;
                exit(0);
            }
        }
        cout<<"value stored successfully"<<endl;
        s = temp;
    }

    int decimal_eq(){
        int ans = 0;
        for(int i = s.length()-1,j=0 ; i>=0 ; i--,j++){
            if(s.at(i) == '1'){
                ans += power_two(j);
            }
        }
        cout<<"Decimal equivalent of your binary is : "<< ans<<endl;
        return ans;
    }

    string one_comp(){
        string temp;
        temp = s;
        for(int i = 0 ; i<temp.length();i++){
            if(temp.at(i) == '0'){
                temp.at(i) = '1';
            }else{
                temp.at(i) = '0';
            }
        }
        cout<<"1's complement: "<<temp<<endl;
        return temp;
    }

    string two_comp();

};
string binary :: two_comp(){
    string temp ; 
    temp = s;
    int i = temp.length()-1;
    for(i ; i>=0 ; i--){
        if(temp.at(i) == '1'){
            i--;
            break;
        }
    }
    for(i ; i>=0;i--){
        if(temp.at(i) == '0'){
            temp.at(i) = '1';
        }else{
            temp.at(i) = '0';
        }
    }
    cout<<"2's complement: "<<temp<<endl;
    return temp;
}

int main(){
    
    binary s1;
    s1.take_string();
    s1.decimal_eq();
    s1.one_comp();
    s1.two_comp();
    return 0;
}