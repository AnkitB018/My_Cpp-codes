#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n, x, m;
        scanf("%d %d %d", &n, &x, &m);
        pair<int, int> range = {x, x};

        for (int i = 0; i < m; i++)
        {
            int l;
            int r;
            scanf("%d %d", &l, &r);

            if (l <= range.second && r >= range.first)
            {
                range.first = min(range.first, l);
                range.second = max(range.second, r);
            }
        }

        cout << range.second - range.first + 1 << endl;
    }

    return 0;
}