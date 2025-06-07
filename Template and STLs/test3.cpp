#include<iostream>
using namespace std;

typedef struct player{

    string name;
    int runs;
    int wickets;
    int catches;
    int matches;

}player;



int main(){
    
    player *ankit;
    ankit->name = "Ankit";
    ankit->matches = 100;
    ankit->runs = 782839;
    ankit->wickets = 34234;

    cout<<(*ankit).runs<<endl;


    enum meal {breakfast , lunch , dinner};
    meal k1 = lunch;

    cout<<k1<<endl;


    int a[] = {1,2,3,4,5,6};
    int *ptr = &a[0];
    int i=0;
    while(i<10){
        cout<<ptr[i]<<" ";
        i++;
    }
    

}