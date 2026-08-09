#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long long>vec(n);
    multiset<long long>s;
    long long total = 0;
    for(int i=0 ; i<n ; i++){
        cin>>vec[i];
        total += vec[i];
        s.insert(vec[i]);
    }

    vector<int>idx;

    
    for(int i=0 ; i<n ; i++){
        long long remain = total - vec[i];
        s.erase(s.find(vec[i]));
        
        long long last = *s.rbegin();
        if(last == remain - last){
            idx.push_back(i);
        }
        s.insert(vec[i]);
    }

    cout<<idx.size()<<endl;
    for(int i=0 ; i<idx.size() ; i++){
        cout<<idx[i]+1<<" ";
    }
    
    cout<<endl;



    return 0;
}