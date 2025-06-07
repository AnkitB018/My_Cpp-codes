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

        void display(){
            Node *temp = front;
            if(front == NULL){
                cout<<"Empty queue!";
                cout<<endl;
                return;
            }
            cout<<temp->val;
            if(temp->next == NULL){
                cout<<endl;
                return;
            }
            while(1){
                cout<<"->";
                temp = temp->next;
                cout<<temp->val;
                if(temp->next == NULL){
                    cout<<endl;
                    return;
                }
            }
        }
};


class priority_queue{
    int size;
    queue *arr;
    public:
        priority_queue(int pr){
            size = pr;
            arr = new queue[size];
        }

        void enqueue(int val , int priority){
            if(priority>size){
                cout<<"invalid priority! "<<endl;
                return;
            }
            arr[priority-1].enqueue(val);
        }

        int dequeue(){
            int temp = -1;
            for(int i=0 ; i<size ; i++){
                if(!arr[i].isempty()){
                    temp = arr[i].dequeue();
                    break;
                }
                if(i==size-1){
                    cout<<"All queues are empty!"<<endl;
                }
            }
            return temp;
        }

        void display(){
            for(int i=0 ; i<size; i++){
                cout<<"QUEUE "<<i+1<<"--->"<<endl;
                arr[i].display();
            }
        }

};

int main(){
    priority_queue p1(3);
    p1.enqueue(4,1);
    p1.enqueue(2,1);
    p1.enqueue(6,1);
    p1.enqueue(7,2);
    p1.enqueue(5,2);
    p1.enqueue(3,2);
    p1.enqueue(0,2);
    p1.enqueue(2,3);
    p1.enqueue(1,3);
    p1.enqueue(7,3);
    p1.enqueue(8,3);
    p1.enqueue(3,3);
    p1.display();
    p1.dequeue();
    p1.dequeue();
    p1.display();
    p1.dequeue();
    p1.display();
    p1.dequeue();
    p1.display();
    p1.enqueue(90,1);
    p1.display();
    p1.dequeue();
    p1.display();

return 0;
}