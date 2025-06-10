#include<iostream>
#include<vector>
using namespace std;

class max_heap{
    vector<int>heap;
    public:
        max_heap(){
            heap.push_back(-1); // 0th index not used for ease in calculation so inserted -1
        }

        void insert(int key){ //insert one at a time
            heap.push_back(key);
            int temp = key;
            int i = heap.size()-1;
            while(i>1 && temp > heap[i/2]){
                heap[i] = heap[i/2]; //replacing with parent
                i = i/2;
            }
            heap[i] = temp;
            //cout<<"Inserted successfully!"<<endl;
        }

        void create(vector<int>a){ // this will clear out existing heap and build a new one
            heap.clear();
            for(int i=0 ; i<a.size() ; i++){
                insert(a[i]);
            }
            //cout<<"Heap created successfully!"<<endl;
        }

        void disp_heap_array(){
            for(int i=1 ; i<heap.size() ; i++){
                cout<<heap[i]<<"  ";
            }
            cout<<endl;
        }

        int Delete_max(){
            if(heap.size() == 1){
                cout<<"heap is empty!"<<endl;
            }
            int n = heap.size()-1;
            int temp = heap[1];
            heap[1] =  heap[n];
            heap[n] = temp;
            int i,j;
            i=1;
            j=i*2;
            while(j<n-1){
                if(heap[j]<heap[j+1]){
                    j=j+1;
                }
                if(heap[j]>heap[i]){
                    temp = heap[i];
                    heap[i] = heap[j];
                    heap[j] = temp;
                    i=j;
                    j=2*j;
                }else{
                    break;
                }
            }
            if(j == n-1){
                if(heap[i]<heap[j]){
                    temp = heap[i];
                    heap[i] = heap[j];
                    heap[j] = temp;
                }
            }
            temp = heap[n];
            heap.erase(heap.begin()+n);
            return temp;
        }

        void heap_sort(vector<int>&h){
            create(h);
            h.clear();
            while(heap.size() > 1){
                int temp = Delete_max();
                h.push_back(temp);
            }
        }

        void Delete_heap(){ //to delete the entire heap
            heap.clear();
            cout<<"Entire heap cleared! "<<endl;
        }
        
};


int main(){
    max_heap h1;
    vector<int> a = {1,4,2,7,40,18,9,10,12,34,23,21};
    h1.create(a);
    h1.disp_heap_array();
    h1.Delete_max();
    h1.disp_heap_array();
    max_heap h2;
    h2.heap_sort(a);
    for(int i=0 ; i<a.size(); i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;


    return 0;
}