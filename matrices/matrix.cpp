#include<iostream>
using namespace std;

class diagonal{
    private:
        int *a;
        int n;
    public:
        diagonal(){
            a = new int[2];
            n=2;
        }
        diagonal(int n){
            this->n = n;
            a = new int[n];
        }
        void set(int val , int i , int j){
            if(i == j){
                a[i-1] = val;
            }
        }
        void disp(int i , int j){
            if(i == j){
                cout<<a[i-1]<<endl;
            }else{
                cout<<"0"<<endl;
            }
        }
        void disp_matrix(){
            for(int i=1 ; i<=n ; i++){
                for(int j=1 ; j<=n ; j++){
                    if(i == j){
                        cout<<a[i-1]<<" ";
                    }else{
                        cout<<0<<" ";
                    }
                } 
                cout<<endl;
            }
        }
};

class lower_tri_mat{
    private:
        int *a;
        int n;
    public:
        lower_tri_mat(int n=2){
            this->n = n;
            a = new int[n];
        }

        void set(int val , int i , int j){
            if(i>=j){
                a[(i*(i-1)/2)+(j-1)] = val;
            }
        }

        void disp_mat(){
            for(int i=1 ; i<=n ; i++){
                for(int j=1 ; j<=n ; j++){  
                    if(i>=j){
                        cout<<a[(i*(i-1)/2)+(j-1)]<<" ";
                    }else{
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
        }
};
class symmetric{
    private:
        int *a;
        int  n;
    public:
        symmetric(int n=2){
            this->n = n;
            a = new int[n];
        }

        void set(int val , int i, int j){
            if(i>=j){
                a[(i*(i-1)/2)+j-1]=val;
            }else{
                int temp = i;
                i = j;
                j = temp;
                a[(i*(i-1)/2)+j-1]=val;
            }
        }
        void disp(){
            for(int i=1 ; i<=n ; i++){
                for(int j=1 ; j<=n ; j++){
                    if(i>=j){
                        cout<<a[(i*(i-1)/2)+(j-1)]<<" ";
                    }else{
                        cout<<a[(j*(j-1)/2)+(i-1)]<<" ";
                    }
                }
                cout<<endl;
            }
        }
};

int main(){
    cout<<"Diagonal matrix: "<<endl;
    diagonal d(3);
    d.set(2 ,1,1);
    d.set(3,2,2);
    d.set(5,3,3);
    d.disp_matrix();
    cout<<"Now lower triangle matrix: "<<endl;
    lower_tri_mat l(3);
    l.set(3, 1, 1);
    l.set(4, 2, 1);
    l.set(5, 2, 2);
    l.set(7, 3, 1);
    l.set(1, 3, 2);
    l.set(9, 3, 3);
    l.disp_mat();
    cout<<"Now symmetric matrix: "<<endl;
    symmetric s(3);
    s.set(4,1,1);
    s.set(8,2,1);
    s.set(6,2,2);
    s.set(2,3,1);
    s.set(9,3,2);
    s.set(7,3,3);
    s.disp();
    
    return 0;
}