#include<iostream>
#include<climits>
using namespace std;

class hashtable{
    int arr[10];
    public:
        hashtable(){
            for(int i=0 ;i<10;i++){
                arr[i] = INT_MIN;
            }
        }
        void insert(int key){
            int slot = key%10;
            if(arr[slot] == INT_MIN){
                arr[slot] = key;
            }else{
                int i=slot+1;
                while(arr[i] != INT_MIN){
                    i = (i+1)%10; 
                    if(i == slot){ // In case of quadratic probing choose a iteration limit like 100 to stop and declare no free space found
                        cout<<"Hashtable is full can not isert: "<<key<<endl;
                        return;
                    }
                }
                arr[i] = key;
            }
            cout<<"Successfully inserted: "<<key<<endl;

        }

        void show(){
            for(int i=0 ; i<10 ; i++){
                if(arr[i] == INT_MIN){
                    cout<<endl;
                    continue;
                }
                cout<<arr[i]<<endl;
            }
        }

        void Delete_key(int key){
            int slot = key%10;
            int flag = slot;
            while(arr[slot]!=key){
                slot = (slot+1)%10;
                if(slot == flag){
                    cout<<"Key not found"<<endl;
                    return;
                }
            }
            arr[slot] = INT_MIN;
            cout<<"Key deleted successfully: "<<key<<endl;
        }
};

int main(){
    hashtable h;
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.insert(8);
    h.insert(9);
    h.insert(15);
    h.insert(25);
    h.insert(17);
    h.Delete_key(25);

    h.show();
return 0;
//perfect
}