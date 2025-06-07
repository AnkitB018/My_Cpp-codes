#include<iostream>
using namespace std;

class element{
    public:
        int i;
        int j;
        int val;
};

class sparse{
    private:
        int m;
        int n;
        int num;
        element *ele;
    public:
        sparse(int m , int n,int num){
            this->m = m;
            this->n = n;
            this->num = num;
            ele = new element[num];
        }

        ~sparse(){
            delete [] ele;
        }

        friend istream &operator >>(istream &is, sparse &s);
        friend ostream &operator <<(ostream &os, sparse &s);
        sparse operator +(sparse &s); // if we used friend we needed to pass 2 sparse but in case of scope resolution we can just pass one of them as the other one is the class itself(the called one)

};

sparse sparse:: operator + (sparse &s){ 
    int i,j,k;
    sparse *res = new sparse(n,m,num+s.num);
    if(m != s.m || n != s.n){
        return *res;
    }
    i=j=k=0;
    while(i<num && j<s.num){
        if(ele[i].i<s.ele[j].i){
            res->ele[k++] = ele[i++];
        }else if(ele[i].i>s.ele[j].i){
            res->ele[k++] = s.ele[j++];
        }else{
            if(ele[i].j < s.ele[j].j){
                res->ele[k++] = ele[i++];
            }else if(ele[i].j>s.ele[j].j){
                res->ele[k++] = s.ele[j++];
            }else{
                res->ele[k].i = ele[i].i;
                res->ele[k].j = ele[i].j;
                res->ele[k++].val = s.ele[j++].val+ele[i++].val;
            }
        }   
    }
    
    for(;i<num;i++){
        res->ele[k++] = ele[i];
    }
    for(;j<s.num;j++){
        res->ele[k++] = s.ele[j];
    }

    return *res;

}

istream & operator >>(istream &is, sparse &s){
    cout<<"Enter non-zero elements and their indices (i , j , value): ";
    for(int i=0 ; i<s.num ; i++){
        cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].val;
    }
    return is;
}

ostream & operator <<(ostream &os, sparse &s){
    int k=0;
    for(int i=0 ; i<s.m ; i++){
        for(int j=0 ; j<s.n ; j++){
            if(s.ele[k].i == i && s.ele[k].j == j){
                cout<<s.ele[k++].val<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return os;
}


int main(){
    sparse s1(5,5,5);
    sparse s2(5,5,5);
    cin>>s1;
    cin>>s2;

    sparse s3 = s1 + s2;

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;

return 0;
}