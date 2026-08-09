#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<vector<long long>>vec;
        long long minG = INT_MAX;
        for(int i=0 ; i<n ; i++){
            long long m;
            cin>>m;
            vector<long long>temp(m);
            for(int j=0 ; j<m ; j++){
                cin>>temp[j];
            }
            sort(temp.begin() , temp.end());
            if(temp[0] < minG){
                minG = temp[0];
            }
            vec.push_back(temp);
        }

        long long min=INT_MAX;
        long long sum=0;
        for(int i=0 ; i<n ; i++){
            sum += vec[i][1];
            if(vec[i][1] < min){
                min = vec[i][1];
            }
        }

        sum -= min;
        sum+= minG;
        
        cout<<sum<<endl;



    }



    return 0;
}