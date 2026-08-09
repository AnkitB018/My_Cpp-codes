#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isprime(int n)
{
    if (n == 2 || n == 3)
    {
        return true;
    }

    if (n % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i * i <= n; i+=2)
    {
        if (n % i == 0)
        {
            return false;
        }
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
        scanf("%d", &n);

        vector<int> primes;

        int i = 2;
        if(isprime(n)){
            cout<<"NO"<<endl;
            continue;
        }
        while (true)
        {
            if (n % i == 0 && isprime(i))
            {
                primes.push_back(i);
                n = n / i;
                if(isprime(n)){
                    primes.push_back(n);
                    break;
                }
                continue;
            }
            i++;
        }

        sort(primes.begin(), primes.end());

        vector<int> ans(3, -1);
        int idx = 0;
        int curr = 1;
        for (int i = 0; i < primes.size(); i++)
        {
            if (idx == 2)
            {
                curr *= primes[i];
                if (i == primes.size() - 1)
                {
                    if (ans[idx - 1] == curr || ans[idx - 2] == curr)
                    {
                        continue;
                    }
                    ans[idx] = curr;
                    idx++;
                }
                continue;
            }
            curr *= primes[i];
            if (idx == 1 && ans[idx - 1] == curr)
            {
                continue;
            }

            ans[idx] = curr;
            curr = 1;
            idx++;
        }

        if (idx != 3)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << ans[i] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}