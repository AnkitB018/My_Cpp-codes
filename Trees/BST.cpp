#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(){
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    void insert(int key)
    {
        Node *t = root, *p = nullptr;
        Node *newNode = new Node;
        newNode->data = key;
        newNode->left = newNode->right = nullptr;

        if(root == NULL){
            root = newNode;
            cout<<"Root inserted!"<<endl;
            return;
        }

        while (t)
        {
            if (t->data == key)
            {
                cout << "data already present!" << endl;
                return;
            }
            p = t;
            if (t->data > key)
            {
                t = t->left;
            }
            else
            {
                t = t->right;
            }
        }

        if (key < p->data)
        {
            p->left = newNode;
        }
        else
        {
            p->right = newNode;
        }

        cout << "Inserted successfully!" << endl;
    }

    void insert_list(vector<int> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            int key = a[i];
            insert(key);
        }
    }

    void inorder(Node *t)
    {
        if (t)
        {
            inorder(t->left);
            cout << t->data << "  ";
            inorder(t->right);
        }
    }

    void preorder(Node *t){
        if(t){
            cout<<t->data<<"  ";
            preorder(t->left);
            preorder(t->right);
        }
    }

    bool search(int key){
        Node *t = root;
        while(t){
            if(t->data == key){
                cout<<"key found:"<<key<<endl;
                return true;
            }
            else if(t->data < key){
                t = t->right;
            }
            else{
                t = t->left;
            }
        }

        cout<<"key not found:"<<key<<endl;
        return false;
    }

    void levelorder_traversal(){
        queue<Node*>q;
        Node *t = root;
        q.push(t);
        while(!q.empty()){
            t = q.front();
            q.pop();
            cout<<t->data<<"  ";
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        cout<<endl;
    }

    int height(Node* t){
        if(t){
            return 1+max(height(t->left), height(t->right));
        }
        return 0;
    }

    Node* inorderpre(Node *t){
        while(t && t->right){
            t = t->right;
        }
        return t;
    }

    Node* inordersucc(Node *t){
        while(t && t->left){
            t = t->left;
        }
        return t;
    }

    // In this delete method we replace the key with inorder successor or inorder predecessor based on which side has more height
    Node* delete_node(Node *p , int key){
        if(p == NULL){
            return NULL;
        }
        if(p->left == NULL && p->right == NULL){
            if(p->data == key){
                if(p == root){
                    root = NULL;
                }
                delete p;
            }
            return NULL;
        }

        Node *q = NULL;
           if(key>p->data){
                p->right = delete_node(p->right , key);
           }else if(key<p->data){
                p->left = delete_node(p->left , key);
           }else{
                if(height(p->left) > height(p->right)){
                    q = inorderpre(p->left);
                    p->data = q->data;
                    p->left = delete_node(p->left , q->data);
                }else{
                    q = inordersucc(p->right);
                    p->data = q->data;
                    p->right = delete_node(p->right , q->data);
                }
           }

           return p;
    }

    void insert_from_preorder(vector<int>&pre){
        stack<Node *>s;
        Node *p;
        int i=0;
        Node *t = new Node;
        t->data = pre[i++];
        t->left = t->right = NULL;
        root = t;
        while(i<pre.size()){
            if(pre[i]<t->data){
                p = new Node;
                p->data = pre[i++];
                p->left = p->right = NULL;
                t->left = p;
                s.push(t);
                t=p;
            }else if(pre[i]>t->data){
                if(!s.empty()){
                    if(pre[i]<s.top()->data){
                        p = new Node;
                        p->data = pre[i++];
                        p->left = p->right = NULL;
                        t->right = p;

                    }else{
                        t= s.top();
                        s.pop();
                    }
                }else{
                    p = new Node;
                    p->data = pre[i++];
                    p->left = p->right = NULL;
                    t->right = p;
                    t = p;
                }
            }
        }
    }

};


int main()
{
    vector<int> a = {5, 3, 7 , 1 , 3 , 6 , 21, 2 , 15 , 12 , 4};
    BST b1;
    b1.insert_list(a);

    b1.levelorder_traversal();
    cout<<endl;

    b1.inorder(b1.root);

    cout<<endl;

    //b1.search(5);
    //b1.search(7);
    //b1.search(11);

    b1.delete_node(b1.root , 7);
    cout<<endl;
    b1.inorder(b1.root);
    cout<<endl;
    b1.delete_node(b1.root , 1);
    cout<<endl;
    b1.inorder(b1.root);

    cout<<endl;

    b1.levelorder_traversal();


    //perfect

    BST b2;
    vector<int>vec = {30,20,10,15,25,40,50,45};
    b2.insert_from_preorder(vec);
    cout<<endl;
    b2.preorder(b2.root);
    cout<<endl;
    b2.inorder(b2.root);
    return 0;

}