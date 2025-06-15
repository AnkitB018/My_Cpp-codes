#include<iostream>
using namespace std;


class hashtable{
    int arr[10];
    public:
        hashtable(){
            for(int i=0 ; i<10 ; i++){  
                arr[i] = -1;
            }
        }

        void insert(int key){
            int slot;
            for(int i=0 ; i<100 ; i++){
                slot = ((key%10) + i*(7-(key%7)))%10;
                if(arr[slot] == -1){
                    arr[slot] = key;
                    cout<<"Key inserted: "<<key<<endl;
                    return;
                }
            }
            cout<<"No free space found insertion failed!"<<endl;
        }

        void show(){
            for(int i=0 ; i<10 ; i++){
                if(arr[i] == -1){
                    cout<<endl;
                    continue;
                }
                cout<<arr[i]<<endl;
            }
        }

};

int main(){
    hashtable h;
    h.insert(5);
    h.insert(15);
    h.insert(17);

    
    h.show();
    
    return 0;
}