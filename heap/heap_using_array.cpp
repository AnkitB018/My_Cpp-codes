#include<iostream>
#include<vector>
using namespace std;

class max_heap{
    vector<int>heap;
    public:
        max_heap(){
            heap.push_back(-1); // 0th index not used for ease in calculation so inserted -1
        }

        void insert(int key){
            heap.push_back(key);
            int temp = key;
            int i = heap.size()-1;
            while(i>1 && temp > heap[i/2]){
                heap[i] = heap[i/2]; //replacing with parent
                i = i/2;
            }
            heap[i] = temp;
            cout<<"Inserted successfully!"<<endl;
        }

        void create(vector<int>a){
            for(int i=0 ; i<a.size() ; i++){
                insert(a[i]);
            }
            cout<<"List created successfully!"<<endl;
        }

        void disp_heap_array(){
            for(int i=1 ; i<heap.size() ; i++){
                cout<<heap[i]<<"  ";
            }
            cout<<endl;
        }

        
};


int main(){
    max_heap h1;
    vector<int> a = {1,4,2,7,40,18,9,10,12,34,23,21};
    h1.create(a);
    h1.disp_heap_array();

return 0;
}