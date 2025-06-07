#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
        char data;
        Node* next;
};

class stack2{
    Node *top;
    public:
        stack2(){
            top = NULL;
        }

        void push(char val){
            Node *t = new Node();
            t->data = val;
            if(t == NULL){
                cout<<"Stack Overflow!"<<endl;
                return;
            }
            t->next = top;
            top = t; 
            cout<<"Successfully pushed!"<<endl;
        }

        int pop(){
            if(top ==NULL){
                cout<<"Stack is empty!"<<endl;
                return '\0';
            }
            Node *temp = top;
            top = top->next;
            char val = temp->data;
            delete temp;
            cout<<"Successfully popped: "<<val<<endl;
            return val;
        }

        int peek(){
            if(top ==NULL){
                cout<<"Stack is empty!"<<endl;
                return '\0';
            }
            return top->data;
        }
        
        bool isempty(){
            if(top == NULL){
                return true;
            }
            return false;
        }

};


bool is_operand(char c){
    if(c == '+' || c == '-' ||c == '*' ||c == '/' || c == '^' || c == '(' || c==')'){
        return false;
    }
    return true;
}

int priority(char c){
    if(c == '+' || c == '-'){
        return 1;
    }else if(c == '*' ||c == '/'){
        return 2;
    }else if(c == '^'){
        return 3;
    }
    return 0;
}



//infix to postfix
string convert_to_post(string s){
    string result = s;
    stack2 st;
    int i,j;
    i=j=0;
    while(i<s.length()){
        if(is_operand(s[i])){
            result[j++] = s[i++];
        }else{
            if(priority(s[i]) > priority(st.peek())){
                st.push(s[i++]);
            }else{
                result[j++] = st.pop();
            }
        }
    }

    while(!st.isempty()){
        result[j++] = st.pop();
    }

    return result;
}


string advanced_post(string s){
    string result;
    stack2 st;
    int i;
    i=0;
    while(i<s.length()){
        if(is_operand(s[i])){
            result.push_back(s[i++]);
        }else{
            if(s[i] == '('){
                st.push(s[i++]);
                continue;
            }else if(s[i] == ')'){
                while(st.peek() != '(' && st.isempty() == false){
                    result.push_back(st.pop());
                }
                if(!st.isempty()) st.pop();  
                i++;
                continue;
            }
            if(priority(s[i]) > priority(st.peek()) || (priority(s[i]) == 3 && priority(st.peek()) == 3)){
                st.push(s[i++]);
                continue;
            }else{
                result.push_back(st.pop());
            }
        }
    }

    while(!st.isempty()){
        result.push_back(st.pop());
    }

    return result;

}

int pow_local(int base , int exp){
    int res = 1;
    for(int i=0 ; i<exp ; i++){
        res = res*base;
    }
    return res;
}

int post_eval(string post){
    stack<int> st; //need integer stack our defined stack is of char type
    int i=0;
    while(i<post.length()){
        if(is_operand(post[i])){
            st.push(post[i++]-'0');
        }else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c;
            switch(post[i]){
                case '+' : c = a+b; break;
                case '-' : c = b-a; break;
                case '*' : c = a*b; break;
                case '/' : c = b/a; break;
                case '^' : c = pow_local(b,a); break;
            }
            st.push(c);
            i++;
        }
    }

    int ans = st.top();
    st.pop();
    return ans;
    
}


//infix to prefix left (same as post fix just reverse and return reversed and same priority also waits) 


int main(){
    string s= "((a+b)*c)-d^e^f";
    string res = advanced_post(s);
    string s1 = "a+b*(c+b-h*d)/d^r^g^y-a";
    string res1 = advanced_post(s1);
    string s2 = "1+2*(4-2*3)+4^2";
    string res2 = advanced_post(s2);
    int ans = post_eval(res2);

    cout<<endl<<endl;

    cout<<"Infix string: "<<s<<endl;
    cout<<"postfix string: "<<res<<endl;

    cout<<"Next one->"<<endl<<endl;

    cout<<"Infix string: "<<s1<<endl;
    cout<<"postfix string: "<<res1<<endl;

    cout<<"Next one->"<<endl<<endl;

    cout<<"Infix string: "<<s2<<endl;
    cout<<"postfix string: "<<res2<<endl;
    cout<<"value of the post fix: "<<ans<<endl;


    return 0;

}