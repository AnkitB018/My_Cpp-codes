#include<iostream>
#include<vector>


using namespace std;

template<class T=int>
class stack_local{
    vector<T>st;
    int top;
    public:
    stack_local(){
        top = -1;
    }

    void push(int val);
    T pop();
    T peek();
    bool isempty();
};

template<class T>
bool stack_local<T>:: isempty(){
    return top == -1;
}

template<class T>
void stack_local<T> :: push(int val){
    st.push_back(val);
    top++;
}

template<class T>
T stack_local<T>::pop(){
    if(isempty()){
        cout<<"Stack Underflow!";
        return -1;
    }
    T val = st[top--];
    st.pop_back();
    return val;
}

template<class T>
T stack_local<T>::peek(){
    if(isempty()){
        cout<<"Stack is empty!";
        return -1;
    }
    return st[top];
}


string infix_to_postfix(string s){
    
}


int main(){
    stack_local<char>st;
    st.push('c');
    char op = st.pop();
    cout<<op;
    st.push('a');
    st.push('b');
    st.push('d');
    op = st.pop();
    op = st.pop();
    cout<<op;

}