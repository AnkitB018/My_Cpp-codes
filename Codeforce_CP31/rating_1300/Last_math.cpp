#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        int a, b;
        if (n % 2 == 0)
        {
            a = n / 2;
            b = n / 2;
        }
        else
        {
            vector<int> primes;
            for (int i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    primes.push_back(i);
                    primes.push_back(n / i);
                }
            }

            if (primes.size() == 0)
            {
                a = 1;
            }
            else
            {
                sort(primes.rbegin(), primes.rend());
                a = primes[0];
            }
            b = n - a;
        }

        printf("%d %d \n", a, b);
    }

    return 0;
}