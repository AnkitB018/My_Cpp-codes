#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
};

class binary_tree{
    public:
        Node* root;
        binary_tree(){
            root = NULL;
        }

        void create(){
            queue<Node*>q;
            cout<<"Enter the value of root-> ";
            int val;
            cin>>val;
            root = new Node;
            root->data = val;
            root->left=NULL;
            root->right=NULL;    
            q.push(root);
            while(!q.empty()){
                Node *temp = new Node;
                temp = q.front();
                q.pop();
                cout<<"Enter left child, if null enter -999-> ";
                cin>>val;
                if(val != -999){
                    Node* create = new Node;
                    create->data = val;
                    create->left = NULL;
                    create->right = NULL;
                    temp->left = create;
                    q.push(create);
                }
                cout<<"Enter right child, if null enter -999-> ";
                cin>>val;
                if(val != -999){
                    Node* create = new Node;
                    create->data = val;
                    create->left = NULL;
                    create->right = NULL;
                    temp->right = create;
                    q.push(create);
                }

            }
        }

        void preorder(Node* temp){
            if(!temp){
                return;
            }
            cout<<temp->data<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }

        void inorder(Node * temp);
        void postorder(Node *temp);
        void levelorder();
        int count_height(Node* temp);
        int count_nodes(Node* temp);
        int count_leafs(Node* temp);

};

void binary_tree :: inorder(Node * temp){
    if(temp){
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

void binary_tree :: postorder(Node* temp){
    if(temp){
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

void binary_tree :: levelorder(){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int binary_tree :: count_height(Node* temp){
    if(!temp){
        return 0;
    }
    return 1+max(count_height(temp->left), count_height(temp->right));
}

int binary_tree :: count_nodes(Node* temp){
    if(temp){
        return(1+count_nodes(temp->left)+count_nodes(temp->right));
    }else{
        return 0;
    }
}

int binary_tree :: count_leafs(Node* temp){
    if(temp){
        int x = count_leafs(temp->left);
        int y = count_leafs(temp->right);
        if(!temp->left && !temp->right){
            return 1+x+y;
        }else{
            return x+y;
        }
    }
    return 0;
}

int main(){
    binary_tree tree;
    tree.create();
    cout<<"Preorder: "<<"\n";
    tree.preorder(tree.root);
    cout<<"postorder: "<<"\n";
    tree.postorder(tree.root);
    cout<<"height: "<<tree.count_height(tree.root)<<"\n";
    cout<<"number of nodes: "<< tree.count_nodes(tree.root)<<"\n";
    cout<<"number of leaf nodes: "<< tree.count_leafs(tree.root)<<"\n";
}