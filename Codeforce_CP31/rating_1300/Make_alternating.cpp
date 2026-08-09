#include <iostream>
#include <vector>

using namespace std;

int MOD = 998244353;

long long fact(long long n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = (res * i) % MOD;
    }

    return res;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        int n = s.size();
        long long ans = 1;
        char curr = s[0];
        long long cons = 1;
        long long oprs = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == curr)
            {
                cons = (cons + 1) % MOD;
                continue;
            }

            if (cons == 1)
            {
                curr = s[i];
                continue;
            }
            oprs += cons - 1;
            ans = (ans * cons) % MOD;
            cons = 1;
            curr = s[i];
        }
        if (cons != 1)
        {
            oprs += cons - 1;
            ans = (ans * cons) % MOD;
        }

        ans = (ans*fact(oprs)) % MOD;

        
        cout << oprs << " ";
        cout << ans << endl;
    }

    return 0;
}