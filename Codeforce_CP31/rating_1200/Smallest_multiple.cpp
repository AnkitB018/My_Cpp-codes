#include <iostream>
#include <string>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        long long cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' || s[i] == '2')
            {
                int j = i + 1;
                while (j < n + 1 && s[j - 1] != '1')
                {
                    if (s[j - 1] == '2')
                    {
                        j+=(i+1);
                        continue;
                    }
                    cost += i + 1;
                    s[j - 1] = '2';
                    j += (i + 1);
                }
            }
        }

        cout << cost << endl;
    }

    return 0;
}