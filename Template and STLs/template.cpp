#include<iostream>
using namespace std;

template <class T=char>
class vec{
    T *arr;
    int size;
    public:
        vec(int m){
            this->size =m;
            arr = new T[size];
        }
        void set_data(){
            for(int i = 0 ; i<size ; i++){
                cout<<"input data for "<<i<<"th element: ";
                cin>>arr[i];
            }
        }
        T add_data(){
            T ans = 0 ;
            for(int i=0 ; i<size;i++){
                ans += this->arr[i];
            }
            return ans;
        }
};

template <class T>
class some{
    T a;
};

int main(){
    vec <float> a(3);
    a.set_data();
    float ans = a.add_data();
    cout<<"addtion of all the elements is: "<<ans;
    return 0;
}