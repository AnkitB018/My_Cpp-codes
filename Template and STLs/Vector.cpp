#include<iostream>
#include<Vector>
using namespace std;

template <class T>
void disp(vector<T> v){
    for(int i=0 ; i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

int main(){
    vector <int> v1;
    int size;
    int element;
    cout<<"Enter size of vector: "<<endl;
    cin>>size;
    for(int i= 0 ; i<size ; i++){
        cout<<"Enter "<<i<<"th element of vector: "<<endl;
        cin>>element;
        v1.push_back(element);
    }
    v1.push_back(999);
    disp(v1);
    //v1.pop_back();
    //disp(v1);

    vector<int>:: iterator itr = v1.begin();
    v1.insert(itr+3 , 3 , 6);
    v1.insert(v1.begin() , 0);
    disp(v1);
    //vector <char> v2;
    //v2.push_back('c');
    //disp(v2);
    //vector<char> v3(v2);
return 0;
}
