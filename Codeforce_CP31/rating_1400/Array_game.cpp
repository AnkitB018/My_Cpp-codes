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
        int n, k;
        cin >> n >> k;

        vector<long long> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        if (k >= 3)
        {
            cout << 0 << endl;
            continue;
        }

        sort(vec.begin(), vec.end());
        if (k == 1)
        {
            long long best = vec[0];

            for (int i = 0; i < n - 1; i++)
            {
                if (vec[i + 1] - vec[i] < best)
                {
                    best = vec[i + 1] - vec[i];
                }
            }

            cout << best << endl;
            continue;
        }

        long long best = vec[0];
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long diff = vec[j] - vec[i];
                if (diff < best)
                {
                    best = diff;
                }
                int l = 0;
                int r = n - 1;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (vec[mid] <= diff)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }

                long long temp = LLONG_MAX;

                if (l < n)
                    temp = min(temp, vec[l] - diff);

                if (l > 0)
                    temp = min(temp, diff - vec[l - 1]);

                best = min(best, temp);
                if (temp < best)
                {
                    best = temp;
                }
            }
        }

        cout << best << endl;
    }

    return 0;
}