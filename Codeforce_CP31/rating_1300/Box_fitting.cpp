#include <iostream>
#include <vector>

using namespace std;

int log(int n){
    for(int i=1 ; i<=31 ; i++){
        long long val = 1<<i;
        if(val > n){
            return i-1;
        }
    }

    return 32;
}

int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        int n,w;
        scanf("%d %d", &n, &w);
        vector<int>bits(30, 0);
        for(int i=0 ; i<n ; i++){
            int temp;
            scanf("%d", &temp);
            int bit = log(temp);
            bits[bit]++;
        }

        int space = w;
        int level = 1;
        int placed = 0;


        while(placed != n){
            int large = log(space);
            bool found = false;
            for( ; large>=0 ; large--){
                if(bits[large]){
                    found = true;
                    break;
                }
            }
            if(!found){
                space = w;
                level++;
                continue;
            }

            space -= (1<<large);
            placed++;
            bits[large]--;
            if(space <= 0){
                space = w;
                if(placed !=n ){
                    level++;
                }
            }

        }


        printf("%d \n", level);

    }

    return 0;
}