#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node(){
            next = NULL;
        }
        Node(int data){
            val = data;
            next = NULL;
        }
};

class queue{
    Node *front;
    Node *rear;
    public:
        queue(){
            front = new Node();
            front = NULL;
            rear = new Node();
            rear = NULL;
        }
        
        void enqueue(int data){
            Node *add = new Node(data);
            if(add == NULL){
                cout<<"queue is full! "<<endl;
                return;
            }
            add->val = data;
            if(front == NULL && rear == NULL){
                cout<<"enqueued successfully: "<<data<<endl;
                front = rear = add;
                return;
            }
            rear->next = add;
            rear = add;
            cout<<"enqueued successfully: "<<data<<endl;
        }

        int dequeue(){
            int temp;
            if(front == NULL){
                cout<<"Queue is empty! "<<endl;
                return -1;
            }
            Node *t = front;
            temp = t->val;
            if(front == rear){
                front = rear = NULL;
                cout<<"Successfully dequeued value: "<<temp<<endl;
                return temp;
            }
            front = front->next;
            delete t;
            cout<<"Successfully dequeued value: "<<temp<<endl;
            return temp;
        }

        bool isempty(){
            if(front == NULL){
                return true;
            }
            return false;
        }

};



int main(){
    queue q;
    q.dequeue();
    q.enqueue(4);
    q.enqueue(6);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(1);
    q.dequeue();
    q.dequeue();

return 0;
}