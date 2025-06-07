#include<iostream>
#include<map>
#include<string>
using namespace std;

template <class T1 , class T2>
void disp_map(map <T1,T2> mp){
    typename map<T1 , T2>::iterator itr = mp.begin();
    for(itr ; itr != mp.end() ;itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}


int main(){
    map<string , int>my_map;
    my_map["ankit"] = 98;
    my_map.insert({{"Rohan" , 99} , {"alab" , 45} , {"sik_kabab" , 67}});
    cout<<"my map before deletion and new additions: "<<endl;
    disp_map(my_map);
    my_map.clear();
    my_map["new_ankit"] = 98;
    my_map.insert({{"new_rohan" , 99} , {"nem_alab" , 45} , {"new_sik_kabab" , 67}});    
    cout<<"My map after the deletion and new addition:"<<endl;
    disp_map(my_map);
    cout<<"let's delete the record new_ankit"<<endl;
    my_map.erase("new_ankit");
    disp_map(my_map);
    return 0;

}
