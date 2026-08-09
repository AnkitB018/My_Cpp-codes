#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        unordered_map<int, int>cons1;
        unordered_map<int, int>cons2;
        int on;
        int score;
        for(int i=0 ; i<n ; i++ ){
            int temp;
            cin>>temp;
            if(i == 0){
                on = temp;
                score = 1;
                if(cons1[on] < score){
                    cons1[on] = score;
                }
                continue;
            }
            if(temp == on){
                score++;
                if(cons1[on] < score){
                    cons1[on] = score;
                }
                continue;
            }else{
                score=1;
                on = temp;
                if(cons1[on] < score){
                    cons1[on] = score;
                }
            }
        }

        for(int i=0 ; i<n ; i++ ){
            int temp;
            cin>>temp;
            if(i == 0){
                on = temp;
                score = 1;
                if(cons2[on] < score){
                    cons2[on] = score;
                }
                continue;
            }
            if(temp == on){
                score++;
                if(cons2[on] < score){
                    cons2[on] = score;
                }
                continue;
            }else{
                score=1;
                on = temp;
                if(cons2[on] < score){
                    cons2[on] = score;
                }
            }
        }

        int best = INT_MIN;
        for(auto &freq: cons1){
            cons2[freq.first]+=freq.second;
        }

        for(auto &freq: cons2){
            if(freq.second > best){
                best = freq.second;
            }
        }

        cout<<best<<endl;

    }

    return 0;
}