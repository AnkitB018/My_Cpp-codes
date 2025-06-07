#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
};

class list{
    Node *head;
    public:
        list(){
            head = new Node();
            head = NULL;    
        }
        list(int val){
            head = new Node();
            head->val = val;
            head->next = NULL;
        }
        ~list(){
            Node *temp = head;
            Node *prev = NULL;
            while(temp){
                prev = temp;
                temp = temp->next;
                delete prev; // as this is a single object we only do delete prev not delete[]prev
            }
        }
        void add_end(int val);
        void add_begin(int val);
        void add_middle(int i, int val);
        void add_list(int *a , int n);
        void del(int val);
        void display();
        int count();
        void reverse();
};

void list::add_end(int val){
    if(head == NULL){
        head->val = val;
        head->next = NULL;
        return;
    }
    Node *new_node = new Node();
    new_node->val = val;
    new_node->next = NULL;
    Node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new_node;
    cout<<"Successfully added!"<<endl;
    return;
}

void list::add_begin(int val){
    Node *new_node = new Node();
    new_node->val = val;
    new_node->next = head;
    head = new_node;
    cout<<"Successfully added!"<<endl;
}

void list::add_list(int *a , int n){
    Node *temp = head;
    if(head != NULL){
        while(temp->next){
            temp = temp->next;
        }
    }
    for(int i=0 ; i<n ; i++){
        Node * add = new Node();
        add->val = a[i];
        add->next = NULL;
        if(head ==NULL){
            head = add;
            temp = add;
        }else{
            temp->next = add;
            temp = add;
        }    
    }
    cout<<"List successfully added!"<<endl;
}
void list :: add_middle(int i , int val){
    Node *temp = head;
    Node *real = new Node();
    real->val = val;
    real->next = NULL;
    for(int j=0 ; j<i-1 ; j++){
        if(temp ==NULL){
            cout<<"Index out of range!"<<endl;
            return;
        }
        temp = temp->next;
    }
    real->next = temp->next;
    temp->next = real;
    cout<<"Successfully added!"<<endl;
}

void list::del(int val){
    Node* temp = head;
    Node* prev = NULL;
    while(temp && temp->val != val){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"element not found!"<<endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout<<"Successfully deleted!"<<endl;
}

void list:: display(){
    Node *temp = head;
    while(temp){
        cout<<temp->val;
        temp = temp->next;
        if(temp != NULL){
            cout<<"->";
        }
    }
    cout<<endl;
}

int list::count(){
    int no=0;
    Node *temp = head;
    while(temp){
        temp = temp->next;
        no++;
    }
    cout<<"No of elements currently in linked list: "<<no<<endl;
    return no;
}

void list:: reverse(){
    if(head==NULL){
        return;
    }
    Node *curr = head;
    Node *next = curr->next;
    Node *prev = NULL;
    Node *temp;
    while(next){
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    head = curr;
    cout<<"List reversed successfully! "<<endl;
}

int main(){
    list l1(1);
    l1.add_end(2);
    l1.add_begin(4);
    int a[5] = {1,2,3,4,5};
    l1.add_list(a,5);
    l1.display();
    cout<<"Let's delete the first 1:"<<endl;
    l1.del(1);
    l1.display();
    l1.reverse();
    l1.display();

return 0;
}