#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
};

class hashtable{
    public:
        Node arr[10];

        hashtable(){
            for(int i=0 ; i<10 ; i++){
                arr[i].next = NULL;
            }
        }

        void insert(int key){
            Node *temp;
            Node *add = new Node;
            add->val = key;
            add->next = NULL;
            int slot = key %10;
            if(arr[slot].next == NULL){
                arr[slot].next = add;
            }else{
                temp = arr[slot].next;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = add;
            }
            cout<<"Value successfully inserted: "<<key<<endl;
        }

        void show(){
            Node *temp;
            for(int i = 0; i<10 ; i++){
                temp = arr[i].next;
                while(temp){
                    cout<<temp->val<<" -> ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

        bool search(int key){
            int slot = key%10;
            Node *temp;
            temp = arr[slot].next;
            if(temp->val == key){
                return true;
            }else{
                while(temp){
                    if(temp->val == key){
                        return true;
                    }
                    temp = temp->next;
                }
            }

            return false;
        }

        void Delete_key(int key){
            int slot = key%10;
            if(arr[slot].next == NULL){
                cout<<"Key not found! "<<endl;
                return;
            }
            if(arr[slot].next->val == key){
                arr[slot].next = NULL;
                cout<<"Successfully deleted: "<<key<<endl;
                return;
            }
            Node *prev = arr[slot].next;
            Node *curr = prev->next;
            while(curr){
                if(curr->val == key){
                    prev->next = curr->next;
                    delete curr;
                    cout<<"Successfully deleted: "<<key<<endl;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }

            cout<<"key not found!"<<endl;
        }
        
};

int main(){
    hashtable h;
    h.insert(5);
    h.insert(3);
    h.insert(15);
    h.insert(20);
    h.insert(7);
    h.insert(12);
    h.insert(17);
    h.insert(22);
    h.insert(32);
    h.insert(9);
    h.insert(1);
    h.insert(14);
    h.insert(16);
    h.insert(8);

    h.insert(88);

    h.show();

    h.Delete_key(88);
    h.show();
return 0;
}