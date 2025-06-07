#include<iostream>
using namespace std;

class queue{
    int size;
    int front;
    int rear;
    int *arr;

    public:
        queue(int s){
            this->size = s;
            front = -1;
            rear = -1;
            arr = new int[s];
        }
        ~queue(){
            delete []arr;
        }

        void enqueue(int val){
            if(front == (rear+1)%size){
                cout<<"Queue is full! "<<endl;
                return;
            }
            if(front == -1){
                front = 0;
            }
            rear = (rear+1)%size;
            arr[rear] = val;
            cout<<"Successfully enqueued value: "<<val<<endl;
        }

        int dequeue(){
            int temp;
            if(front == -1 && rear == -1){
                cout<<"Queue is empty!"<<endl;
                return -1;
            }
            if(front == rear){
                temp = arr[front];
                front = rear = -1;
                cout<<"Value dequeued successfully: "<<temp<<endl;
                return temp;
            }
            temp = arr[front];
            front = (front+1)%size;
            cout<<"Value dequeued successfully: "<<temp<<endl;
            return temp;
        }

        bool isempty(){
            if(front == rear){
                return true;
            }
            return false;
        }

        bool isfull(){
            if(front = (rear+1)%size){
                return true;
            }   
            return false;
        }

};


int main(){
    queue q(5);
    q.dequeue();
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(3);

return 0;
}