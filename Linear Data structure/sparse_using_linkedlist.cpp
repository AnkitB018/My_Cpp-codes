#include<iostream>
using namespace std;

class Node{
    public:
        int col;
        int val;
        Node* next;
};

class sparse{
    Node *arr;
    int n;
    int m;
    int num;
    public:
        sparse(int n , int m, int num){
            this->n = n;
            this->m = m;
            arr = new Node[n];
            for(int i=0 ; i<n ; i++){
                arr[i].next = NULL;
            }
            this->num = num;
        }

        ~sparse(){
            for (int i = 0; i < n; ++i) {
                 Node* temp = arr[i].next;
                    while (temp) {
                        Node* next = temp->next;
                        delete temp;
                        temp = next;
                    }
            }
            delete []arr;
            cout<<"Memory freed!";
        }

        friend istream &operator >>(istream &is, sparse &s);
        friend ostream &operator <<(ostream &os, sparse &s);
        friend sparse operator +(sparse &s1 , sparse &s2);
};

istream &operator >>(istream &is, sparse &s){
    int i,j,val;
    for(int k=0 ; k<s.num ; k++){
        cout<<"Enter Row, column and value of non-zero elements(in correct order for each row): "<<endl;
        cin>>i>>j>>val;
        Node *p = &(s.arr[i]);
        while(p->next){
            p = p->next;
        }
        Node *add =new Node();
        add->val = val;
        add->col = j;
        p->next = add;
        add->next = NULL; 
    }
    return is;
}

ostream &operator <<(ostream &os, sparse &s){
    for(int i=0 ; i<s.n ; i++){
        Node *p = s.arr[i].next;
        for(int j=0 ; j<s.m ; j++){
            if(p != NULL && p->col == j){
                cout<<p->val<<" ";
                p = p->next;
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;

    return os;
}

sparse operator +(sparse &s1 , sparse &s2){
    sparse res(s1.n  , s2.m , s1.num+s2.num);
    for(int i=0 ; i<s1.n ; i++){
        Node *p1 = s1.arr[i].next;
        Node *p2 = s2.arr[i].next;
        Node *p3 = &res.arr[i];
        while(p1 && p2){
            if(p1->col < p2->col){
                Node *add = new Node();
                add->col = p1->col;
                add->val = p1->val;
                p3->next = add;
                p3 = p3->next;
                p1 = p1->next;
            }else if(p1->col > p2->col){
                Node *add = new Node();
                add->col = p2->col;
                add->val = p2->val;
                p3->next = add;
                p3 = p3->next;
                p2 = p2->next;
            }else{
                Node *add = new Node();
                add->col = p2->col;
                add->val = p2->val+p1->val;
                p3->next = add;
                p3= p3->next;
                p1= p1->next;
                p2=p2->next;
            }
        }
        if(p2 != NULL){
            while(p2){
                Node *add = new Node();
                add->col = p2->col;
                add->val = p2->val;
                p3->next = add;
                p3 = p3->next;
                p2 = p2->next;
            }
        }else if(p1 != NULL){
            while(p1){
                Node *add = new Node();
                add->col = p1->col;
                add->val = p1->val;
                p3->next = add;
                p3 = p3->next;
                p1 = p1->next;
            }
        }   
    }

    return res;
}



int main(){
    sparse s1(3, 4, 5);
    sparse s2(3,4,4);

    cout<<"Enter for s1:"<<endl;
    cin>>s1;
    cout<<"Enter for s2:"<<endl;
    cin>>s2;

    sparse s3 = s1+s2;
    
    cout<<"Here are the metrices:"<<endl;
    cout<<s1;
    cout<<s2;
    cout<<s3;

return 0;
}