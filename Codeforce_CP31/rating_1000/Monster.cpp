#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int , int>>vec;
        for(int i=0 ; i<n ; i++){
            int temp;
            cin>>temp;
            temp = temp%k;
            if(temp == 0) temp = k;
            vec.push_back({temp, i+1});
        }
        auto cmp = [](auto &a, auto&b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first>b.first;
        };

        sort(vec.begin(), vec.end(), cmp);
        for(int i=0 ; i<n ; i++){
            cout<<vec[i].second<<" ";
        }

        cout << endl;
    }

    return 0;
}