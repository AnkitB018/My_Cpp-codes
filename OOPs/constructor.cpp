#include<iostream>
using namespace std;


class student{
    int roll ;
    string name;
    public:
        student(string s){
            name = s;
            roll = 0;
        }
        void set_roll(){
            cout<<"Enter roll no."<<endl;
            cin>>roll;
            cout<<"Roll updated";
        }
        void get_data(){
            cout<<"Name is "<< name<<endl;
            cout<<"Roll no is: "<<roll << endl;
            
        }

};


int main(){

    return 0;
}