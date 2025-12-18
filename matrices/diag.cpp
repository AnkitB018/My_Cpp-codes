#include<iostream>
#include<vector>

using namespace std;

class diagonal{
    private: 
        vector<int> mat;
        int n;
    public:
        diagonal(int n){
            this->n = n;
        }
        void set(){
            int ele;
            for(int i=0 ; i<n ; i++){
                cout<<"Enter diagonal element No. "<<i<<endl;
                cin>>ele;
                mat.push_back(ele);
            }
        }
        void disp();
};

void diagonal :: disp(){
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<n ; j++){
            if(i == j){
                cout<<mat[i]<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    diagonal d(3);
    d.set();
    d.disp();

    return 0;
}