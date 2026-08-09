#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> vec(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp;
                cin >> temp;
                vec[i][j] = temp;
            }
        }

        
        int minimum = INT_MAX;
        int sum = 0;
        int neg_ele = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vec[i][j] < 0){
                    neg_ele++;
                }
                minimum = min(abs(vec[i][j]), minimum);
                sum += abs(vec[i][j]);
            }
        }

        if(neg_ele % 2 == 0){
            cout<<sum<<endl;
        }else{
            int ans = sum - 2*minimum;
            cout<<ans<<endl;
        }

                    
    }

    return 0;
}