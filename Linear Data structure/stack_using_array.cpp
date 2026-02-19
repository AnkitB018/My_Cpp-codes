#include<iostream>
using namespace std;

class stack_test{
    int size;
    int top;
    int *arr;
    public:
        stack_test(int size){
            this->size = size;
            top = -1;
            arr = new int[size];
        }

        ~stack_test(){
            delete []arr;
        }

        void push(int val){
            if(top == size-1){
                cout<<"Stackoverflow, push failed!"<<endl;
                return;
            }
            top++;
            arr[top] = val;
            cout<<"Push operation successful!"<<endl;
        }
        
        int pop(){
            if(size == -1){
                cout<<"Stack is empty!"<<endl;
                return -1;
            }
            int res = arr[top];
            top--;
            cout<<"Successfully popped!"<<endl;
            return res;
        }

        bool isempty(){
            if(top == -1){
                return true;
            }else{
                return false;
            }
        }

        bool isfull(){
            if(top = size-1 ){
                return true;
            }else{
                return false;
            }
        }

        int peek(){
            if(isempty() ){
                cout<<"No element in stack!"<<endl;
            }else{
                return arr[top];
            }
        }
};


int main(){
    
    stack_test s1(5);
    s1.push(1);
    s1.push(2);
    cout<<s1.pop()<<endl;
    s1.push(4);
    cout<<s1.peek()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.isempty()<<endl;
    s1.push(10);
    s1.push(11);
    s1.push(4);
    s1.push(7);
    s1.push(5);
    cout<<s1.pop()<<endl;
    s1.push(2);

return 0;
}