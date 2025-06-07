#include<iostream>
#include<string>
using namespace std;

class person{
    string name;
    int age;
    public:
        friend ostream &operator << (ostream &output, person &p); // here ostream is the return type, operator defines on which operator it will work, here it is <<
        friend istream &operator >> (istream &input , person &p); //friend function makes it globally definable without needing scope resolution operator
};

istream &operator >> (istream &input , person &p){
    cout<<"Enter your name and age: ";
    cin>>p.name>>p.age;
    cout<<endl;
    return input;
}


ostream &operator << (ostream &output, person &p){
    cout<<"My name is "<<p.name<<" and my age is "<<p.age<<endl;
    return output;
}


int main(){
    person p;
    cin>>p;
    cout<<p;
    return 0;
}