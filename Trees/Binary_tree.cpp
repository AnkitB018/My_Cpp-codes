#include<iostream>
#include <algorithm>
#include<stack>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class queue{
    int size;
    int front;
    int rear;
    Node **arr;

    public:
        queue(int s = 10){
            this->size = s;
            front = -1;
            rear = -1;
            arr = new Node*[s];
        }
        ~queue(){
            delete []arr;
        }

        void enqueue(Node* val){
            if(front == (rear+1)%size){
                cout<<"Queue is full! "<<endl;
                return;
            }
            if(front == -1){
                front = 0;
            }
            rear = (rear+1)%size;
            arr[rear] = val;
        }

        Node* dequeue(){
            Node* temp;
            if(front == -1 && rear == -1){
                cout<<"Queue is empty!"<<endl;
                return NULL;
            }
            if(front == rear){
                temp = arr[front];
                front = rear = -1;
                return temp;
            }
            temp = arr[front];
            front = (front+1)%size;
            return temp;
        }

        bool isempty(){
            if(front == -1 && rear == -1){
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

class tree{
    public:
        Node *root;
        tree(){
            root = NULL;
        }
        
        void create(){
            Node *t,*p;
            queue q;
            int val;
            cout<<"Enter value of root node"<<endl;
            cin>>val;
            root = new Node;
            root->data = val;
            root->left = NULL;
            root->right = NULL;
            q.enqueue(root);
            while(!q.isempty()){
                p = q.dequeue();
                cout<<"Enter value of left child:"<<endl;
                cin>>val;
                if(val != -1){
                    Node *temp = new Node;
                    temp->data = val;
                    temp->left = NULL;
                    temp->right = NULL;
                    p->left = temp;                                                                             
                    q.enqueue(temp);
                }
                cout<<"Enter value of right child:"<<endl;
                cin>>val;
                if(val!= -1){
                    Node *temp = new Node;
                    temp->data = val;
                    temp->left = NULL;
                    temp->right = NULL;
                    p->right = temp;                                                                             
                    q.enqueue(temp);
                }
            }
        }

        void preorder(Node *r){
            if(r){
                cout<<r->data<<"  ";
                preorder(r->left);
                preorder(r->right);
            }
        }

        void iterative_preorder(){
            stack<Node*>st;
            Node *t = root;
            while(t != NULL || !st.empty()){
                if(t != NULL){
                    cout<<t->data<<"  ";
                    st.push(t);
                    t = t->left;
                }else{
                    t = st.top();
                    t = t->right;
                    st.pop();
                }
            }
            cout<<endl;
        }

        void inorder(Node *r){
            if(r){
                inorder(r->left);
                cout<<r->data<<"  ";
                inorder(r->right);
            }
        }

        void iterative_inorder(){
            stack<Node *>st;
            Node *t = root;
            while(t || !st.empty()){
                if(t){
                    st.push(t);
                    t = t->left;
                }else{
                    t = st.top();
                    st.pop();
                    cout<<t->data<<"  ";
                    t = t->right;
                }
            }

            cout<<endl;
        }

        
        void postorder(Node *r ){
            if(r){
                postorder(r->left);
                postorder(r->right);
                cout<<r->data<<"  ";
            }
        }

        void levelorder(){
            Node *p;
            queue q;
            cout<<root->data<<"  ";
            q.enqueue(root);
            while(!q.isempty()){
                p = q.dequeue();
                if(p->left){
                    cout<<p->left->data<<"  ";
                    q.enqueue(p->left);
                }
                if(p->right){
                    cout<<p->right->data<<"  ";
                    q.enqueue(p->right);
                }
            }
            cout<<endl;
        }

        int nodes(Node *r){
            if(!r){
                return 0;
            }
            return 1+nodes(r->left)+nodes(r->right);
        }

        int height(Node *r){
            if(!r){
                return 0;
            }
            return 1+max(height(r->left),height(r->right));
        }

        int count_leaf(Node *r){
            int x,y;
            if(r){
                x = count_leaf(r->left);
                y = count_leaf(r->right);
                if(r->left == NULL && r->right == NULL){
                    return x+y+1;
                }else{
                    return x+y;
                }
            }else{
                return 0;
            }
        }

        int count_internal(Node *r){
            int x,y;
            if(r){
                x = count_internal(r->left);
                y = count_internal(r->right);
                if(r->left != NULL || r->right != NULL){
                    return x+y+1;
                }else{
                    return x+y;
                }
            }else{
                return 0;
            }
        }


};


int main(){
    tree t1;
    t1.create();
    cout<<endl;
    t1.levelorder();
    cout<<endl;
    t1.preorder(t1.root);
    cout<<endl;
    t1.iterative_preorder();
    cout<<endl;
    t1.inorder(t1.root);
    cout<<endl;
    t1.iterative_inorder();
    cout<<endl;
    int nodes = t1.nodes(t1.root);
    int h = t1.height(t1.root);
    cout<<"No of nodes: "<<nodes<<endl<<"Height: "<<h<<endl;
    cout<<"No of leafs: "<<t1.count_leaf(t1.root)<<endl<<"No of internal Nodes:"<<t1.count_internal(t1.root)<<endl;
    return 0;
    
}