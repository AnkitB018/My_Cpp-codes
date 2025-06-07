#include<iostream>
using namespace std;

class element{
    public:
        int exp;
        int co;
};

class poly{
    int n;
    element *ele;
    public:
        poly(int n){
            this->n = n;
            ele = new element[n];
        }

        ~poly(){
            delete []ele;
        }

        friend istream &operator >>(istream &is , poly &p);
        friend ostream &operator <<(ostream &os , poly &p);
        friend poly operator+(poly &p1 , poly &p2);
};

istream &operator >>(istream &is , poly &p){
    cout<<"Enter exponenet and co-efficients: "<<endl;
    for(int i=0 ; i<p.n ; i++){
        cin>>p.ele[i].exp>>p.ele[i].co;
    }
    return is;
}

ostream &operator <<(ostream &os , poly &p){
    for(int i=0 ; i<p.n;i++){
        cout<<p.ele[i].co<<"x^"<<p.ele[i].exp;
        if(i < p.n-1){
            cout<<"+";
        }
    }
    cout<<endl;
    return os;
}

poly operator+(poly &p1 , poly &p2){
    poly *res = new poly(p1.n+p2.n);
    int i,j,k;
    i=j=k=0;
    while(i<p1.n && j<p2.n){
        if(p1.ele[i].exp > p2.ele[i].exp){
            res->ele[k++] = p1.ele[i++];
        }else if(p1.ele[i].exp < p2.ele[j].exp){
            res->ele[k++] = p2.ele[j++];
        }else{
            res->ele[k].exp = p1.ele[i].exp;
            res->ele[k++].co = p1.ele[i++].co+p2.ele[j++].co;
        }
    }

    for(;i<p1.n ; i++){
        res->ele[k++] = p1.ele[i];
    }
    for(;j<p2.n ; j++){
        res->ele[k++] = p2.ele[j];
    }
    res->n = k;
    return *res;
}


int main(){
    poly p1(3);
    poly p2(4);
    cin>>p1;
    cin>>p2;

    poly p3 = p1 + p2;

    cout<<p1;
    cout<<p2;
    cout<<p3;
 
    return 0;
}
