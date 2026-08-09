#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long n, k, q;
        cin >> n >> k >> q;
        vector<long long> vec;
        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            vec.push_back(temp);
        }

        long long ans = 0;
        long long i, j;
        i = 0;
        j = 0;
        while (j < n)
        {
            if (vec[j] <= q)
            {
                j++;
                continue;
            }
            if (j - i >= k)
            {
                long long diff = j - i;
                long long start = (diff - k + 1);
                ans += (start * (start + 1)) / 2;
            }
            j++;
            i = j;
        }
        long long diff = j - i;
        if(diff >= k){
            long long start = (diff - k + 1);
            ans += (start * (start + 1)) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}