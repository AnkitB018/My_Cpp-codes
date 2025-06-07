#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class stack{
    Node *top;
    public:
        stack(){
            top = new Node();
            top = NULL;
        }

        void push(int val){
            Node *t = new Node();
            t->data = val;
            if(t == NULL){
                return;
            }
            t->next = top;
            top = t; 
        }

        int pop(){
            if(top ==NULL){
                return -1;
            }
            Node *temp = top;
            top = top->next;
            int val = temp->data;
            delete temp;
            return val;
        }

        int peek(){
            if(top ==NULL){
                return -1;
            }
            return top->data;
        }

        void display(){
            if(isempty()){
                cout<<"It is empty!"<<endl;
                return;
            }
            Node *temp = top;
            while(temp->next!=NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<temp->data;
        }
        
        void display_in_reverse(Node *top){
            if(top == NULL){
                cout<<"Empty!"<<endl;
            }
            if(top->next == NULL){
                cout<<top->data<<"->";
                return;
            }
            display_in_reverse(top->next);
            cout<<top->data<<"->";

        }

        Node* get_top(){
            return top;
        }

        bool isempty(){
            if(top == NULL){
                return true;
            }
            return false;
        }

};

class queue_using_stack{
    stack s1 ,s2;
    public:
        void enqueue(int val){
            s1.push(val);
            cout<<"Enqueued successfully value: "<<val<<endl;
        }

        int dequeue(){
            int res;
            if(!s2.isempty()){
                res = s2.pop();
                cout<<"Value dequeued successfully: "<<res<<endl;
                return res;
            }
            while(!s1.isempty()){
                s2.push(s1.pop());
            }
            res = s2.pop();
            cout<<"Value dequeued successfully: "<<res<<endl;
            return res;
        }

        bool isempty(){
            if(s1.isempty() && s2.isempty()){
                return true;
            }
            return false;
        }

        void display(){
            if(!s2.isempty()){
                s2.display();
                cout<<"->";
            }
            if(!s1.isempty()){
                Node *top = s1.get_top();
                s1.display_in_reverse(top);
            }
            
        }


        
};


int main(){

    //stack s;
    //s.push(4);
    //s.push(3);
    //s.push(1);
    //s.display();
    //cout<<endl;
    //s.display_in_reverse(s.get_top());


    queue_using_stack q1;
    q1.enqueue(4);
    q1.enqueue(2);
    q1.enqueue(6);
    q1.dequeue();
    q1.enqueue(3);
    q1.enqueue(5);

    q1.display();


return 0;
}
