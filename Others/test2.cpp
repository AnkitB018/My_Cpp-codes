#include<iostream>
#include<iomanip>

using namespace std;
int a = 18;
int main(){
    //int a = 25;
    //int &b = a;
    //int &c = ::a;
    //cout<<"The value of a is "<<a<<endl;
    //cout<<"The value of a through be is "<<b<<endl;
    //cout<<"The value of global a is "<<::a<<endl;
    //cout<<"The value of global a thorugh c is "<<c<<endl;

    //b++;
    //cout<<a;

    int select ;
    cout<<"Enter your selected number (1-3): "<<endl;
    cin>>select;
    if(select>3){
        cout<<"what!";
    }
    switch(select){
        case 1:
            cout<<"You won";
            break;
        case 2:
            cout<<"stupid";
            break;
        case 3:
            cout<<"Nope";
            break;
        default:
            cout<<"select a valid number !!";
            break;

    }
    string name = " ankit";
    cout<<name;

}