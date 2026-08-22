#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve(){
    long long n,m;
    cin>>n>>m;

    long long temp = n;
    long long extra_fives = 0;
    while(temp % 5 == 0){
        temp = temp/5;
        extra_fives++;
    }

    temp = n;
    while(temp % 2 == 0){
        temp = temp/2;
        extra_fives--;
    }

    long long done = 1;

    while(done < m){
        int target;
        if(extra_fives > 0){
            target = 2;
            extra_fives--;
        }else if(extra_fives < 0){
            target = 5;
            extra_fives++;
        }else{
            target = 10;
        }

        if(done * target > m){
            if(done * 2 > m){
                break;
            }
            int i = 2;
            while(done *(i+1) <= m){
                i++;
            }
            target = i;
        }

        n = n*target;
        done *= target;

    }

    cout<<n<<endl;

}

int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }

    return 0;
}