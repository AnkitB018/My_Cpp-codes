#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *right;
        int height;
};

class AVL{
    public:
        Node *root;
        AVL(){
            root = NULL;
        }

        int Set_height(Node* p){
            int h1 = p && p->left?p->left->height:0;
            int h2 = p && p->right?p->right->height:0;

            return h1>h2?h1+1:h2+1;
        }

        int Balance_factor(Node *p){
            int h1 = p && p->left?p->left->height:0;
            int h2 = p && p->right?p->right->height:0;

            return h1-h2;
        }

        Node * LL_rotation(Node *p){
            Node *pl = p->left;
            Node *plr = pl->right;

            pl->right = p;
            p->left = plr;

            p->height = Set_height(p);
            pl->height = Set_height(pl);
            if(root == p){
                root = pl;
            }
            return pl;
        }

        Node * LR_rotation(Node *p){
            Node *pl = p->left;
            Node *plr = pl->right;

            pl->right = plr->left;
            p->left = plr->right;

            plr->left = pl;
            plr->right = p;

            plr->height = Set_height(plr);
            p->height = Set_height(p);
            pl->height = Set_height(pl);

            if(root == p){
                root = plr;
            }

            return plr;

        }

        Node * RR_rotation(Node *p){
            Node *pr = p->right;
            Node *prl = pr->left;

            pr->left = p;
            p->right = prl;

            p->height = Set_height(p);
            pr->height = Set_height(pr);

            if(root == p){
                root = pr;
            }

            return pr;
        }

        Node * RL_rotation(Node *p){
            Node *pr = p->right;
            Node *prl = pr->left;

            p->right = prl->left;
            pr->left = prl->right;

            prl->left = p;
            prl->right = pr;

            prl->height = Set_height(prl);
            p->height = Set_height(p);
            pr->height = Set_height(pr);

            if(root == p){
                root = prl;
            }
            return prl;

        }

        Node* insert(Node *p, int key){
            Node *t = NULL;
            if(root == NULL){
                t = new Node;
                t->val = key;
                t->height = 0;
                t->left = t->right = NULL;
                root=t;
                return t;
            }
            if(p==NULL){
                t = new Node;
                t->val = key;
                t->height = 1;
                t->left = t->right = NULL;
                return t;
            }
            if(key<p->val){
                p->left = insert(p->left , key);
            }else if(key>p->val){
                p->right = insert(p->right , key);
            }

            p->height = Set_height(p);
            if(Balance_factor(p)==2 && Balance_factor(p->left) == 1){
                return LL_rotation(p);
            }else if(Balance_factor(p)==2 && Balance_factor(p->left) == -1){
                return LR_rotation(p);
            }else if(Balance_factor(p)==-2 && Balance_factor(p->left) == -1){
                return RR_rotation(p);
            }else if(Balance_factor(p)==-2 && Balance_factor(p->left) == 1){
                return RL_rotation(p);
            }

            return p;

        }

        void inorder(Node *p){
            if(p){
                inorder(p->left);
                cout<<p->val<<"  ";
                inorder(p->right);
            }

        }

        void preorder(Node *p){
            if(p){
                cout<<p->val<<"  ";
                preorder(p->left);
                preorder(p->right);
            }

        }

        void levelorder(){
            Node *t = root;
            queue<Node *>q;
            q.push(t);
            while(!q.empty()){
                t = q.front();
                q.pop();
                cout<<t->val<<"  ";
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            
            cout<<endl;
        }

        Node *InPre(Node *p) {
        while (p && p->right != nullptr){
            p = p->right;
        }
        return p;
        }
 
        Node *InSucc(Node *p) {
            while (p && p->left != nullptr){
            p = p->left;
            }   
        return p;
        }
        
        int height_cal(Node *p){
            if(p){
                return max(height_cal(p->left), height_cal(p->right))+1;
            }
            return 0;
        }

        Node *delete_node(Node* p, int key){
            Node * q;
            if(p == NULL){
                return NULL;
            }
            if(p->left == NULL && p->right == NULL && p->val == key){
                if(root == p){
                    root = NULL;
                }
                delete p;
                return NULL;
            }

            if(key<p->val){
                p->left = delete_node(p->left, key);
            }else if(key>p->val){
                p->right = delete_node(p->right, key);
            }else{
                if(height_cal(p->left)>height_cal(p->right)){
                    q = InPre(p->left);
                    p->val = q->val;
                    p->left = delete_node(p->left, q->val);
                }else{
                    q = InSucc(p->right);
                    p->val = q->val;
                    p->right = delete_node(p->right, q->val);
                }   
            }

            p->height = Set_height(p);

            if (Balance_factor(p) == 2 && Balance_factor(p->left) == 1) {  // L1 Rotation
                return LL_rotation(p);
            } else if (Balance_factor(p) == 2 && Balance_factor(p->left) == -1){  // L-1 Rotation
                return LR_rotation(p);
            } else if (Balance_factor(p) == -2 && Balance_factor(p->right) == -1){  // R-1 Rotation
                return RR_rotation(p);
            } else if (Balance_factor(p) == -2 && Balance_factor(p->right) == 1){  // R1 Rotation
                return RL_rotation(p);
            } else if (Balance_factor(p) == 2 && Balance_factor(p->left) == 0){  // L0 Rotation
                return LL_rotation(p);
            } else if (Balance_factor(p) == -2 && Balance_factor(p->right) == 0){  // R0 Rotation
                return RR_rotation(p);
            }


            return p;
        }

        
};


int main(){
    AVL a;
    a.insert(a.root , 10);
    a.insert(a.root, 5);
    a.insert(a.root, 2);
    a.insert(a.root,13);
    a.insert(a.root,4);
    a.insert(a.root,7);
    a.insert(a.root,17);
    a.insert(a.root,20);
    a.insert(a.root,11);
    a.insert(a.root,3);
    a.insert(a.root,8);

    a.delete_node(a.root, 17);
    a.delete_node(a.root, 5);

    a.levelorder();
    a.inorder(a.root);

    return 0;

}