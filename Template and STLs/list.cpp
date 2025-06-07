#include<iostream>
#include<list>
#include<string>
using namespace std;

template <class T>
void disp(list<T> l){
    typename list <T> :: iterator it = l.begin(); //as it is a type we use typename if it was a value or something else we did not have to write typename
    for( ; it != l.end() ; it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template <class T1, class T2>
void disp2(list<T1,T2> lst){
    typename list<T1,T2>::iterator itr = lst.begin();
    for(itr ; itr!=lst.end();itr++){
        cout<<(*itr).first<<" "<<itr->second<<endl;
    }
}

int main(){
    list<int> l1 , l2;
    l1.push_back(5);
    l1.push_front(2);
    l1.push_back(1);
    l1.push_front(9);
    cout<<"contents of list1: ";
    disp(l1);

    l2.push_back(0);
    l2.push_front(4);
    l2.push_back(6);
    l2.push_front(8);
    cout<<"contents of list2: ";
    disp(l2);
    l1.swap(l2);
    cout<<"After swapping----> "<<endl;
    cout<<"contents of list1: ";
    disp(l1);
    cout<<"contents of list2: ";
    disp(l2);

    cout<<"applying merging after sorting: ";
    l1.sort();
    l2.sort();
    l1.merge(l2);
    disp(l1);
    cout<<"reversing the list: ";
    l1.reverse();
    disp(l1);



    //new type of list
    list<pair<char , int>> mylist;
    mylist.emplace(mylist.begin(), 'x' , 100);
    mylist.emplace(mylist.begin(), 'y' , 200);
    mylist.emplace(mylist.begin(), 'a' , 300);
    mylist.emplace(mylist.end(), 'b' , 400);

    disp2(mylist);
return 0;
}