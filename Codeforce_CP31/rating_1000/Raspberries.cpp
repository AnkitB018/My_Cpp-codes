#include <iostream>
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
        int best = INT_MAX;
        int even = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            int curr = 0;
            cin >> temp;
            if(temp%2 == 0){
                even++;
            }
            int rem = temp % k;
            if (rem == 0)
            {
                curr = 0;
            }
            else
            {
                curr = k - rem;
            }
            if (curr < best)
            {
                best = curr;
            }
        }
        if(k == 4){
            even = min(2, even);
            best = min(2-even, best);
        }

        cout << best << endl;
    }

    return 0;
}