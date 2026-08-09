#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canreach(vector<pair<int, int>> &vec, int k)
{
    int l = 0;
    int r = 0;

    int n = vec.size();
    for (int i = 0; i < n; i++){
        int lower_range = l-k;
        int higher_range = r+k;

        if(lower_range > vec[i].second){
            return false;
        }else if(higher_range < vec[i].first){
            return false;
        }

        l = max(lower_range, vec[i].first);
        r = min(higher_range, vec[i].second);

    }

    return true;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> vec;

        int high = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;

            vec.push_back({l, r});

            if(r > high){
                high = r;
            }
        }

        int l,r;
        l = 0;
        r = high;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(canreach(vec, mid)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        cout<<l<<endl;

    }
}