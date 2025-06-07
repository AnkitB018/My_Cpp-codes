#include<iostream>
using namespace std;


class data{
    protected:
        string name;
        int roll;
    public:
        data(string name , int roll){
            this->name = name;
            this->roll = roll;
        }
        virtual void display() = 0;
};

class result : public data{
    protected:
        int OS;
        int CN;
        int TOC;
    public:
        result(string name , int roll , int os , int cn , int toc):data(name , roll){
            this->OS = os;
            this->CN = cn;
            this->TOC = toc;
        }
        void display();
};

void result ::display(){
    cout<<"name-> "<<name<<endl<<"roll-> "<<roll<<endl<<"Marks: "<<endl<<"\tOS-> "<<this->OS<<endl<<"\tCN-> "<<this->CN<<endl<<"\tTOC-> "<<this->TOC<<endl;
    cout<<this->name <<" your percentage is: "<<(OS+TOC+CN)/3<<endl;
}

int main(){
    result r1("Ankit" , 23 , 87 , 98 , 84);
    r1.display();
    return 0;
}