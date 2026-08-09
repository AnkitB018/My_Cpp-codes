#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        vector<vector<char>>vec(n, vector<char>(n, 0));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cin>>vec[i][j];
            }
        }

        pair<int, int> tl, tr, bl, br;
        tl={0,0};
        tr = {0,n-1};
        bl = {n-1,0};
        br = {n-1, n-1};

        pair<int, int> p_tl, p_tr, p_bl, p_br;
        int ans = 0;
        n-=2;
        while(n>=0){
            p_tl = tl;
            p_tr = tr;
            p_bl = bl;
            p_br = br;
            for(int i=0 ; i<=n ; i++){
                int ones = 0;
                int zeros = 0;
                if(vec[tl.first][tl.second] == '0'){
                    zeros++;
                }else{
                    ones++;
                }

                if(vec[tr.first][tr.second] == '0'){
                    zeros++;
                }else{
                    ones++;
                }

                if(vec[bl.first][bl.second] == '0'){
                    zeros++;
                }else{
                    ones++;
                }

                if(vec[br.first][br.second] == '0'){
                    zeros++;
                }else{
                    ones++;
                }

                ans+= 4-max(zeros, ones);

                tl.second +=1;
                tr.first += 1;
                bl.first -=1;
                br.second -=1;
            }

            tl = {p_tl.first+1, p_tl.second+1};
            tr = {p_tr.first+1, p_tr.second-1};
            bl = {p_bl.first-1, p_bl.second+1};
            br = {p_br.first-1, p_br.second-1};


            n-=2;
        }

        cout<<ans<<endl;

    }

}