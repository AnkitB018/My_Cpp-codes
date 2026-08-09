#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char, int>freq;
        int dis = 0;
        for(int i=0 ; i<n ; i++){
            if(freq[s[i]] == 0){
                dis++;
            }
            freq[s[i]]++;
        }

        int dis2 = 0;
        int best = dis;
        vector<int>taken(26,0);
        for(int i=0; i <n ; i++){
            int temp = s[i] - 'a';
            freq[s[i]]--;
            if(freq[s[i]] == 0){
                dis--;
            }
            if(taken[temp] == 0){
                taken[temp] = 1;
                dis2++;
            }

            best = max(best, dis+dis2);

        }

        cout<<best<<endl;


    }


    return 0;
}