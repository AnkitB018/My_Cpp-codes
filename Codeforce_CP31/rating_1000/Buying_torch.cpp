#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        long long trades = 0;

        long long total = k * y + k;

        trades += (total+x-3)/(x-1);

        trades += k;
        cout << trades << endl;
    }

    return 0;
}