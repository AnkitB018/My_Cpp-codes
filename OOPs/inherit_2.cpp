#include<iostream>
using namespace std;

class Base{
        int data1;
    protected:
        int data2;
    public:
        int data3;
        Base(){
            cout<<"Set data1: ";
            cin>>data1;
            cout<<endl<<"Set data2: ";
            cin>>data2;
            cout<<endl<<"Set data3: ";
            cin>>data3;
        }
        int get_data1(){
            return data1;
        }
};
class derived :public Base{
        int data4;
        public: 
            
            void disp_data(){
                cout<<"data1: "<<get_data1() << endl;
                cout<<"data2: "<<data2 << endl;
                cout<<"data3: "<<data3 << endl;
                cout<<"data4: "<<data4 << endl;
            }

    

};


int main(){
    derived d1;
    d1.disp_data();
    return 0;
}