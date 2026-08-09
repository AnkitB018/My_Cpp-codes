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
        vector<int> rem(m);
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;

            int r = temp % m;
            rem[r]++;
        }

        int size = 0;
        for (int i = 0; i <= m / 2; i++)
        {
            if (i == 0)
            {
                if(rem[i]>0){
                    size++;
                }
                continue;
            }
            if (m % 2 == 0 && i == (m / 2))
            {
                if(rem[i] > 0){
                    size++;
                }
                continue;
            }
            int a = rem[i];
            int b = rem[m - i];

            if (a == 0 || b == 0)
            {
                size += max(a, b);
            }
            else
            {
                size += (1 + max(abs(a - b)-1, 0));
            }
        }

        cout << size << endl;
    }

    return 0;
}