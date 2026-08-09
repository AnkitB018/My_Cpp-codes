#include<iostream>
#include<vector>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n,m;
        cin>>n>>m;
        vector<int>vec(m);

        for(int i=0 ; i<m ; i++){
            cin>>vec[i];
        }

        sort(vec.begin(), vec.end());

        vector<int>gaps;
        for(int i=0 ; i<m-1 ; i++){
            gaps.push_back(vec[i+1] - vec[i]-1);
        }

        gaps.push_back((n - vec[m-1] + vec[0]) - 1);

        sort(gaps.rbegin(), gaps.rend());

        int saved = 0;
        int days = 0;
        for(auto gap:gaps){
            int curr =  gap -2*days;
            if(curr > 0){
                saved++;
                
                curr-=2;
                if(curr> 0){
                    saved+= curr;
                }

                days+=2;
            }

        }

        cout<<(n-saved)<<endl;

    }


}